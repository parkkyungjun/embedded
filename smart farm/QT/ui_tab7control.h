/********************************************************************************
** Form generated from reading UI file 'tab7control.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB7CONTROL_H
#define UI_TAB7CONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab7control
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pPBRed;
    QPushButton *pPBBlue;
    QPushButton *pPBPurple;

    void setupUi(QWidget *tab7control)
    {
        if (tab7control->objectName().isEmpty())
            tab7control->setObjectName(QString::fromUtf8("tab7control"));
        tab7control->resize(540, 345);
        scrollArea = new QScrollArea(tab7control);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 543, 408));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 541, 406));
        pPBRed = new QPushButton(scrollAreaWidgetContents);
        pPBRed->setObjectName(QString::fromUtf8("pPBRed"));
        pPBRed->setGeometry(QRect(380, 40, 61, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/red_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/red_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBRed->setIcon(icon);
        pPBRed->setIconSize(QSize(60, 60));
        pPBRed->setCheckable(true);
        pPBBlue = new QPushButton(scrollAreaWidgetContents);
        pPBBlue->setObjectName(QString::fromUtf8("pPBBlue"));
        pPBBlue->setGeometry(QRect(390, 130, 61, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/blue_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/blue_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBBlue->setIcon(icon1);
        pPBBlue->setIconSize(QSize(60, 60));
        pPBBlue->setCheckable(true);
        pPBPurple = new QPushButton(scrollAreaWidgetContents);
        pPBPurple->setObjectName(QString::fromUtf8("pPBPurple"));
        pPBPurple->setGeometry(QRect(380, 220, 61, 61));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IotQtClient/Image/purple_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/IotQtClient/Image/purple_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBPurple->setIcon(icon2);
        pPBPurple->setIconSize(QSize(60, 60));
        pPBPurple->setCheckable(true);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(tab7control);

        QMetaObject::connectSlotsByName(tab7control);
    } // setupUi

    void retranslateUi(QWidget *tab7control)
    {
        tab7control->setWindowTitle(QCoreApplication::translate("tab7control", "Form", nullptr));
        pPBRed->setText(QString());
        pPBBlue->setText(QString());
        pPBPurple->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tab7control: public Ui_tab7control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB7CONTROL_H
