#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "tab2socketclient.h"
#include "tab3controlpannel.h"
#include "tab4chartplot.h"
#include "tab5database.h"
#include "tab6camsecurity.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

    Tab2SocketClient* pTab2SocketClient;
    Tab3ControlPannel* pTab3ControlPannel;
    Tab4ChartPlot* pTab4ChartPlot;
    Tab5DataBase* pTab5DataBase;
    Tab6CamSecurity* pTab6CamSecurity;


private slots:

};
#endif // MAINWIDGET_H
