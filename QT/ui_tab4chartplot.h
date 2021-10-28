/********************************************************************************
** Form generated from reading UI file 'tab4chartplot.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB4CHARTPLOT_H
#define UI_TAB4CHARTPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab4ChartPlot
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pDateTimeEditTo;
    QDateTimeEdit *pDateTimeEditFrom;
    QLineEdit *pLEName;
    QPushButton *pPBAddButton;
    QPushButton *pPBClearButton;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Tab4ChartPlot)
    {
        if (Tab4ChartPlot->objectName().isEmpty())
            Tab4ChartPlot->setObjectName(QString::fromUtf8("Tab4ChartPlot"));
        Tab4ChartPlot->resize(591, 345);
        verticalLayout_2 = new QVBoxLayout(Tab4ChartPlot);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pDateTimeEditTo = new QDateTimeEdit(Tab4ChartPlot);
        pDateTimeEditTo->setObjectName(QString::fromUtf8("pDateTimeEditTo"));
        pDateTimeEditTo->setDateTime(QDateTime(QDate(2021, 9, 29), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pDateTimeEditTo);

        pDateTimeEditFrom = new QDateTimeEdit(Tab4ChartPlot);
        pDateTimeEditFrom->setObjectName(QString::fromUtf8("pDateTimeEditFrom"));
        pDateTimeEditFrom->setDateTime(QDateTime(QDate(2021, 12, 31), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pDateTimeEditFrom);

        pLEName = new QLineEdit(Tab4ChartPlot);
        pLEName->setObjectName(QString::fromUtf8("pLEName"));

        horizontalLayout->addWidget(pLEName);

        pPBAddButton = new QPushButton(Tab4ChartPlot);
        pPBAddButton->setObjectName(QString::fromUtf8("pPBAddButton"));

        horizontalLayout->addWidget(pPBAddButton);

        pPBClearButton = new QPushButton(Tab4ChartPlot);
        pPBClearButton->setObjectName(QString::fromUtf8("pPBClearButton"));

        horizontalLayout->addWidget(pPBClearButton);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 3);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        retranslateUi(Tab4ChartPlot);

        QMetaObject::connectSlotsByName(Tab4ChartPlot);
    } // setupUi

    void retranslateUi(QWidget *Tab4ChartPlot)
    {
        Tab4ChartPlot->setWindowTitle(QCoreApplication::translate("Tab4ChartPlot", "Form", nullptr));
        pLEName->setText(QString());
        pPBAddButton->setText(QCoreApplication::translate("Tab4ChartPlot", "\354\241\260\355\232\214", nullptr));
        pPBClearButton->setText(QCoreApplication::translate("Tab4ChartPlot", "\354\202\255\354\240\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab4ChartPlot: public Ui_Tab4ChartPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB4CHARTPLOT_H
