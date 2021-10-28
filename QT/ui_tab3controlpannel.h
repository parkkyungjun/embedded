/********************************************************************************
** Form generated from reading UI file 'tab3controlpannel.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB3CONTROLPANNEL_H
#define UI_TAB3CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab3ControlPannel
{
public:
    QPushButton *pPBRed;
    QPushButton *pPBBlue;
    QPushButton *pPBPurple;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *pLEName;
    QPushButton *pPBName;

    void setupUi(QWidget *Tab3ControlPannel)
    {
        if (Tab3ControlPannel->objectName().isEmpty())
            Tab3ControlPannel->setObjectName(QString::fromUtf8("Tab3ControlPannel"));
        Tab3ControlPannel->resize(540, 345);
        pPBRed = new QPushButton(Tab3ControlPannel);
        pPBRed->setObjectName(QString::fromUtf8("pPBRed"));
        pPBRed->setGeometry(QRect(170, 80, 60, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/red_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/red_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBRed->setIcon(icon);
        pPBRed->setIconSize(QSize(60, 60));
        pPBRed->setCheckable(true);
        pPBBlue = new QPushButton(Tab3ControlPannel);
        pPBBlue->setObjectName(QString::fromUtf8("pPBBlue"));
        pPBBlue->setGeometry(QRect(240, 80, 60, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/blue_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/blue_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBBlue->setIcon(icon1);
        pPBBlue->setIconSize(QSize(60, 60));
        pPBBlue->setCheckable(true);
        pPBPurple = new QPushButton(Tab3ControlPannel);
        pPBPurple->setObjectName(QString::fromUtf8("pPBPurple"));
        pPBPurple->setGeometry(QRect(310, 80, 60, 60));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IotQtClient/Image/purple_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/IotQtClient/Image/purple_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBPurple->setIcon(icon2);
        pPBPurple->setIconSize(QSize(60, 60));
        pPBPurple->setCheckable(true);
        widget = new QWidget(Tab3ControlPannel);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 190, 230, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pLEName = new QLineEdit(widget);
        pLEName->setObjectName(QString::fromUtf8("pLEName"));

        horizontalLayout->addWidget(pLEName);

        pPBName = new QPushButton(widget);
        pPBName->setObjectName(QString::fromUtf8("pPBName"));

        horizontalLayout->addWidget(pPBName);


        retranslateUi(Tab3ControlPannel);

        QMetaObject::connectSlotsByName(Tab3ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *Tab3ControlPannel)
    {
        Tab3ControlPannel->setWindowTitle(QCoreApplication::translate("Tab3ControlPannel", "Form", nullptr));
        pPBRed->setText(QString());
        pPBBlue->setText(QString());
        pPBPurple->setText(QString());
        pPBName->setText(QCoreApplication::translate("Tab3ControlPannel", "\354\241\260\355\232\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab3ControlPannel: public Ui_Tab3ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3CONTROLPANNEL_H
