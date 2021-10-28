#include <QDebug>
#include "keyled.h"

/* kccistc embedded & iot by ksh */

Keyled::Keyled(QWidget *parent) :
    QWidget(parent)
{
    pFile = new QFile("/dev/keyled");
    if(!pFile->open(QFile::ReadWrite | QFile::Unbuffered))
    {
        QMessageBox::information(this,"open","open fail: /dev/keyled");
        exit(1);
    }
    keyledFd = pFile->handle();
    pKeyledNotifier = new QSocketNotifier(keyledFd,QSocketNotifier::Read,this);
    QObject::connect(pKeyledNotifier, SIGNAL(activated(int)),this, SLOT(readKeyData(int)));
//    QObject::connect(this,SIGNAL(updateKeydataSig(int)),this,SLOT(writeLedData(int)));
}

Keyled::~Keyled()
{
    pFile->close();
}
void Keyled::readKeyData(int)
{
    char no=0;
    int ret = pFile->read(&no,sizeof(no));
//    qDebug() << "ledread : "<< (int)no;
    if(ret>0)
        emit updateKeydataSig((int)no);
}
void Keyled::writeLedData(int no)
{
    char led = (char)no;
//    qDebug() << "ledwrite : " <<  led;
//    printf("keyled : %d",led);
    int ret = pFile->write(&led,sizeof(led));
    if(!ret) {};
}
