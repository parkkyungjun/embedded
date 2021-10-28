#ifndef TAB7CONTROL_H
#define TAB7CONTROL_H

#include <QWidget>

namespace Ui {
class tab7control;
}

class tab7control : public QWidget
{
    Q_OBJECT

public:
    explicit tab7control(QWidget *parent = nullptr);
    ~tab7control();

private:
    Ui::tab7control *ui;
signals:
    void sigSocketSendData(QString);
private slots:
    void slotRedOnOff(bool);
    void slotBlueOnOff(bool);
    void slotPurpleOnOff(bool);
    void slotTab7RecvData(QString);
};

#endif // TAB7CONTROL_H
