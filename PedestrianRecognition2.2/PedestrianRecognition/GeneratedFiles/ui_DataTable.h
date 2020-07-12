/********************************************************************************
** Form generated from reading UI file 'DataTable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATATABLE_H
#define UI_DATATABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataTable
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSearch;
    QTableView *tableView;

    void setupUi(QWidget *DataTable)
    {
        if (DataTable->objectName().isEmpty())
            DataTable->setObjectName(QString::fromUtf8("DataTable"));
        DataTable->resize(1280, 684);
        verticalLayout = new QVBoxLayout(DataTable);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DataTable);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(DataTable);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout->addWidget(dateTimeEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(DataTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateTimeEdit_2 = new QDateTimeEdit(DataTable);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout->addWidget(dateTimeEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSearch = new QPushButton(DataTable);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));

        horizontalLayout->addWidget(btnSearch);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(DataTable);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(DataTable);

        QMetaObject::connectSlotsByName(DataTable);
    } // setupUi

    void retranslateUi(QWidget *DataTable)
    {
        DataTable->setWindowTitle(QApplication::translate("DataTable", "DataTable", nullptr));
        label->setText(QApplication::translate("DataTable", "Start time:", nullptr));
        label_2->setText(QApplication::translate("DataTable", "End time:", nullptr));
        btnSearch->setText(QApplication::translate("DataTable", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataTable: public Ui_DataTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATATABLE_H
