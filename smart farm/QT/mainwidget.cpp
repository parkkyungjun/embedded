#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    pTab4ChartPlot = new Tab4ChartPlot(ui->pTab4);
    pTab5DataBase = new Tab5DataBase(ui->pTab5);
    pTab6CamSecurity = new Tab6CamSecurity(ui->pTab6);

    ui->tabWidget->setCurrentIndex(1);


    ui->pTab2->setLayout(pTab2SocketClient->layout());
    ui->pTab3->setLayout(pTab3ControlPannel->layout());
    ui->pTab4->setLayout(pTab4ChartPlot->layout());
    ui->pTab5->setLayout(pTab5DataBase->layout());
    ui->pTab6->setLayout(pTab6CamSecurity->layout());

//    connect(pTab2SocketClient,SIGNAL(sigLedWrite(int)),pTab1DevControl->getpKeyled(),SLOT(writeLedData(int)));
    connect(pTab3ControlPannel,SIGNAL(sigSocketSendData(QString)),pTab2SocketClient,SLOT(slotSocketSendData(QString)));
    connect(pTab2SocketClient,SIGNAL(sigTab3RecvData(QString)),pTab3ControlPannel,SLOT(slotTab3RecvData(QString)));
    connect(pTab2SocketClient,SIGNAL(sigTab4RecvData(QString)),pTab4ChartPlot,SLOT(slotTab4RecvData(QString)));
    connect(pTab6CamSecurity->pGetCameracapture(),SIGNAL(sigSocketSendData(QString)),pTab2SocketClient,SLOT(slotSocketSendData(QString)));
    connect(pTab4ChartPlot,SIGNAL(sigSnapShot()),pTab6CamSecurity,SLOT(slotSnapShot()));
    
}

MainWidget::~MainWidget()
{
    delete ui;
}


