/********************************************************************************
** Form generated from reading UI file 'tab1devcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1DEVCONTROL_H
#define UI_TAB1DEVCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1DevControl
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pPBtimerStart;
    QComboBox *pCBtimerValue;
    QPushButton *pPBappQuit;
    QHBoxLayout *horizontalLayout_2;
    QDial *pDialLed;
    QLCDNumber *pLcdNumberLed;
    QProgressBar *pProgressBarLed;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *pCBkey1;
    QCheckBox *pCBkey2;
    QCheckBox *pCBkey3;
    QCheckBox *pCBkey4;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *pCBkey5;
    QCheckBox *pCBkey6;
    QCheckBox *pCBkey7;
    QCheckBox *pCBkey8;
    QLCDNumber *pLcdNumberKey;

    void setupUi(QWidget *Tab1DevControl)
    {
        if (Tab1DevControl->objectName().isEmpty())
            Tab1DevControl->setObjectName(QString::fromUtf8("Tab1DevControl"));
        Tab1DevControl->resize(540, 345);
        verticalLayout_3 = new QVBoxLayout(Tab1DevControl);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 4, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pPBtimerStart = new QPushButton(Tab1DevControl);
        pPBtimerStart->setObjectName(QString::fromUtf8("pPBtimerStart"));
        pPBtimerStart->setCheckable(true);

        horizontalLayout->addWidget(pPBtimerStart);

        pCBtimerValue = new QComboBox(Tab1DevControl);
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->setObjectName(QString::fromUtf8("pCBtimerValue"));

        horizontalLayout->addWidget(pCBtimerValue);

        pPBappQuit = new QPushButton(Tab1DevControl);
        pPBappQuit->setObjectName(QString::fromUtf8("pPBappQuit"));

        horizontalLayout->addWidget(pPBappQuit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pDialLed = new QDial(Tab1DevControl);
        pDialLed->setObjectName(QString::fromUtf8("pDialLed"));
        pDialLed->setMaximum(15);
        pDialLed->setPageStep(3);
        pDialLed->setWrapping(false);
        pDialLed->setNotchesVisible(true);

        horizontalLayout_2->addWidget(pDialLed);

        pLcdNumberLed = new QLCDNumber(Tab1DevControl);
        pLcdNumberLed->setObjectName(QString::fromUtf8("pLcdNumberLed"));
        pLcdNumberLed->setDigitCount(1);
        pLcdNumberLed->setMode(QLCDNumber::Hex);

        horizontalLayout_2->addWidget(pLcdNumberLed);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pProgressBarLed = new QProgressBar(Tab1DevControl);
        pProgressBarLed->setObjectName(QString::fromUtf8("pProgressBarLed"));
        pProgressBarLed->setMaximum(15);
        pProgressBarLed->setValue(-1);

        verticalLayout_2->addWidget(pProgressBarLed);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pCBkey1 = new QCheckBox(Tab1DevControl);
        pCBkey1->setObjectName(QString::fromUtf8("pCBkey1"));

        horizontalLayout_3->addWidget(pCBkey1);

        pCBkey2 = new QCheckBox(Tab1DevControl);
        pCBkey2->setObjectName(QString::fromUtf8("pCBkey2"));

        horizontalLayout_3->addWidget(pCBkey2);

        pCBkey3 = new QCheckBox(Tab1DevControl);
        pCBkey3->setObjectName(QString::fromUtf8("pCBkey3"));

        horizontalLayout_3->addWidget(pCBkey3);

        pCBkey4 = new QCheckBox(Tab1DevControl);
        pCBkey4->setObjectName(QString::fromUtf8("pCBkey4"));

        horizontalLayout_3->addWidget(pCBkey4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pCBkey5 = new QCheckBox(Tab1DevControl);
        pCBkey5->setObjectName(QString::fromUtf8("pCBkey5"));

        horizontalLayout_4->addWidget(pCBkey5);

        pCBkey6 = new QCheckBox(Tab1DevControl);
        pCBkey6->setObjectName(QString::fromUtf8("pCBkey6"));

        horizontalLayout_4->addWidget(pCBkey6);

        pCBkey7 = new QCheckBox(Tab1DevControl);
        pCBkey7->setObjectName(QString::fromUtf8("pCBkey7"));

        horizontalLayout_4->addWidget(pCBkey7);

        pCBkey8 = new QCheckBox(Tab1DevControl);
        pCBkey8->setObjectName(QString::fromUtf8("pCBkey8"));

        horizontalLayout_4->addWidget(pCBkey8);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        pLcdNumberKey = new QLCDNumber(Tab1DevControl);
        pLcdNumberKey->setObjectName(QString::fromUtf8("pLcdNumberKey"));
        pLcdNumberKey->setDigitCount(2);
        pLcdNumberKey->setMode(QLCDNumber::Hex);

        horizontalLayout_5->addWidget(pLcdNumberKey);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 2);

        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Tab1DevControl);
        QObject::connect(pDialLed, SIGNAL(valueChanged(int)), pProgressBarLed, SLOT(setValue(int)));
        QObject::connect(pDialLed, SIGNAL(valueChanged(int)), pLcdNumberLed, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Tab1DevControl);
    } // setupUi

    void retranslateUi(QWidget *Tab1DevControl)
    {
        Tab1DevControl->setWindowTitle(QCoreApplication::translate("Tab1DevControl", "Form", nullptr));
        pPBtimerStart->setText(QCoreApplication::translate("Tab1DevControl", "Timer Start", nullptr));
        pCBtimerValue->setItemText(0, QCoreApplication::translate("Tab1DevControl", "100", nullptr));
        pCBtimerValue->setItemText(1, QCoreApplication::translate("Tab1DevControl", "500", nullptr));
        pCBtimerValue->setItemText(2, QCoreApplication::translate("Tab1DevControl", "1000", nullptr));
        pCBtimerValue->setItemText(3, QCoreApplication::translate("Tab1DevControl", "2000", nullptr));

        pPBappQuit->setText(QCoreApplication::translate("Tab1DevControl", "Quit", nullptr));
        pCBkey1->setText(QCoreApplication::translate("Tab1DevControl", "1", nullptr));
        pCBkey2->setText(QCoreApplication::translate("Tab1DevControl", "2", nullptr));
        pCBkey3->setText(QCoreApplication::translate("Tab1DevControl", "3", nullptr));
        pCBkey4->setText(QCoreApplication::translate("Tab1DevControl", "4", nullptr));
        pCBkey5->setText(QCoreApplication::translate("Tab1DevControl", "5", nullptr));
        pCBkey6->setText(QCoreApplication::translate("Tab1DevControl", "6", nullptr));
        pCBkey7->setText(QCoreApplication::translate("Tab1DevControl", "7", nullptr));
        pCBkey8->setText(QCoreApplication::translate("Tab1DevControl", "8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1DevControl: public Ui_Tab1DevControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1DEVCONTROL_H
