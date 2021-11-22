#include "dispatcher.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <QSocketNotifier>
#include <unistd.h>
#include <iostream>

#include <QBitArray>

using namespace TPS;
using namespace std;

Dispatcher::Dispatcher(int fdPort, const QMap<uint8_t, Device*> &devs) :
    m_devs(devs)
{
    m_fd = fdPort;
    int flags = fcntl (m_fd, F_GETFL);
    if (flags < 0) {
        perror ("Cannot get file flags of the port FD");
        exit (1);
    }
    flags |= O_NONBLOCK;
    if (fcntl (m_fd, F_SETFL, flags) < 0) {
        perror ("Cannot set file flags of the port FD");
        exit (1);
    }
    skipInput();
    QSocketNotifier * notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read);
    connect(notifier, SIGNAL(activated(int)), this, SLOT(read()));
}

void Dispatcher::read()
{

    QByteArray res;

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(m_fd, &fds);
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 500;
    if(select(m_fd+1, &fds, NULL, NULL, &tv) > 0) {
        //finding device
        Device* cur_device;

        uint8_t addr;
        if(read_with_timeout(m_fd, &addr, sizeof(addr)) < 0) //ADDR
            return;
        if(m_devs.value(addr, NULL) != NULL) {
            cur_device = m_devs.value(addr, NULL);
//            std::cout << "Found Device ADDR:" << m_devs.value(addr)->name().toStdString() << std::endl;
            if(!m_devs.value(addr)->isDeviceWorking()) {
                std::cout << "Устройство не работает. Отбрасываем данные" << std::endl;
                skipInput(); return;
            }
        } else {
            clearInput();
            return;
        }

        uint8_t msgType;
        if(read_with_timeout(m_fd, &msgType, sizeof(msgType)) < 0)
            return;

        switch(msgType) {
            case COMMAND_WORD:
//                std::cout << "We have been commanded to do smthing" << std::endl;
            break;
            case ASK_FOR_STATUS_WORD:
                std::cout << "We have been asked for status" << std::endl;
                uint8_t val;
                if (read_with_timeout(m_fd, &val, sizeof(val)) < 0)
                        return;
                std::cout << "length of the whole message : " << (int)val;
                res.push_back(val);
                if(val == 5) {
                    std::cout << " good." << std::endl;
                } else {
                    std::cout << " ERROR LENGTH!" << std::endl;
                    skipInput();
                    return;
                }
                if (read_with_timeout(m_fd, &val, sizeof(val)) < 0)
                        return;
                res.push_back(val);
                if (read_with_timeout(m_fd, &val, sizeof(val)) < 0)
                        return;
                res.push_back(val);

                //CHECK CRC

                sendOurState(cur_device);
                skipInput(); // temporary
            break;
            default: std::cout << "SOMETHING ELSE HAVE COME:" << std::hex << (int)val << std::endl; break;
        }
    }
}

ByteWord *Dispatcher::decode(const uint8_t &val)
{
    return new ByteWord(val);
}

void Dispatcher::sendOurState(Device* dev)
{
    QByteArray msg;
    msg.append(dev->addr());
    msg.append(ANSWER_FOR_STATUS_WORD);
    PP4 * pp4dev = dynamic_cast<PP4*>(dev);
    if(pp4dev) {
        msg.append(30);
        msg.append(pp4dev->statusPP4->word());
        msg.append(pp4dev->statusUMP->word());
        msg.append(pp4dev->statusBVD31->word());
        msg.append(pp4dev->statusBVD32->word());
        msg.append(pp4dev->statusCAN->word());
        QVector<FunctionalDevice*> funcs = pp4dev->funcs();
        foreach(FunctionalDevice* fun, pp4dev->funcs()) {
            msg.append(fun->state1->word());
            msg.append(fun->state2->word());
        }
    }
    A2 * a2dev = dynamic_cast<A2*>(dev);
    if(a2dev) {
        msg.append(8);
        msg.append(a2dev->stPr->word());
        msg.append(a2dev->sost1->word());
        msg.append(a2dev->sost2->word());
    }
    msg.append((char)3);
    msg.append((char)4);

    for(int i = 0 ; i < msg.size(); i++) {
        std::cout << (int)msg[i] << " ";
    } std::cout << std::endl;

    for(int i = 0; i < msg.size(); i++) {
        char a = msg[i];
        ::write(m_fd, &a, sizeof(a));
    }
}

void Dispatcher::skipInput()
{
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(m_fd, &fds);
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 500;
    while(select(m_fd+1, &fds, NULL, NULL, &tv) > 0) {
        uint8_t val;
        ::read(m_fd, &val, sizeof(val));
    }
}

void Dispatcher::clearInput()
{
    uint8_t val;
    while(::read(m_fd, &val, sizeof(val)) != -1);
}

ssize_t Dispatcher::read_with_timeout (int fd, void *buf, size_t size)
{
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(m_fd, &fds);
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 500;
    if(select(m_fd+1, &fds, NULL, NULL, &tv) > 0) {
        return ::read(m_fd, buf, size);
    } else {
        return -1;
    }
}
