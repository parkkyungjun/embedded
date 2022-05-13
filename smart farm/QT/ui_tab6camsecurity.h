/********************************************************************************
** Form generated from reading UI file 'tab6camsecurity.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB6CAMSECURITY_H
#define UI_TAB6CAMSECURITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab6CamSecurity
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pPBCamView;
    QPushButton *pPBsnapShot;
    QCheckBox *pCBsecurityMode;
    QVBoxLayout *verticalLayout;
    QLabel *pTLcamView;

    void setupUi(QWidget *Tab6CamSecurity)
    {
        if (Tab6CamSecurity->objectName().isEmpty())
            Tab6CamSecurity->setObjectName(QString::fromUtf8("Tab6CamSecurity"));
        Tab6CamSecurity->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(Tab6CamSecurity);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pPBCamView = new QPushButton(Tab6CamSecurity);
        pPBCamView->setObjectName(QString::fromUtf8("pPBCamView"));
        pPBCamView->setCheckable(true);

        horizontalLayout_2->addWidget(pPBCamView);

        pPBsnapShot = new QPushButton(Tab6CamSecurity);
        pPBsnapShot->setObjectName(QString::fromUtf8("pPBsnapShot"));

        horizontalLayout_2->addWidget(pPBsnapShot);

        pCBsecurityMode = new QCheckBox(Tab6CamSecurity);
        pCBsecurityMode->setObjectName(QString::fromUtf8("pCBsecurityMode"));

        horizontalLayout_2->addWidget(pCBsecurityMode);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pTLcamView = new QLabel(Tab6CamSecurity);
        pTLcamView->setObjectName(QString::fromUtf8("pTLcamView"));

        verticalLayout->addWidget(pTLcamView);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 9);

        retranslateUi(Tab6CamSecurity);

        QMetaObject::connectSlotsByName(Tab6CamSecurity);
    } // setupUi

    void retranslateUi(QWidget *Tab6CamSecurity)
    {
        Tab6CamSecurity->setWindowTitle(QCoreApplication::translate("Tab6CamSecurity", "Form", nullptr));
        pPBCamView->setText(QCoreApplication::translate("Tab6CamSecurity", "\354\230\201\354\203\201\353\263\264\352\270\260", nullptr));
        pPBsnapShot->setText(QCoreApplication::translate("Tab6CamSecurity", "\354\212\244\353\203\205\354\203\267", nullptr));
        pCBsecurityMode->setText(QCoreApplication::translate("Tab6CamSecurity", "Security Mode", nullptr));
        pTLcamView->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tab6CamSecurity: public Ui_Tab6CamSecurity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB6CAMSECURITY_H
