#ifndef TAB4CHARTPLOT_H
#define TAB4CHARTPLOT_H
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
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Tab4ChartPlot;
}

class Tab4ChartPlot : public QWidget
{
    Q_OBJECT

public:
    explicit Tab4ChartPlot(QWidget *parent = nullptr);
    ~Tab4ChartPlot();

private:
    Ui::Tab4ChartPlot *ui;
    QLineSeries *series, *series2, *series3;
    QSqlDatabase sqlDb;
    QDateTimeAxis *axisX;
    QChartView *chartView;
    int flag = 1;
    QDateTime exTime;
signals:
    void sigSnapShot();
private slots:
    void slotSearchDb();
    void slotChartPlotClear();
    void slotTab4RecvData(QString);
};

#endif // TAB4CHARTPLOT_H
