#ifndef TAB1DEVCONTROL_H
#define TAB1DEVCONTROL_H
/* kccistc embedded & iot by ksh */
#include <QWidget>
#include <QTimer>
#include <keyled.h>
namespace Ui {
class Tab1DevControl;
}

class Tab1DevControl : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1DevControl(QWidget *parent = nullptr);
    ~Tab1DevControl();
    Keyled* getpKeyled();

private:
    Ui::Tab1DevControl *ui;
    Keyled* pKeyled;
    QTimer* pQTimer;
private slots:
    void slotKeyCheckBoxUpdate(int);
    void slotTimerStart(bool);
    void slotSetValueDial();
    void slotTimerValueChange(QString);
};

#endif // TAB1DEVCONTROL_H
