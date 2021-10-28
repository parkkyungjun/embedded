#include "tab1devcontrol.h"
#include "ui_tab1devcontrol.h"

#define STR_CON(y) #y
#define CAT_STR(x,y) x##STR_CON(y)

Tab1DevControl::Tab1DevControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1DevControl)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);
    connect(pQTimer, SIGNAL(timeout()),this,SLOT(slotSetValueDial()));
    connect(ui->pPBtimerStart,SIGNAL(clicked(bool)),this, SLOT(slotTimerStart(bool)));
    connect(ui->pCBtimerValue,SIGNAL(currentIndexChanged(QString)),this,SLOT(slotTimerValueChange(QString)));
    connect(ui->pPBappQuit, SIGNAL(clicked()),qApp,SLOT(quit()));

}
void Tab1DevControl::slotTimerStart(bool check) {
    if(check) {
        QString strValue = ui->pCBtimerValue->currentText();
        int timerValue = strValue.toInt();
        pQTimer->start(timerValue);
        ui->pPBtimerStart->setText("Timer Stop");
    } else {
        pQTimer->stop();
        ui->pPBtimerStart->setText("Timer Start");
    }
}
void Tab1DevControl::slotSetValueDial() {
    int value = ui->pDialLed->value();
    if(value >= ui->pDialLed->maximum()) {
        value = 0;
        ui->pDialLed->setValue(value);
    }
    else
        ui->pDialLed->setValue(++value);
}
void Tab1DevControl::slotTimerValueChange(QString strValue) {
    if(pQTimer->isActive()) {
        pQTimer->stop();
        pQTimer->start(strValue.toInt());
    }
}
void Tab1DevControl::slotKeyCheckBoxUpdate(int key) {
    static int lcdData = 0;
    lcdData ^= (0x01 << (key-1));

    ui->pLcdNumberKey->display(lcdData);
    if(key == 1) {
        if(ui->pCBkey1->isChecked())
            ui->pCBkey1->setChecked(false);
        else
            ui->pCBkey1->setChecked(true);
    } else if(key == 2) {
        if(ui->pCBkey2->isChecked())
            ui->pCBkey2->setChecked(false);
        else
            ui->pCBkey2->setChecked(true);
    } else if(key == 3) {
        if(ui->pCBkey3->isChecked())
            ui->pCBkey3->setChecked(false);
        else
            ui->pCBkey3->setChecked(true);
    }else if(key == 4) {
        if(ui->pCBkey4->isChecked())
            ui->pCBkey4->setChecked(false);
        else
            ui->pCBkey4->setChecked(true);
    }else if(key == 5) {
        if(ui->pCBkey5->isChecked())
            ui->pCBkey5->setChecked(false);
        else
            ui->pCBkey5->setChecked(true);
    }else if(key == 6) {
        if(ui->pCBkey6->isChecked())
            ui->pCBkey6->setChecked(false);
        else
            ui->pCBkey6->setChecked(true);
    }else if(key == 7) {
        if(ui->pCBkey7->isChecked())
            ui->pCBkey7->setChecked(false);
        else
            ui->pCBkey7->setChecked(true);
    }
    else if(key == 8) {   //
        if(ui->pCBkey8->isChecked())
            ui->pCBkey8->setChecked(false);
        else
            ui->pCBkey8->setChecked(true);
    }
}
Keyled* Tab1DevControl::getpKeyled() {
    return pKeyled;
}
Tab1DevControl::~Tab1DevControl()
{
    delete ui;
}
