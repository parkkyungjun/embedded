#include "cameracapture.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

Cameracapture::Cameracapture(QWidget *parent) :  QThread(parent)
{
    camFlag = false;
    saveFlag = false;
    timerFlag = false;
    frameCount = 0;
    waitTime = 1000; //1000mss
    pQTimer = new QTimer(this);
    connect(pQTimer, SIGNAL(timeout()),this,SLOT(slotMScounter()));
}
void Cameracapture::slotMScounter() {
    timerFlag=true;
}
void Cameracapture::camTimerStartStop(bool check) {
    if(check)
       pQTimer->start(waitTime);
    else
       pQTimer->stop();
}
void Cameracapture::run()
{
    QString text;
    VideoCapture  capture(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,480);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,360);
    if (!capture.isOpened())
    {
        cout << "카메라가 연결되지 않았습니다." << endl;
        exit(1);
    }

    while(camFlag) {
        capture.read(frame);
        put_string(frame, "count : ", Point(10, 40), frameCount++);
        cvtColor(frame, frame, COLOR_BGR2RGB);
        QImage _img(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
        pTLcamView->setPixmap(QPixmap::fromImage(_img));

        if(timerFlag)
        {
             securityProcess();
             timerFlag = false;
        }
    }
    capture.release();
    destroyWindow("카메라 영상보기");
}

void Cameracapture::put_string(Mat &frame, string text, Point pt, uint32_t value)
{
    text += to_string(value);
    Point shade = pt + Point(2, 2);
    int font = FONT_HERSHEY_SIMPLEX;
    putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);     // 그림자 효과
    putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);// 작성 문자
}

bool Cameracapture::getCamFlag()
{
    return camFlag;
}
void Cameracapture::setCamFlag(bool camFlag)
{
    this->camFlag = camFlag;
}
void Cameracapture::camSnapshot()
{
    cvtColor(frame, frame, COLOR_RGB2BGR);
    imwrite("img.jpg", frame);
    inspectcolor();
}
void Cameracapture::inspectcolor()
{
    // Create a black image with a gray rectangle on top left
    QString Name;
    Mat img = imread("img.jpg");
    Mat img_rectangle;
    img.copyTo(img_rectangle);
    rectangle(img, Rect(0, 0, 100, 100), Scalar(100), CV_FILLED);
    QDateTime dateTime = QDateTime::currentDateTime();


    // Define a polygon
    Point pts[1][4];
    pts[0][0] = Point(20, 20);
    pts[0][1] = Point(40, 100);
    pts[0][2] = Point(200, 60);
    pts[0][3] = Point(150, 30);

    Name = dateTime.toString("yy-MM-dd hh:mm:ss") + "_img_rectangle.jpg";
    rectangle(img_rectangle, Rect(Point(270, 430), Point(400, 460)), Scalar(0, 0, 255), 1,8,0);
    imwrite(Name.toStdString(),img_rectangle);
    const Point* points[1] = {pts[0]};
    int npoints = 4;

    // Create the mask with the polygon
    Mat1b mask(img.rows, img.cols, uchar(0));
    fillPoly(mask, points, &npoints, 1, Scalar(255));

    // Compute the mean with the computed mask
    Scalar average = mean(img, mask);
//    qDebug() << average;
    cout << average << endl;

}
void Cameracapture::securityProcess()
{
    int pixelCount = 0;
    if(!saveFlag)
    {
        securityFrame = frame.clone();
        saveFlag = true;
    }
    else
    {
        securityFrame = abs(securityFrame - frame);
        uchar* my_ptr = (uchar*)securityFrame.data; // v+1행 첫 칸의 주소를 불러온다.
        for(int v= 0;v<securityFrame.rows ; v++){
            for(int u = 0 ; u<securityFrame.cols; u++){
                if(my_ptr[v*securityFrame.cols + u] >=30) pixelCount++;

            }

        }
        if(pixelCount > 3072)
        {
            cvtColor(frame, frame, COLOR_RGB2BGR);
            imwrite("security.jpg", frame);
            emit sigSocketSendData("[KSH_LIN]INTRUDER");
            qDebug() << "INTRUDER " ;
         }
         saveFlag = false;
         qDebug() << securityFrame.total() << " " << pixelCount <<" " << \
                 (double)pixelCount/securityFrame.total()*100<< "%";
    }
}
