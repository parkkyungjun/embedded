#include "tab6camsecurity.h"
#include "ui_tab6camsecurity.h"

Tab6CamSecurity::Tab6CamSecurity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab6CamSecurity)
{
    ui->setupUi(this);
    cameracapture = new Cameracapture(this);
    cameracapture->pTLcamView = ui->pTLcamView;
    connect(ui->pPBCamView,SIGNAL(clicked(bool)), this, SLOT(slotCamView(bool)));
    connect(ui->pPBsnapShot,SIGNAL(clicked()), this, SLOT(slotSnapShot()));
    connect(ui->pCBsecurityMode,SIGNAL(clicked(bool)), this, SLOT(slotSecurityMode(bool)));
}

Tab6CamSecurity::~Tab6CamSecurity()
{
    delete ui;
}
void Tab6CamSecurity::slotCamView(bool check)
{
    if(check)  //on
    {
        if(ui->pCBsecurityMode->isChecked())
            slotSecurityMode(true);
        else
            slotSecurityMode(false);

        ui->pPBCamView->setText("영상 정지");
        if(!cameracapture->getCamFlag())
        {
            cameracapture->setCamFlag(true);
            cameracapture->start();
        }

    }
    else //off
    {
        cameracapture->camTimerStartStop(false);
        ui->pPBCamView->setText("영상 보기");
        cameracapture->setCamFlag(false);
    }
}
void Tab6CamSecurity::slotSnapShot() {

    if(ui->pPBCamView->isChecked())
        cameracapture->camSnapshot();
}
void Tab6CamSecurity::slotSecurityMode(bool check) {
    if(check) {
         cameracapture->camTimerStartStop(true);
    }
    else {
         cameracapture->camTimerStartStop(false);
    }
}

Cameracapture* Tab6CamSecurity::pGetCameracapture() {
    return cameracapture;
}
