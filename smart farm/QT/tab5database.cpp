#include "tab5database.h"
#include "ui_tab5database.h"

Tab5DataBase::Tab5DataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab5DataBase)
{
    ui->setupUi(this);
    connect(ui->pPBsearchDb,SIGNAL(clicked()),this,SLOT(slotSearchDb()));
    connect(ui->pPBdeleteDb,SIGNAL(clicked()),this,SLOT(slotDeleteDb()));
}
void Tab5DataBase::slotSearchDb() {
    QSqlQuery query;
    QDateTime to_datetime = ui->pDateTimeEditTo->dateTime();
    QString to_str = to_datetime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime from_datetime = ui->pDateTimeEditFrom->dateTime();
    QString from_str = from_datetime.toString("yyyy/MM/dd hh:mm:ss");
    QString name, temp, date_time;

    int row_count = 0;

    ui->tableWidget->clearContents();
    if(query.exec("select * from temp_db where date>'" + to_str + "' AND date<'" + from_str + "'")){
        qDebug() << query.lastQuery();
        while(query.next()){
            row_count++;
            ui->tableWidget->setRowCount(row_count);
            QTableWidgetItem *id = new QTableWidgetItem();
            QTableWidgetItem *name = new QTableWidgetItem();
            QTableWidgetItem *date = new QTableWidgetItem();
            QTableWidgetItem *toyang = new QTableWidgetItem();
            QTableWidgetItem *temp = new QTableWidgetItem();
            QTableWidgetItem *humi = new QTableWidgetItem();
            QTableWidgetItem *co2 = new QTableWidgetItem();
            QTableWidgetItem *tvoc = new QTableWidgetItem();

            id->setText(query.value("id").toString());
            name->setText(query.value("name").toString());
            date->setText(query.value("date").toString());
            toyang->setText(query.value("toyang").toString());
            temp->setText(query.value("temp").toString());
            humi->setText(query.value("humi").toString());
            co2->setText(query.value("co2").toString());
            tvoc->setText(query.value("tvoc").toString());

     //      qDebug() << "id " << id->text() << "name " << name->text() << " temp " << temp->text() << " date " << date->text();
           ui->tableWidget->setItem(row_count-1, 0, id);
           ui->tableWidget->setItem(row_count-1, 1, name);
           ui->tableWidget->setItem(row_count-1, 2, date);
           ui->tableWidget->setItem(row_count-1, 3, toyang);
           ui->tableWidget->setItem(row_count-1, 4, temp);
           ui->tableWidget->setItem(row_count-1, 5, humi);
           ui->tableWidget->setItem(row_count-1, 6, co2);
           ui->tableWidget->setItem(row_count-1, 7, tvoc);
        }
    }
}
void Tab5DataBase::slotDeleteDb() {
    QSqlQuery query;
    QDateTime to_datetime = ui->pDateTimeEditTo->dateTime();
    QString to_str = to_datetime.toString("yy/MM/dd hh:mm:ss");
    QDateTime from_datetime = ui->pDateTimeEditFrom->dateTime();
    QString from_str = from_datetime.toString("yy/MM/dd hh:mm:ss");
    QString temp, date_time;
    if(query.exec("delete from temp_db where date>'" + to_str + "' AND date<'" + from_str + "'")){
    }
}
Tab5DataBase::~Tab5DataBase()
{
    delete ui;
}
