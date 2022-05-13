#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"
#include "socketclient.h"

#define Kor(str)  QString::fromLocal8Bit(str)

Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    ui->pPBSendButton->setEnabled(false);
    connect(ui->pPBserverConnect,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer(bool)));
    connect(pSocketClient,SIGNAL(sigSocketRecv(QString)),this,SLOT(slotSocketRecvUpdate(QString)));
    connect(ui->pPBSendButton,SIGNAL(clicked()),this,SLOT(slotSocketSendData()));
    connect(ui->pPBRecvDataClear,SIGNAL(clicked()),ui->pTErecvData,SLOT(clear()));

    sqlDb = QSqlDatabase::addDatabase("QSQLITE");
    sqlDb.setDatabaseName("rbp.db");
    if (!QSqlDatabase::contains("my_sql_connection")) {
        if(sqlDb.open()){
            qDebug() << "success rbpDB connection\n";
        }
        else{
            qDebug() << "fail DB connection\n";
        }
    }

    QString query = "CREATE TABLE rbp_db ("
            "id integer primary key,"
            "name VARCHAR(10),"
            "r INT(10),"
            "b INT(10),"
            "p INT(10))";

    QSqlQuery qry;
    if(!qry.exec(query))
    {
//         qDebug() << "error creating table\n";
    } else
         qDebug() << "create table\n";
}

void Tab2SocketClient::slotConnectToServer(bool check) {
    bool bOk;
    QSqlQuery query;
    QString LOGID;
    if(check) {
        pSocketClient->slotConnectToServer(bOk);


        if(bOk) {
            query.exec("delete from rbp_db where name = 9");
            ui->pPBserverConnect->setText("서버종료");
            ui->pPBSendButton->setEnabled(true);
            query.exec("delete from rpb_db where name ='"+ LOGID + "'");
        } else {
            ui->pPBserverConnect->setChecked(false);
        }
    } else {
        pSocketClient->slotClosedByServer();
        ui->pPBserverConnect->setText("서버연결");
        ui->pPBSendButton->setEnabled(false);
    }
}
void Tab2SocketClient::slotSocketSendData() {
    QString strRecvId;
    QString strSendData;

    strRecvId = ui->pLERecvId->text();
    strSendData = ui->pLEsendData->text();

    if(strRecvId.isEmpty())
        strSendData = "[ALLMSG]"+strSendData;
    else
        strSendData = "["+strRecvId+"]"+strSendData;
    pSocketClient->slotSocketSendData(strSendData);
    ui->pLEsendData->clear();

}
void Tab2SocketClient::slotSocketSendData(QString strData) {
    if(ui->pPBserverConnect->isChecked()) {
        pSocketClient->slotSocketSendData(strData);
    }
}
void Tab2SocketClient::slotSocketRecvUpdate(QString strRecvData) {

    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    QSqlQuery query;
    strTime = strTime + " " + strRecvData;
    ui->pTErecvData->append(strTime);
    ui->pTErecvData->moveCursor(QTextCursor::End);

    if((strRecvData.indexOf("Already logged") != -1) || \
            (strRecvData.indexOf("Authentication Error") != -1))
        return;
    //수신포멧 : [KSH_QT]LED@1@ON
    //       @KSH_QT@LED@1@ON
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qlist = strRecvData.split("@"); //qlist[1] : 송신자ID

    if((strRecvData.indexOf("New") != -1)){
        query.exec("insert into rbp_db(name, r, b, p) values('" + qlist[3] + "',0,0,0)");
        qDebug() << qlist << "NEW";
        return;
    }

    if((strRecvData.indexOf("Disconnect ID") != -1))
        query.exec("delete from rbp_db where name ='" + qlist[1] + "'");

    if(strRecvData.indexOf("LED") != -1) {
        int iLedNo = qlist[3].toInt();

        if(qlist[4] == "ON") {
            iNewLedNo |= (0x01 << (iLedNo-1));
        } else {
            iNewLedNo &= ~(0x01 << (iLedNo-1));
        }

        emit sigLedWrite(iNewLedNo);
    }else if(((strRecvData.indexOf("RED") != -1) || (strRecvData.indexOf("BLUE") != -1) || (strRecvData.indexOf("PURPLE") != -1) ||  (strRecvData.indexOf("GAS") != -1))) {

        QStringList qlist = strRecvData.split("@");
        emit sigTab3RecvData(strRecvData);

    }else if(strRecvData.indexOf("SENSOR") != -1) {
        emit sigTab4RecvData(strRecvData);
    }

}
Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}
