#include "tab4chartplot.h"
#include "ui_tab4chartplot.h"

Tab4ChartPlot::Tab4ChartPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab4ChartPlot)
{
    ui->setupUi(this);

    series = new QLineSeries(this);
    series2 = new QLineSeries(this);
    series3 = new QLineSeries(this);
    series->setName("토양");
    series2->setName("온도");
    series3->setName("습도");


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series2);
    chart->addSeries(series3);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,100);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->layout()->addWidget(chartView);

    axisX = new QDateTimeAxis;
    axisX->setFormat("MM-dd h:mm");


    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QDateTime latestDate;
    QDateTime firstDate;
    QTime tempTime;

    firstDate.setDate(date);
    if(time.hour() >= 23)
        tempTime.setHMS(23,59,59);
    else
        tempTime = time.addSecs(-(60*10*1));


    latestDate.setDate(date);
    firstDate.setTime(tempTime);
    latestDate.setTime(time);

    axisX->setRange(firstDate,latestDate);

    chartView->chart()->setAxisX(axisX, series);;
    chartView->chart()->setAxisX(axisX, series2);;
    chartView->chart()->setAxisX(axisX, series3);;

    connect(ui->pPBClearButton,SIGNAL(clicked()),this, SLOT(slotChartPlotClear()));
    connect(ui->pPBAddButton,SIGNAL(clicked()),this,SLOT(slotSearchDb()));
    QString query = "CREATE TABLE temp_db ("
            "id integer primary key,"
            "name VARCHAR(10),"
            "date DATETIME,"
            "toyang VARCHAR(10),"
            "temp VARCHAR(10),"
            "humi VARCHAR(10),"
            "co2 VARCHAR(10),"
            "tvoc VARCHAR(10))";
    QSqlQuery qry;
    if(!qry.exec(query))
    {
//         qDebug() << "error creating table\n";
    } else
         qDebug() << "create table\n";

}

void Tab4ChartPlot::slotTab4RecvData(QString recvData) {

    QString name,toyang,temp,humi,co2,tvoc;
    QDateTime dateTime = QDateTime::currentDateTime();

    if(flag == 1){
        exTime = dateTime.addDays(10);
        flag = 0;
    }
    if(dateTime > exTime)
    {
        emit sigSnapShot();
        flag = 1;
    }
    QStringList qlist = recvData.split("@");    //@KSH_QT@LAMPON
    if(qlist[2] =="SENSOR") {
        name = qlist[1];
        toyang = qlist[3];
        humi = qlist[4];
        temp = qlist[5];
        co2 = qlist[6];
        tvoc = qlist[7];
        qDebug() << qlist;
    }

    QSqlQuery query;

      if(query.exec("insert into temp_db(name, date, toyang, temp, humi, co2, tvoc) values('" + name + "' , '" + dateTime.toString("yyyy/MM/dd hh:mm:ss")  + "' , '" + toyang + "' , '" + temp + "', '" + humi + "','" + co2 + "','" + tvoc + "')")){
     }
     else {
         qDebug() << query.lastError().text();
     }

}
void Tab4ChartPlot::slotSearchDb() {
    QSqlQuery query;
    QDateTime to_datetime = ui->pDateTimeEditTo->dateTime();
    QString to_str = to_datetime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime from_datetime = ui->pDateTimeEditFrom->dateTime();
    QString from_str = from_datetime.toString("yyyy/MM/dd hh:mm:ss");
    QString name = ui->pLEName->text();
    QString temp, date_time;
    series->clear();
    series2->clear();
    series3->clear();

    axisX->setRange(to_datetime,from_datetime);

    if(query.exec("select * from temp_db where date>'" + to_str + "' AND date<'" + from_str + "' AND name='" + name + "'")){
        QDateTime xValue;
        while(query.next()){
            QDateTime dt = QDateTime::fromString(query.value("date").toString(),"yyyy/MM/dd hh:mm:ss");
            series->append(dt.toMSecsSinceEpoch() , query.value("toyang").toUInt());
            series2->append(dt.toMSecsSinceEpoch() , query.value("temp").toUInt());
            series3->append(dt.toMSecsSinceEpoch() , query.value("humi").toUInt());
        }
    }
}
void Tab4ChartPlot::slotChartPlotClear() {
    series->clear();
    series2->clear();
    series3->clear();
}
Tab4ChartPlot::~Tab4ChartPlot()
{
    delete ui;
}
