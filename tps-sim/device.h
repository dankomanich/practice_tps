#ifndef DEVICE_H
#define DEVICE_H
#include <QWidget>
#include <QByteArray>
#include <QGridLayout>
#include <QStringList>
#include <QLabel>
#include <stdint.h>
#include "tpsstruct.h"
#include <QCheckBox>
#include <QGroupBox>

using namespace TPS;
class Device : public QWidget
{
public:
    Device();
    Device(QString name, uint8_t addr) : m_name(name), m_addr(addr){}

    virtual QByteArray getState() = 0;

    uint8_t addr() const { return m_addr; }
    QString name() const { return m_name; }
    bool isDeviceWorking() const { return m_isDeviceWorking; }

protected:
    bool m_isDeviceWorking;
    QString m_name;
    uint8_t m_addr;
};

class Modules: public Device{
    Q_OBJECT
public:
    Modules();
    Modules(QString name, int addr);

    int get_number(int number){
        return  number;
    }

    QString name(){
        return m_name;
    }

    QByteArray getState() {
        return QByteArray();
    }

    int addr() const { return m_addr; }
    QString name() const { return m_name; }
    bool isModuleWorking() const { return m_isModuleWorking; }

    MODUL_Type_Info * stMd;
    MODUL_Number * num_Md;
    MODUL_Type_Info * type_Md;
    MODUL_Status_Out * sost;


    QCheckBox *res;
    QCheckBox *malfunction;
    QCheckBox *fireMODUL;
    QCheckBox *control_mode;
    QCheckBox *power1;
    QCheckBox *power2;
    QCheckBox *power3;
    QCheckBox *power4;
    QCheckBox *power5;
    QCheckBox *power6;
    QCheckBox *power7;
    QCheckBox *power8;

protected:
    bool m_isModuleWorking;
    QString m_name;
    uint8_t m_addr;
public slots:
    void updateWords() {
        stMd->malfunction                               = malfunction          ->isChecked();
        stMd->res                                = res           ->isChecked();


        sost->power1                     = power1->isChecked();
        sost->power2                     = power2->isChecked();
        sost->power3                     = power3->isChecked();
        sost->power4                     = power4->isChecked();
        sost->power5                     = power5->isChecked();
        sost->power6                     = power6->isChecked();
        sost->power7                     = power7->isChecked();
        sost->power8                     = power8->isChecked();
    }
};

class FunctionalDevice : public QWidget {
    Q_OBJECT
public:
    FunctionalDevice(QWidget * parent = NULL);

    FunctionalDevice(QString name);

    QString name () const {
        return m_name;
    }

    QCheckBox *outOff;
    QCheckBox *inReady;
    QCheckBox *inOn;
    QCheckBox *inLocal;
    QCheckBox *inFail1;
    QCheckBox *inFail2;
    QCheckBox *inNsd1;
    QCheckBox *inNsd2;

    Sost_Kan_1_PP4 *state1;
    Sost_Kan_2_PP4 *state2;
private:
    const QString m_name;
    QGridLayout * grid;


private slots:
    void updateWords() {
        state1->OutOff  = outOff    ->isChecked();
        state1->InReady = inReady   ->isChecked();
        state1->InOn    = inOn      ->isChecked();
        state1->InLocal = inLocal   ->isChecked();
        state1->InFail =  inFail1   ->isChecked();
        state2->InFail2 = inFail2   ->isChecked();
        state2->InUaa1  = inNsd1    ->isChecked();
        state2->InUaa2  = inNsd2    ->isChecked();
    }
};


class A2: public Device
{
    Q_OBJECT
public:
    A2();
    A2(QString name, int addr);
    QByteArray getState() {
        return QByteArray();
    }


    QCheckBox *Fail;
    QCheckBox *res;
    QCheckBox *OverheatPolka1;
    QCheckBox *OverheatPolka2;
    QCheckBox *OverheatPolka3;
    QCheckBox *OverheatPolka4;
    QCheckBox *OverheatPolka5;

