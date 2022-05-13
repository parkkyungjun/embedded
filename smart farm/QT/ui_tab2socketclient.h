/********************************************************************************
** Form generated from reading UI file 'tab2socketclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2SOCKETCLIENT_H
#define UI_TAB2SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2SocketClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pPBserverConnect;
    QPushButton *pPBRecvDataClear;
    QTextEdit *pTErecvData;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pLERecvId;
    QLineEdit *pLEsendData;
    QPushButton *pPBSendButton;

    void setupUi(QWidget *Tab2SocketClient)
    {
        if (Tab2SocketClient->objectName().isEmpty())
            Tab2SocketClient->setObjectName(QString::fromUtf8("Tab2SocketClient"));
        Tab2SocketClient->resize(540, 345);
        verticalLayout_2 = new QVBoxLayout(Tab2SocketClient);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Tab2SocketClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pPBserverConnect = new QPushButton(Tab2SocketClient);
        pPBserverConnect->setObjectName(QString::fromUtf8("pPBserverConnect"));
        pPBserverConnect->setCheckable(true);

        horizontalLayout->addWidget(pPBserverConnect);

        pPBRecvDataClear = new QPushButton(Tab2SocketClient);
        pPBRecvDataClear->setObjectName(QString::fromUtf8("pPBRecvDataClear"));

        horizontalLayout->addWidget(pPBRecvDataClear);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        pTErecvData = new QTextEdit(Tab2SocketClient);
        pTErecvData->setObjectName(QString::fromUtf8("pTErecvData"));

        verticalLayout->addWidget(pTErecvData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pLERecvId = new QLineEdit(Tab2SocketClient);
        pLERecvId->setObjectName(QString::fromUtf8("pLERecvId"));

        horizontalLayout_2->addWidget(pLERecvId);

        pLEsendData = new QLineEdit(Tab2SocketClient);
        pLEsendData->setObjectName(QString::fromUtf8("pLEsendData"));

        horizontalLayout_2->addWidget(pLEsendData);

        pPBSendButton = new QPushButton(Tab2SocketClient);
        pPBSendButton->setObjectName(QString::fromUtf8("pPBSendButton"));

        horizontalLayout_2->addWidget(pPBSendButton);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 6);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Tab2SocketClient);

        QMetaObject::connectSlotsByName(Tab2SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab2SocketClient)
    {
        Tab2SocketClient->setWindowTitle(QCoreApplication::translate("Tab2SocketClient", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tab2SocketClient", "Recv Data", nullptr));
        pPBserverConnect->setText(QCoreApplication::translate("Tab2SocketClient", "\354\204\234\353\262\204\354\227\260\352\262\260", nullptr));
        pPBRecvDataClear->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240\354\202\255\354\240\234", nullptr));
        pPBSendButton->setText(QCoreApplication::translate("Tab2SocketClient", "\354\240\204\354\206\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2SocketClient: public Ui_Tab2SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2SOCKETCLIENT_H
