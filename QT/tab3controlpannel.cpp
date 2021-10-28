#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    connect(ui->pPBRed,SIGNAL(clicked(bool)),this,SLOT(slotRedOnOff(bool)));
    connect(ui->pPBBlue,SIGNAL(clicked(bool)),this,SLOT(slotBlueOnOff(bool)));
    connect(ui->pPBPurple,SIGNAL(clicked(bool)),this,SLOT(slotPurpleOnOff(bool)));
    connect(ui->pPBName,SIGNAL(clicked()),this,SLOT(slotSearchName()));


}
void Tab3ControlPannel::slotSearchName(){
    QString N = ui->pLEName->text();
    QSqlQuery query;
    QIcon icon;
    qDebug() << N;
    if(query.exec("select * from rbp_db where name='" + N + "'")){
        qDebug() << "second";
        while(query.next()){
            qDebug() << query.value("r").toInt() << query.value("b").toInt() << query.value("p").toInt();
            if(query.value("r").toInt()==0)
            {
                icon.addFile(":/IotQtClient/Image/red_off.png");
                ui->pPBRed->setIcon(icon);
                ui->pPBRed->setIconSize(QSize(60,60));
            }
            else if(query.value("r").toInt()==1)
            {
                icon.addFile(":/IotQtClient/Image/red_on.png");
                ui->pPBRed->setIcon(icon);
                ui->pPBRed->setIconSize(QSize(60,60));
            }
            if(query.value("b").toInt()==0)
            {
                icon.addFile(":/IotQtClient/Image/blue_off.png");
                ui->pPBBlue->setIcon(icon);
                ui->pPBBlue->setIconSize(QSize(60,60));
            }
            else if(query.value("b").toInt()==1)
            {
                icon.addFile(":/IotQtClient/Image/blue_on.png");
                ui->pPBBlue->setIcon(icon);
                ui->pPBBlue->setIconSize(QSize(60,60));
            }
            if(query.value("p").toInt()==0)
            {
                icon.addFile(":/IotQtClient/Image/purple_off.png");
                ui->pPBPurple->setIcon(icon);
                ui->pPBPurple->setIconSize(QSize(60,60));
            }
            else if(query.value("p").toInt()==1)
            {
                icon.addFile(":/IotQtClient/Image/purple_on.png");
                ui->pPBPurple->setIcon(icon);
                ui->pPBPurple->setIconSize(QSize(60,60));
            }

        }
    }
}
void Tab3ControlPannel::slotRedOnOff(bool bCheck) {
    QString N = ui->pLEName->text();
    QIcon icon;
    QSqlQuery query;
    if(bCheck) {
        qDebug() << "check in";
        if(query.exec("update rbp_db set r = 1 where name='" + N + "'")){
            emit sigSocketSendData('[' + N + ']' + "REDON");
            icon.addFile(":/IotQtClient/Image/red_on.png");
            ui->pPBRed->setIcon(icon);
            ui->pPBRed->setIconSize(QSize(60,60));
            ui->pPBRed->setChecked(true);
        }
    }
    else {
        query.exec("update rbp_db set r = 0 where name='" + N + "'");{
            emit sigSocketSendData('[' + N + ']' + "REDOFF");
            icon.addFile(":/IotQtClient/Image/red_off.png");
            ui->pPBRed->setIcon(icon);
            ui->pPBRed->setIconSize(QSize(60,60));
            ui->pPBRed->setChecked(false);
        }
    }
}
void Tab3ControlPannel::slotBlueOnOff(bool bCheck) {
    QString N = ui->pLEName->text();
    QIcon icon;
    QSqlQuery query;
    if(bCheck) {
        query.exec("update rbp_db set b = 1 where name='" + N + "'");{
            icon.addFile(":/IotQtClient/Image/blue_on.png");
            ui->pPBBlue->setIcon(icon);
            ui->pPBBlue->setIconSize(QSize(60,60));
            emit sigSocketSendData('[' + N + ']' + "BLUEON");
            ui->pPBBlue->setChecked(true);
        }
    }
    else {
        query.exec("update rbp_db set b = 0 where name='" + N + "'");{
            icon.addFile(":/IotQtClient/Image/blue_off.png");
            ui->pPBBlue->setIcon(icon);
            ui->pPBBlue->setIconSize(QSize(60,60));
            emit sigSocketSendData('[' + N + ']' + "BLUEOFF");
            ui->pPBBlue->setChecked(false);
        }
    }

}
void Tab3ControlPannel::slotPurpleOnOff(bool bCheck) {
    QString N = ui->pLEName->text();
    QIcon icon;
    QSqlQuery query;
    if(bCheck) {
        query.exec("update rbp_db set p = 1 where name='" + N + "'");{
            icon.addFile(":/IotQtClient/Image/purple_on.png");
            ui->pPBPurple->setIcon(icon);
            ui->pPBPurple->setIconSize(QSize(60,60));
            emit sigSocketSendData('[' + N + ']' + "PURPLEON");
            ui->pPBPurple->setChecked(true);
        }
    }
    else {
        query.exec("update rbp_db set p = 0 where name='" + N + "'");{
            icon.addFile(":/IotQtClient/Image/purple_off.png");
            ui->pPBPurple->setIcon(icon);
            ui->pPBPurple->setIconSize(QSize(60,60));
            emit sigSocketSendData('[' + N + ']' + "PURPLEOFF");
            ui->pPBPurple->setChecked(false);
        }
    }
}

