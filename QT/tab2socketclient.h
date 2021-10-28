#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H
/* kccistc embedded & iot by ksh */
#include <QWidget>
#include <QTime>
#include "socketclient.h"
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDateTimeAxis>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();

private:
    Ui::Tab2SocketClient *ui;
    SocketClient* pSocketClient;
    int iNewLedNo = 0;
    QSqlDatabase sqlDb;
signals:
    void sigLedWrite(int);
    void sigTab3RecvData(QString);
    void sigTab4RecvData(QString);
private slots:
    void slotConnectToServer(bool);
    void slotSocketRecvUpdate(QString);
    void slotSocketSendData();
public slots:
    void slotSocketSendData(QString);
};

#endif // TAB2SOCKETCLIENT_H
