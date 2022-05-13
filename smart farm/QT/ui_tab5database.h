/********************************************************************************
** Form generated from reading UI file 'tab5database.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB5DATABASE_H
#define UI_TAB5DATABASE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab5DataBase
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pDateTimeEditTo;
    QDateTimeEdit *pDateTimeEditFrom;
    QPushButton *pPBsearchDb;
    QPushButton *pPBdeleteDb;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Tab5DataBase)
    {
        if (Tab5DataBase->objectName().isEmpty())
            Tab5DataBase->setObjectName(QString::fromUtf8("Tab5DataBase"));
        Tab5DataBase->resize(540, 345);
        verticalLayout = new QVBoxLayout(Tab5DataBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pDateTimeEditTo = new QDateTimeEdit(Tab5DataBase);
        pDateTimeEditTo->setObjectName(QString::fromUtf8("pDateTimeEditTo"));
        pDateTimeEditTo->setDateTime(QDateTime(QDate(2021, 9, 28), QTime(0, 0, 0)));
        pDateTimeEditTo->setDate(QDate(2021, 9, 28));

        horizontalLayout->addWidget(pDateTimeEditTo);

        pDateTimeEditFrom = new QDateTimeEdit(Tab5DataBase);
        pDateTimeEditFrom->setObjectName(QString::fromUtf8("pDateTimeEditFrom"));
        pDateTimeEditFrom->setDateTime(QDateTime(QDate(2021, 10, 30), QTime(12, 0, 0)));
        pDateTimeEditFrom->setDate(QDate(2021, 10, 30));
        pDateTimeEditFrom->setMinimumDateTime(QDateTime(QDate(1752, 9, 15), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pDateTimeEditFrom);

        pPBsearchDb = new QPushButton(Tab5DataBase);
        pPBsearchDb->setObjectName(QString::fromUtf8("pPBsearchDb"));

        horizontalLayout->addWidget(pPBsearchDb);

        pPBdeleteDb = new QPushButton(Tab5DataBase);
        pPBdeleteDb->setObjectName(QString::fromUtf8("pPBdeleteDb"));

        horizontalLayout->addWidget(pPBdeleteDb);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(Tab5DataBase);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setColumnCount(8);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(21);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(Tab5DataBase);

        QMetaObject::connectSlotsByName(Tab5DataBase);
    } // setupUi

    void retranslateUi(QWidget *Tab5DataBase)
    {
        Tab5DataBase->setWindowTitle(QCoreApplication::translate("Tab5DataBase", "Form", nullptr));
        pPBsearchDb->setText(QCoreApplication::translate("Tab5DataBase", "\354\241\260\355\232\214", nullptr));
        pPBdeleteDb->setText(QCoreApplication::translate("Tab5DataBase", "\354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Tab5DataBase", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Tab5DataBase", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Tab5DataBase", "\353\202\240\354\247\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Tab5DataBase", "\355\206\240\354\226\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Tab5DataBase", "\354\230\250\353\217\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Tab5DataBase", "\354\212\265\353\217\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Tab5DataBase", "CO2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Tab5DataBase", "TVOC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab5DataBase: public Ui_Tab5DataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB5DATABASE_H
