#ifndef TAB5DATABASE_H
#define TAB5DATABASE_H
/* kccistc embedded & iot by ksh */
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>
namespace Ui {
class Tab5DataBase;
}

class Tab5DataBase : public QWidget
{
    Q_OBJECT

public:
    explicit Tab5DataBase(QWidget *parent = nullptr);
    ~Tab5DataBase();

private:
    Ui::Tab5DataBase *ui;
    QSqlDatabase sqlDb;
private slots:
    void slotSearchDb();
    void slotDeleteDb();
};

#endif // TAB5DATABASE_H
