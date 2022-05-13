#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H
#include <QThread>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDate>

using namespace cv;
using namespace std;

class Cameracapture : public QThread
{
    Q_OBJECT
    void run();
    int camFlag;
    int saveFlag;
    int waitTime;
    int frameCount;
    Mat frame;
    Mat securityFrame;
    void put_string(Mat &frame, string text, Point pt, uint32_t value);
    QTimer* pQTimer;
    bool timerFlag;
public:
    explicit Cameracapture(QWidget *parent = nullptr);
    bool getCamFlag();
    void setCamFlag(bool);
    void showImage(Mat img);
    void securityProcess();
    QLabel* pTLcamView;
    void camTimerStartStop(bool);
    void camSnapshot();
    void inspectcolor();
signals:
    void sigSocketSendData(QString);
public slots:
    void slotMScounter();

};

#endif // CAMERACAPTURE_H