    QCheckBox *fail1;
    QCheckBox *fail2;
    QCheckBox *fail3;
    QCheckBox *fail4;
    QCheckBox *fail5;
    QCheckBox *fail6;
    QCheckBox *fail7;
    QCheckBox *fail8;

    QCheckBox *power1;
    QCheckBox *power2;
    QCheckBox *power3;
    QCheckBox *power4;
    QCheckBox *power5;
    QCheckBox *power6;
    QCheckBox *power7;
    QCheckBox *power8;

    Status_Pribora * stPr;
    Sost_out_1 * sost1;
    Sost_out_2 * sost2;
public slots:
    void updateWords() {
        stPr->Fail                               = Fail          ->isChecked();
        stPr->res                                = res           ->isChecked();
        stPr->OverheatPolka1                     = OverheatPolka1->isChecked();
        stPr->OverheatPolka2                     = OverheatPolka2->isChecked();
        stPr->OverheatPolka3                     = OverheatPolka3->isChecked();
        stPr->OverheatPolka4                     = OverheatPolka4->isChecked();
        stPr->OverheatPolka5                     = OverheatPolka5->isChecked();
        sost1->fail1                     = fail1->isChecked();
        sost1->fail2                     = fail2->isChecked();
        sost1->fail3                     = fail3->isChecked();
        sost1->fail4                     = fail4->isChecked();
        sost1->fail5                     = fail5->isChecked();
        sost1->fail6                     = fail6->isChecked();
        sost1->fail7                     = fail7->isChecked();
        sost1->fail8                     = fail8->isChecked();
        sost2->power1                     = power1->isChecked();
        sost2->power2                     = power2->isChecked();
        sost2->power3                     = power3->isChecked();
        sost2->power4                     = power4->isChecked();
        sost2->power5                     = power5->isChecked();
        sost2->power6                     = power6->isChecked();
        sost2->power7                     = power7->isChecked();
        sost2->power8                     = power8->isChecked();
    }



};