void Tab3ControlPannel::slotTab3RecvData(QString recvData) {
    QIcon icon;
    qDebug() << "TEST1 " << recvData;
    QSqlQuery query;
    QStringList qlist = recvData.split("@");    //@KSH_QT@LAMPON
    if(qlist[2] =="REDON")
    {
         query.exec("update rbp_db set r = 1 where name='" + qlist[1] + "'");
         qDebug() << "RED ON IN";
         ui->pPBRed->setChecked(true);
         icon.addFile(":/IotQtClient/Image/red_on.png");
         ui->pPBRed->setIcon(icon);
         ui->pPBRed->setIconSize(QSize(60,60));
    }
    else if(qlist[2] =="REDOFF")
    {
        qDebug() << "RED OFF IN";
         query.exec("update rbp_db set r = 0 where name='" + qlist[1] + "'");
         ui->pPBRed->setChecked(false);
         icon.addFile(":/IotQtClient/Image/red_off.png");
         ui->pPBRed->setIcon(icon);
         ui->pPBRed->setIconSize(QSize(60,60));
    }
    if(qlist[2] =="BLUEON")
    {
         query.exec("update rbp_db set b = 1 where name='" + qlist[1] + "'");
         ui->pPBBlue->setChecked(true);
         icon.addFile(":/IotQtClient/Image/blue_on.png");
         ui->pPBBlue->setIcon(icon);
         ui->pPBBlue->setIconSize(QSize(60,60));
    }
    else if(qlist[2] =="BLUEOFF")
    {
         query.exec("update rbp_db set b = 0 where name='" + qlist[1] + "'");
         ui->pPBBlue->setChecked(false);
         icon.addFile(":/IotQtClient/Image/blue_off.png");
         ui->pPBBlue->setIcon(icon);
         ui->pPBBlue->setIconSize(QSize(60,60));
    }
    if(qlist[2] =="PURPLEON")
    {
         query.exec("update rbp_db set p = 1 where name='" + qlist[1] + "'");
         ui->pPBPurple->setChecked(true);
         icon.addFile(":/IotQtClient/Image/purple_on.png");
         ui->pPBPurple->setIcon(icon);
         ui->pPBPurple->setIconSize(QSize(60,60));
    }
    else if(qlist[2] =="PURPLEOFF")
    {
         query.exec("update rbp_db set p = 0 where name='" + qlist[1] + "'");
 //        query.exec("update rbp_db set p = 0 where name'" + qlist[1] + "'");
         ui->pPBPurple->setChecked(false);
         icon.addFile(":/IotQtClient/Image/purple_off.png");
         ui->pPBPurple->setIcon(icon);
         ui->pPBPurple->setIconSize(QSize(60,60));
    }
}
// name r b p
Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}
