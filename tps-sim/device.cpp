#include "device.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QWidget>

Device::Device()
{
}

Modules::Modules() {}

Modules::Modules(QString name, int addr) : Device(name, addr){
    stMd = new MODUL_Type_Info();
    num_Md = new MODUL_Number();
    type_Md = new MODUL_Type_Info();
    sost = new MODUL_Status_Out();
    m_isModuleWorking = true;
    res             = new QCheckBox("---");
    malfunction     = new QCheckBox("Неисправность модуля");
    fireMODUL       = new QCheckBox("Степень пожарной опасности");
    control_mode    = new QCheckBox("Режим управления модуля");
    power1          = new QCheckBox("Наличие питания на выходе 1");
    power2          = new QCheckBox("Наличие питания на выходе 2");
    power3          = new QCheckBox("Наличие питания на выходе 3");
    power4          = new QCheckBox("Наличие питания на выходе 4");
    power5          = new QCheckBox("Наличие питания на выходе 5");
    power6          = new QCheckBox("Наличие питания на выходе 6");
    power7          = new QCheckBox("Наличие питания источника 7");
    power8          = new QCheckBox("Наличие питания источника 8");

    connect(res           , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(malfunction   , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power3        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power4        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power5        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power6        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power7        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power8        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    QCheckBox * chbxIsWorking = new QCheckBox("Работает");
    chbxIsWorking->setChecked(true);
    connect(chbxIsWorking, SIGNAL(toggled(bool)), this, SLOT(updateWorking(bool)));

    QGridLayout * grid = new QGridLayout(this);
    int row = 0, col = 0;
    QLabel * titleLabel = new QLabel(name);
    QFont f(font());
    f.setPixelSize(32);
    titleLabel->setFont(f);
    grid->addWidget(titleLabel, 0, col, 1, 1);
    grid->addWidget(chbxIsWorking, 0, 1, 1, 1);
    grid->setColumnStretch(3, 1000);
    QGroupBox* gb = new QGroupBox("Модуль", this);
    QGridLayout * myDataGrid = new QGridLayout(gb);
    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние модуля"), row++, col);
    myDataGrid->addWidget(malfunction          , row++, col);
    myDataGrid->addWidget(res           , row++, col);

    row = 0; col++;
    myDataGrid->addWidget(new QLabel("Наличие напряжения на выходе источника"), row++, col);
    myDataGrid->addWidget(power1, row++, col);
    myDataGrid->addWidget(power2, row++, col);
    myDataGrid->addWidget(power3, row++, col);
    myDataGrid->addWidget(power4, row++, col);
    myDataGrid->addWidget(power5, row++, col);
    myDataGrid->addWidget(power6, row++, col);
    myDataGrid->addWidget(power7, row++, col);
    myDataGrid->addWidget(power8, row++, col);
    grid->addWidget(gb, 1, 0, 1, 2);
}

A2::A2() {}

A2::A2(QString name, int addr): Device(name, addr)

{
    stPr = new Status_Pribora();
    sost1 = new Sost_out_1();
    sost2 = new Sost_out_2();
    m_isDeviceWorking = true;
    Fail            = new QCheckBox("Неисправность");
    res             = new QCheckBox("---");
    OverheatPolka1  = new QCheckBox("Перегрев полки 1");
    OverheatPolka2  = new QCheckBox("Перегрев полки 2");
    OverheatPolka3  = new QCheckBox("Перегрев полки 3");
    OverheatPolka4  = new QCheckBox("Перегрев полки 4");
    OverheatPolka5  = new QCheckBox("Перегрев полки 5");
    fail1           = new QCheckBox("Неисправность питания 1");
    fail2           = new QCheckBox("Неисправность питания 2");
    fail3           = new QCheckBox("Неисправность питания 3");
    fail4           = new QCheckBox("Неисправность питания 4");
    fail5           = new QCheckBox("Неисправность питания 5");
    fail6           = new QCheckBox("Неисправность питания 6");
    fail7           = new QCheckBox("Неисправность питания 7");
    fail8           = new QCheckBox("Неисправность питания 8");
    power1          = new QCheckBox("Наличие питания источника 1");
    power2          = new QCheckBox("Наличие питания источника 2");
    power3          = new QCheckBox("Наличие питания источника 3");
    power4          = new QCheckBox("Наличие питания источника 4");
    power5          = new QCheckBox("Наличие питания источника 5");
    power6          = new QCheckBox("Наличие питания источника 6");
    power7          = new QCheckBox("Наличие питания источника 7");
    power8          = new QCheckBox("Наличие питания источника 8");

    connect(Fail          , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(res           , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(OverheatPolka1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(OverheatPolka2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(OverheatPolka3, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(OverheatPolka4, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(OverheatPolka5, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail1         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail2         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail3         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail4         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail5         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail6         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail7         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fail8         , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power1        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power2        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power3        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power4        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power5        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power6        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power7        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power8        , SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    QCheckBox * chbxIsWorking = new QCheckBox("Работает");
    chbxIsWorking->setChecked(true);
    connect(chbxIsWorking, SIGNAL(toggled(bool)), this, SLOT(updateWorking(bool)));

    QGridLayout * grid = new QGridLayout(this);
    int row = 0, col = 0;
    QLabel * titleLabel = new QLabel(name);
    QFont f(font());
    f.setPixelSize(32);
    titleLabel->setFont(f);
    grid->addWidget(titleLabel, 0, col, 1, 1);
    grid->addWidget(chbxIsWorking, 0, 1, 1, 1);
    grid->setColumnStretch(3, 1000);
    QGroupBox* gb = new QGroupBox("Прибор", this);
    QGridLayout * myDataGrid = new QGridLayout(gb);
    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние прибора"), row++, col);
    myDataGrid->addWidget(Fail          , row++, col);
    myDataGrid->addWidget(res           , row++, col);
    myDataGrid->addWidget(OverheatPolka1, row++, col);
    myDataGrid->addWidget(OverheatPolka2, row++, col);
    myDataGrid->addWidget(OverheatPolka3, row++, col);
    myDataGrid->addWidget(OverheatPolka4, row++, col);
    myDataGrid->addWidget(OverheatPolka5, row++, col);
    row = 0; col++;
    myDataGrid->addWidget(new QLabel("Неисправность источников"), row++, col);
    myDataGrid->addWidget(fail1, row++, col);
    myDataGrid->addWidget(fail2, row++, col);
    myDataGrid->addWidget(fail3, row++, col);
    myDataGrid->addWidget(fail4, row++, col);
    myDataGrid->addWidget(fail5, row++, col);
    myDataGrid->addWidget(fail6, row++, col);
    myDataGrid->addWidget(fail7, row++, col);
    myDataGrid->addWidget(fail8, row++, col);
    row = 0; col++;
    myDataGrid->addWidget(new QLabel("Наличие напряжения на выходе источника"), row++, col);
    myDataGrid->addWidget(power1, row++, col);
    myDataGrid->addWidget(power2, row++, col);
    myDataGrid->addWidget(power3, row++, col);
    myDataGrid->addWidget(power4, row++, col);
    myDataGrid->addWidget(power5, row++, col);
    myDataGrid->addWidget(power6, row++, col);
    myDataGrid->addWidget(power7, row++, col);
    myDataGrid->addWidget(power8, row++, col);
    grid->addWidget(gb, 1, 0, 1, 2);
}

/* B::B(){}

B::B(QString name, int addr) : Device(name, addr)
{
    m_isDeviceWorking = true;

    malfunction = new QCheckBox("Неисправность");
    overheat    = new QCheckBox("Перегрев");
    nsd         = new QCheckBox("НСД");
    overload    = new QCheckBox("Перегрузка");
    power1      = new QCheckBox("Сеть1");
    power2      = new QCheckBox("Сеть2");
    connect(malfunction, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(overheat, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(nsd, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(overload, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    power1->setEnabled(false);

    res_1_1             = new QCheckBox("---");
    powerBVD3_1         = new QCheckBox("Сеть");
    malfunctionBVD3_1   = new QCheckBox("Неисправность БВД");
    fireBVD3_1          = new QCheckBox("Пожар");
    MN1on_1             = new QCheckBox("МН1 вкл");
    MN2on_1             = new QCheckBox("МН2 вкл");
    MN1malfunction_1    = new QCheckBox("Неисправность МН1");
    MN2malfunction_1    = new QCheckBox("Неисправность МН2");
    connect(res_1_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(powerBVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(malfunctionBVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fireBVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1on_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2on_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1malfunction_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2malfunction_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    res_1_2             = new QCheckBox("---");
    powerBVD3_2         = new QCheckBox("Сеть");
    malfunctionBVD3_2   = new QCheckBox("Неисправность БВД");
    fireBVD3_2          = new QCheckBox("Пожар");
    MN1on_2             = new QCheckBox("МН1 вкл");
    MN2on_2             = new QCheckBox("МН2 вкл");
    MN1malfunction_2    = new QCheckBox("Неисправность МН1");
    MN2malfunction_2    = new QCheckBox("Неисправность Мн2");
    connect(res_1_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(powerBVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(malfunctionBVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fireBVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1on_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2on_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1malfunction_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2malfunction_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    CAN_NOSIGNAL_UMP1_1 = new QCheckBox("Отсутствие обмена на CAN УМП-1(1)");
    CAN_NOSIGNAL_UMP1_2 = new QCheckBox("Отсутствие обмена на CAN УМП-1(2)");
    CAN_NOSIGNAL_BVD3_1 = new QCheckBox("Отсутствие обмена на CAN БВД3(1)");
    CAN_NOSIGNAL_BVD3_2 = new QCheckBox("Отсутствие обмена на CAN БВД3(2)");
    connect(CAN_NOSIGNAL_UMP1_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(CAN_NOSIGNAL_UMP1_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(CAN_NOSIGNAL_BVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(CAN_NOSIGNAL_BVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

} */

PP4::PP4() {}

PP4::PP4(QString name, int addr, QVector<FunctionalDevice *> funcs) : Device(name, addr),
    m_funcs(funcs)
{
    m_isDeviceWorking = true;
    malfunction = new QCheckBox("Неисправность");
    overheat    = new QCheckBox("Перегрев");
    nsd         = new QCheckBox("НСД");
    overload    = new QCheckBox("Перегрузка");
    power1      = new QCheckBox("Сеть1");
    power2      = new QCheckBox("Сеть2");
    connect(malfunction, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(overheat, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(nsd, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(overload, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(power2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    power1->setEnabled(false);
    UMP1_1_on   = new QCheckBox("Выход модуля УМП-1(1)");
    UMP1_2_on   = new QCheckBox("Выход модуля УМП-1(2)");
    UMP1_1_malf = new QCheckBox("Неиспр модуля УМП-1(1)");
    UMP1_2_malf = new QCheckBox("Неиспр модуля УМП-1(2)");
    MNKVN_malf  = new QCheckBox("Неиспр МНКВН");
    UMP1_1_fire = new QCheckBox("Пожар УМП-1(1)");
    UMP1_2_fire = new QCheckBox("Пожар УМП-1(2)");
    connect(UMP1_1_on, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(UMP1_2_on, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(UMP1_1_malf, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(UMP1_2_malf, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MNKVN_malf, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(UMP1_1_fire, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(UMP1_2_fire, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    res_1_1             = new QCheckBox("---");
    powerBVD3_1         = new QCheckBox("Сеть");
    malfunctionBVD3_1   = new QCheckBox("Неисправность БВД");
    fireBVD3_1          = new QCheckBox("Пожар");
    MN1on_1             = new QCheckBox("МН1 вкл");
    MN2on_1             = new QCheckBox("МН2 вкл");
    MN1malfunction_1    = new QCheckBox("Неисправность МН1");
    MN2malfunction_1    = new QCheckBox("Неисправность МН2");
    connect(res_1_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(powerBVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(malfunctionBVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fireBVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1on_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2on_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1malfunction_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2malfunction_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    res_1_2             = new QCheckBox("---");
    powerBVD3_2         = new QCheckBox("Сеть");
    malfunctionBVD3_2   = new QCheckBox("Неисправность БВД");
    fireBVD3_2          = new QCheckBox("Пожар");
    MN1on_2             = new QCheckBox("МН1 вкл");
    MN2on_2             = new QCheckBox("МН2 вкл");
    MN1malfunction_2    = new QCheckBox("Неисправность МН1");
    MN2malfunction_2    = new QCheckBox("Неисправность Мн2");
    connect(res_1_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(powerBVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(malfunctionBVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(fireBVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1on_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2on_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN1malfunction_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(MN2malfunction_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    CAN_NOSIGNAL_UMP1_1 = new QCheckBox("Отсутствие обмена на CAN УМП-1(1)");
    CAN_NOSIGNAL_UMP1_2 = new QCheckBox("Отсутствие обмена на CAN УМП-1(2)");
    CAN_NOSIGNAL_BVD3_1 = new QCheckBox("Отсутствие обмена на CAN БВД3(1)");
    CAN_NOSIGNAL_BVD3_2 = new QCheckBox("Отсутствие обмена на CAN БВД3(2)");
    connect(CAN_NOSIGNAL_UMP1_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(CAN_NOSIGNAL_UMP1_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(CAN_NOSIGNAL_BVD3_1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(CAN_NOSIGNAL_BVD3_2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));

    QCheckBox * chbxIsWorking = new QCheckBox("Работает");
    chbxIsWorking->setChecked(true);
    connect(chbxIsWorking, SIGNAL(toggled(bool)), this, SLOT(updateWorking(bool)));

    QGridLayout * grid = new QGridLayout(this);
    int row = 0, col = 0;
    QLabel * titleLabel = new QLabel(name);
    QFont f(font());
    f.setPixelSize(32);
    titleLabel->setFont(f);
    while(m_funcs.size() < 10) {
        m_funcs.push_back(new FunctionalDevice("Канал" + QString::number(m_funcs.size()+1)));
    }
    grid->addWidget(titleLabel, 0, col, 1, m_funcs.size()-1);
    grid->addWidget(chbxIsWorking, 0, 1, 1, 1);
    QGroupBox* gb = new QGroupBox("Прибор", this);
    QGridLayout * myDataGrid = new QGridLayout(gb);
    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние ПП4"), row++, 0);
    myDataGrid->addWidget(malfunction, row++, 0);
    myDataGrid->addWidget(overheat   , row++, 0);
    myDataGrid->addWidget(nsd        , row++, 0);
    myDataGrid->addWidget(overload   , row++, 0);
    myDataGrid->addWidget(power1     , row++, 0);
    myDataGrid->addWidget(power2     , row++, 0);
    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние УМП и МНКВН"), row++, 1);
    myDataGrid->addWidget(UMP1_1_on  , row++, 1);
    myDataGrid->addWidget(UMP1_2_on  , row++, 1);
    myDataGrid->addWidget(UMP1_1_malf, row++, 1);
    myDataGrid->addWidget(UMP1_2_malf, row++, 1);
    myDataGrid->addWidget(MNKVN_malf , row++, 1);
    myDataGrid->addWidget(UMP1_1_fire, row++, 1);
    myDataGrid->addWidget(UMP1_2_fire, row++, 1);
    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние БВД3(1)"), row++, 2);
    myDataGrid->addWidget(res_1_1          , row++, 2);
    myDataGrid->addWidget(powerBVD3_1      , row++, 2);
    myDataGrid->addWidget(malfunctionBVD3_1, row++, 2);
    myDataGrid->addWidget(fireBVD3_1       , row++, 2);
    myDataGrid->addWidget(MN1on_1          , row++, 2);
    myDataGrid->addWidget(MN2on_1          , row++, 2);
    myDataGrid->addWidget(MN1malfunction_1 , row++, 2);
    myDataGrid->addWidget(MN2malfunction_1 , row++, 2);

    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние БВД3(2)"), row++, 3);
    myDataGrid->addWidget(res_1_2          , row++, 3);
    myDataGrid->addWidget(powerBVD3_2      , row++, 3);
    myDataGrid->addWidget(malfunctionBVD3_2, row++, 3);
    myDataGrid->addWidget(fireBVD3_2       , row++, 3);
    myDataGrid->addWidget(MN1on_2          , row++, 3);
    myDataGrid->addWidget(MN2on_2          , row++, 3);
    myDataGrid->addWidget(MN1malfunction_2 , row++, 3);
    myDataGrid->addWidget(MN2malfunction_2 , row++, 3);

    row = 0;
    myDataGrid->addWidget(new QLabel("Состояние CAN"), row++, 4);
    myDataGrid->addWidget(CAN_NOSIGNAL_UMP1_1, row++, 4);
    myDataGrid->addWidget(CAN_NOSIGNAL_UMP1_2, row++, 4);
    myDataGrid->addWidget(CAN_NOSIGNAL_BVD3_1, row++, 4);
    myDataGrid->addWidget(CAN_NOSIGNAL_BVD3_2, row++, 4);

    grid->addWidget(gb, 1, 0, 1, m_funcs.size());

//    statusPP4
    row = 3;

    channelOut = new QCheckBox("Вкл вых фид");
    connect(channelOut, SIGNAL(toggled(bool)), this, SLOT(activateAllOut(bool)));
    channelInReady = new QCheckBox("Гот ВПН");
    connect(channelInReady, SIGNAL(toggled(bool)), this, SLOT(activateAllInReady(bool)));
    channelInOn = new QCheckBox("Вкл ВПН");
    connect(channelInOn, SIGNAL(toggled(bool)), this, SLOT(activateAllInOn(bool)));
    channelMu = new QCheckBox("МУ");
    connect(channelMu, SIGNAL(toggled(bool)), this, SLOT(activateAllInLocal(bool)));
    channelNeispr1 = new QCheckBox("Неиспр1");
    connect(channelNeispr1, SIGNAL(toggled(bool)), this, SLOT(activateAllinFail1(bool)));
    channelNeispr2 = new QCheckBox("Неиспр2");
    connect(channelNeispr2, SIGNAL(toggled(bool)), this, SLOT(activateAllInFail2(bool)));
    channelNSD1 = new QCheckBox("НСД1");
    connect(channelNSD1, SIGNAL(toggled(bool)), this, SLOT(activateAllNSD1(bool)));
    channelNSD2 = new QCheckBox("НСД2");
    connect(channelNSD2, SIGNAL(toggled(bool)), this, SLOT(activateAllNSD2(bool)));

    grid->addWidget(channelOut, row++, 0);
    row++;
    grid->addWidget(channelInReady, row++, 0);
    grid->addWidget(channelInOn, row++, 0);
    grid->addWidget(channelMu,      row++, 0);
    grid->addWidget(channelNeispr1, row++, 0);
    grid->addWidget(channelNeispr2, row++, 0);
    grid->addWidget(channelNSD1,    row++, 0);
    grid->addWidget(channelNSD2,    row++, 0);

    foreach(FunctionalDevice * dev, m_funcs) {
        row = 2;
        grid->addWidget(new QLabel(dev->name()), row++, col+1, 1, 1);
        grid->addWidget(dev->outOff , row++, col+1);
        grid->addWidget(new QLabel(dev->name()), row++, col+1, 1, 1);
        grid->addWidget(dev->inReady, row++, col+1);
        grid->addWidget(dev->inOn   , row++, col+1);
        grid->addWidget(dev->inLocal, row++, col+1);
        grid->addWidget(dev->inFail1, row++, col+1);
        grid->addWidget(dev->inFail2, row++, col+1);
        grid->addWidget(dev->inNsd1 , row++, col+1);
        grid->addWidget(dev->inNsd2 , row++, col+1);
        col++;
    }

    statusPP4 = new Status_PP4(0);
    statusUMP = new Status_UMP_MNKVN(0);
    statusBVD31 = new MODUL_Status_BVD(0);
    statusBVD32 = new MODUL_Status_BVD(0);
    statusCAN = new Status_CAN(0);


    power1->setChecked(true);
    power2->setChecked(true);
}

void PP4::activateAllOut(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->outOff->setChecked(!check);
        dev->outOff->toggle();
    }
}
void PP4::activateAllInOn(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inOn->setChecked(!check);
        dev->inOn->toggle();
    }
}
void PP4::activateAllInReady(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inReady->setChecked(!check);
        dev->inReady->toggle();
    }
}
void PP4::activateAllinFail1(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inFail1->setChecked(!check);
        dev->inFail1->toggle();
    }
}
void PP4::activateAllInFail2(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inFail2->setChecked(!check);
        dev->inFail2->toggle();
    }
}
void PP4::activateAllNSD1(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inNsd1->setChecked(!check);
        dev->inNsd1->toggle();
    }
}
void PP4::activateAllNSD2(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inNsd2->setChecked(!check);
        dev->inNsd2->toggle();
    }
}
void PP4::activateAllInLocal(bool check)
{
    foreach(FunctionalDevice * dev, m_funcs) {
        dev->inLocal->setChecked(!check);
        dev->inLocal->toggle();
    }
}

void PP4::updateWorking(bool check) {
    power1->setChecked(check);
    m_isDeviceWorking = check;
}


FunctionalDevice::FunctionalDevice(QString name) : m_name(name) {
    state1 = new Sost_Kan_1_PP4(0);
    state2 = new Sost_Kan_2_PP4(0);
    QVBoxLayout *vlay = new QVBoxLayout(this);
    outOff       = new QCheckBox();
    inReady      = new QCheckBox();
    inOn         = new QCheckBox();
    inLocal      = new QCheckBox();
    inFail1      = new QCheckBox();
    inFail2      = new QCheckBox();
    inNsd1       = new QCheckBox();
    inNsd2       = new QCheckBox();
    connect(outOff , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inReady, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inOn   , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inLocal, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inFail1, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inFail2, SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inNsd1 , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
    connect(inNsd2 , SIGNAL(toggled(bool)), this, SLOT(updateWords()));
}