/* class B: public Device
{
    Q_OBJECT
public:
    B();
    B(QString name, int addr);
    QByteArray getState() {
        return QByteArray();
    }

    Status_B * statusB;
    //Status_UMP_MNKVN * statusUMP;
    MODUL_Status_BVD * statusBVD11;
    MODUL_Status_BVD * statusBVD12;
    MODUL_Status_BVD * statusBVD13;
    MODUL_Status_BVD * statusBVD14;

    MODUL_Status_BVD * statusBVD21;
    MODUL_Status_BVD * statusBVD22;
    MODUL_Status_BVD * statusBVD23;
    MODUL_Status_BVD * statusBVD24;
    MODUL_Status_BVD * statusBVD25;
    MODUL_Status_BVD * statusBVD26;
    MODUL_Status_BVD * statusBVD27;
    MODUL_Status_BVD * statusBVD28;

    MODUL_Status_BVD * statusBVD31;
    MODUL_Status_BVD * statusBVD32;
    MODUL_Status_BVD * statusBVD33;
    MODUL_Status_BVD * statusBVD34;
    MODUL_Status_BVD * statusBVD35;

    Status_CAN * statusCAN;

    /* For All CHANNELS
    QCheckBox * channelOut;
    QCheckBox * channelInReady;
    QCheckBox * channelInOn;
    QCheckBox * channelMu;
    QCheckBox * channelNeispr1;
    QCheckBox * channelNeispr2;
    QCheckBox * channelNSD1;
    QCheckBox * channelNSD2;

    /*B status
    QCheckBox * malfunction;
    QCheckBox * overheat   ;
    QCheckBox * nsd        ;
    QCheckBox * overload   ;
    QCheckBox * powerX5     ;
    QCheckBox * powerX6     ;
    QCheckBox * powerX7     ;
    QCheckBox * powerX8     ;
    QCheckBox * powerX9     ;
    QCheckBox * powerX10     ;
    QCheckBox * powerX13     ;
    QCheckBox * powerX14     ;

    /*bvd11
    QCheckBox * res_1_1;
    QCheckBox * powerBVD1_1;
    QCheckBox * malfunctionBVD1_1;
    QCheckBox * fireBVD1_1;
    QCheckBox * MN1on_1;
    QCheckBox * MN2on_1;
    QCheckBox * MN1malfunction_1;
    QCheckBox * MN2malfunction_1;

    /*bvd12
    QCheckBox * res_1_2;
    QCheckBox * powerBVD1_2;
    QCheckBox * malfunctionBVD1_2;
    QCheckBox * fireBVD1_2;
    QCheckBox * MN1on_2;
    QCheckBox * MN2on_2;
    QCheckBox * MN1malfunction_2;
    QCheckBox * MN2malfunction_2;

    /*bvd13
    QCheckBox * res_1_3;
    QCheckBox * powerBVD1_3;
    QCheckBox * malfunctionBVD1_3;
    QCheckBox * fireBVD1_3;
    QCheckBox * MN1on_3;
    QCheckBox * MN2on_3;
    QCheckBox * MN1malfunction_3;
    QCheckBox * MN2malfunction_3;

    /*bvd14
    QCheckBox * res_1_4;
    QCheckBox * powerBVD1_4;
    QCheckBox * malfunctionBVD1_4;
    QCheckBox * fireBVD1_4;
    QCheckBox * MN1on_4;
    QCheckBox * MN2on_4;
    QCheckBox * MN1malfunction_4;
    QCheckBox * MN2malfunction_4;

    /*CAN
    //QCheckBox * CAN_NOSIGNAL_UMP1_1;
    //QCheckBox * CAN_NOSIGNAL_UMP1_2;
    QCheckBox * CAN_NOSIGNAL_BVD1_1;
    QCheckBox * CAN_NOSIGNAL_BVD1_2;
    QCheckBox * CAN_NOSIGNAL_BVD1_3;
    QCheckBox * CAN_NOSIGNAL_BVD1_4;

};
*/
class PP4: public Device
{
    Q_OBJECT
public:
    PP4();
    PP4(QString name, int addr, QVector<FunctionalDevice*> funcs);
    QByteArray getState() {
        return QByteArray();
    }

    Status_PP4 * statusPP4;
    Status_UMP_MNKVN * statusUMP;
    MODUL_Status_BVD * statusBVD31;
    MODUL_Status_BVD * statusBVD32;
    Status_CAN * statusCAN;

    /* For All CHANNELS */
    QCheckBox * channelOut;
    QCheckBox * channelInReady;
    QCheckBox * channelInOn;
    QCheckBox * channelMu;
    QCheckBox * channelNeispr1;
    QCheckBox * channelNeispr2;
    QCheckBox * channelNSD1;
    QCheckBox * channelNSD2;

    /*PP4 status*/
    QCheckBox * malfunction;
    QCheckBox * overheat   ;
    QCheckBox * nsd        ;
    QCheckBox * overload   ;
    QCheckBox * power1     ;
    QCheckBox * power2     ;

    /*ump*/
    QCheckBox * UMP1_1_on;
    QCheckBox * UMP1_2_on;
    QCheckBox * UMP1_1_malf;
    QCheckBox * UMP1_2_malf;
    QCheckBox * MNKVN_malf;
    QCheckBox * UMP1_1_fire;
    QCheckBox * UMP1_2_fire;

    /*bvd31*/
    QCheckBox * res_1_1;
    QCheckBox * powerBVD3_1;
    QCheckBox * malfunctionBVD3_1;
    QCheckBox * fireBVD3_1;
    QCheckBox * MN1on_1;
    QCheckBox * MN2on_1;
    QCheckBox * MN1malfunction_1;
    QCheckBox * MN2malfunction_1;

