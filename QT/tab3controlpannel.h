#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H
/* kccistc embedded & iot by ksh */
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
class Tab3ControlPannel;
}

class Tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3ControlPannel(QWidget *parent = nullptr);
    ~Tab3ControlPannel();

private:
    Ui::Tab3ControlPannel *ui;
    QSqlDatabase sqlDb;
signals:
    void sigSocketSendData(QString);
private slots:
    void slotRedOnOff(bool);
    void slotBlueOnOff(bool);
    void slotPurpleOnOff(bool);
    void slotTab3RecvData(QString);
    void slotSearchName();
};

#endif // TAB3CONTROLPANNEL_H
