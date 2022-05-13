#ifndef TAB6CAMSECURITY_H
#define TAB6CAMSECURITY_H

#include <QWidget>
#include "cameracapture.h"
namespace Ui {
class Tab6CamSecurity;
}

class Tab6CamSecurity : public QWidget
{
    Q_OBJECT

public:
    explicit Tab6CamSecurity(QWidget *parent = nullptr);
    ~Tab6CamSecurity();
    Cameracapture* pGetCameracapture();
private:
    Ui::Tab6CamSecurity *ui;
    Cameracapture* cameracapture;

private slots:
    void slotCamView(bool);
    void slotSnapShot();
    void slotSecurityMode(bool);
};

#endif // TAB6CAMSECURITY_H