    /*bvd32*/
    QCheckBox * res_1_2;
    QCheckBox * powerBVD3_2;
    QCheckBox * malfunctionBVD3_2;
    QCheckBox * fireBVD3_2;
    QCheckBox * MN1on_2;
    QCheckBox * MN2on_2;
    QCheckBox * MN1malfunction_2;
    QCheckBox * MN2malfunction_2;

    /*CAN*/

    QCheckBox * CAN_NOSIGNAL_UMP1_1;
    QCheckBox * CAN_NOSIGNAL_UMP1_2;
    QCheckBox * CAN_NOSIGNAL_BVD3_1;
    QCheckBox * CAN_NOSIGNAL_BVD3_2;


    const QVector<FunctionalDevice*> funcs() { return m_funcs; }

private:
    QVector<FunctionalDevice*> m_funcs;

private slots:
    void updateWords() {
        statusPP4->malfunction         =   malfunction->isChecked();
        statusPP4->nsd                 =   nsd->isChecked();
        statusPP4->overheat            =   overheat->isChecked();
        statusPP4->overload            =   overload->isChecked();
        statusPP4->power1              =   power1->isChecked();
        statusPP4->power2              =   power2->isChecked();
        statusUMP->UMP1_1_on           =   UMP1_1_on->isChecked();
        statusUMP->UMP1_2_on           =   UMP1_2_on->isChecked();
        statusUMP->UMP1_1_malf         =   UMP1_1_malf->isChecked();
        statusUMP->UMP1_2_malf         =   UMP1_2_malf->isChecked();
        statusUMP->MNKVN_malf          =   MNKVN_malf->isChecked();
        statusUMP->UMP1_1_fire         =   UMP1_1_fire->isChecked();
        statusUMP->UMP1_2_fire         =   UMP1_2_fire->isChecked();

        statusBVD31->res_1             =   res_1_1->isChecked();
        statusBVD31->powerBVD3         =   powerBVD3_1->isChecked();
        statusBVD31->malfunctionBVD3   =   malfunctionBVD3_1->isChecked();
        statusBVD31->fireBVD3          =   fireBVD3_1->isChecked();
        statusBVD31->MN1on             =   MN1on_1->isChecked();
        statusBVD31->MN2on             =   MN2on_1->isChecked();
        statusBVD31->MN1malfunction    =   MN1malfunction_1->isChecked();
        statusBVD31->MN2malfunction    =   MN2malfunction_1->isChecked();

        statusBVD32->res_1             =   res_1_2->isChecked();
        statusBVD32->powerBVD3         =   powerBVD3_2->isChecked();
        statusBVD32->malfunctionBVD3   =   malfunctionBVD3_2->isChecked();
        statusBVD32->fireBVD3          =   fireBVD3_2->isChecked();
        statusBVD32->MN1on             =   MN1on_2->isChecked();
        statusBVD32->MN2on             =   MN2on_2->isChecked();
        statusBVD32->MN1malfunction    =   MN1malfunction_2->isChecked();
        statusBVD32->MN2malfunction    =   MN2malfunction_2->isChecked();

        statusCAN->CAN_NOSIGNAL_UMP1_1 =   CAN_NOSIGNAL_UMP1_1->isChecked();
        statusCAN->CAN_NOSIGNAL_UMP1_2 =   CAN_NOSIGNAL_UMP1_2->isChecked();
        statusCAN->CAN_NOSIGNAL_BVD3_1 =   CAN_NOSIGNAL_BVD3_1->isChecked();
        statusCAN->CAN_NOSIGNAL_BVD3_2 =   CAN_NOSIGNAL_BVD3_2->isChecked();
    }
    void activateAllOut(bool check);
    void activateAllInOn(bool check);
    void activateAllInReady(bool check);
    void activateAllinFail1(bool check);
    void activateAllInFail2(bool check);
    void activateAllNSD1(bool check);
    void activateAllNSD2(bool check);
    void activateAllInLocal(bool check);
    void updateWorking(bool check);
};

#endif // DEVICE_H
