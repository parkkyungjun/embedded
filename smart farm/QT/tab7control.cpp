#include "tab7control.h"
#include "ui_tab7control.h"

tab7control::tab7control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab7control)
{
    ui->setupUi(this);
    connect(ui->pPBRed,SIGNAL(clicked(bool)),this,SLOT(slotRedOnOff(bool)));
    connect(ui->pPBBlue,SIGNAL(clicked(bool)),this,SLOT(slotBlueOnOff(bool)));
    connect(ui->pPBPurple,SIGNAL(clicked(bool)),this,SLOT(slotPurpleOnOff(bool)));
}
void tab7control::slotRedOnOff(bool bCheck) {
    if(bCheck) {
        emit sigSocketSendData("[502]REDON");
        ui->pPBRed->setChecked(false);
    }
    else {
        emit sigSocketSendData("[502]REDOFF");
        ui->pPBRed->setChecked(true);
    }
}
void tab7control::slotBlueOnOff(bool bCheck) {
    if(bCheck) {
        emit sigSocketSendData("[502]BLUEON");
        ui->pPBBlue->setChecked(false);
    }
    else {
        emit sigSocketSendData("[502]BLUEOFF");
        ui->pPBBlue->setChecked(true);
    }
}
void tab7control::slotPurpleOnOff(bool bCheck) {
    if(bCheck) {
        emit sigSocketSendData("[502]PURPLEON");
        ui->pPBPurple->setChecked(false);
    }
    else {
        emit sigSocketSendData("[502]PURPLEOFF");
        ui->pPBPurple->setChecked(true);
    }
}
void tab7control::slotTab7RecvData(QString recvData) {
    QIcon icon;
//     qDebug() << "TEST1 " << recvData;
    QStringList qlist = recvData.split("@");    //@KSH_QT@LAMPON
    if(qlist[2] =="REDON")
    {
         ui->pPBRed->setChecked(true);
         icon.addFile(":/IotQtClient/Image/red_on.png");
         ui->pPBRed->setIcon(icon);
         ui->pPBRed->setIconSize(QSize(60,60));
    }
    else if(qlist[2] =="REDOFF")
    {
         ui->pPBRed->setChecked(false);
         icon.addFile(":/IotQtClient/Image/red_off.png");
         ui->pPBRed->setIcon(icon);
         ui->pPBRed->setIconSize(QSize(60,60));
    }
    if(qlist[2] =="BLUEON")
    {
         ui->pPBBlue->setChecked(true);
         icon.addFile(":/IotQtClient/Image/blue_on.png");
         ui->pPBBlue->setIcon(icon);
         ui->pPBBlue->setIconSize(QSize(60,60));
    }
    else if(qlist[2] =="BLUEOFF")
    {
         ui->pPBBlue->setChecked(false);
         icon.addFile(":/IotQtClient/Image/blue_off.png");
         ui->pPBBlue->setIcon(icon);
         ui->pPBBlue->setIconSize(QSize(60,60));
    }
    if(qlist[2] =="PURPLEON")
    {
         ui->pPBPurple->setChecked(true);
         icon.addFile(":/IotQtClient/Image/purple_on.png");
         ui->pPBPurple->setIcon(icon);
         ui->pPBPurple->setIconSize(QSize(60,60));
    }
    else if(qlist[2] =="PURPLEOFF")
    {
         ui->pPBPurple->setChecked(false);
         icon.addFile(":/IotQtClient/Image/purple_off.png");
         ui->pPBPurple->setIcon(icon);
         ui->pPBPurple->setIconSize(QSize(60,60));
    }
}
tab7control::~tab7control()
{
    delete ui;
}
