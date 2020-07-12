/********************************************************************************
** Form generated from reading UI file 'persondata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONDATA_H
#define UI_PERSONDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonData
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *startTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QDateTimeEdit *endTimeEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSearch;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEditPage;
    QLabel *label_3;
    QLabel *labelPageSum;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnPre;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *PersonData)
    {
        if (PersonData->objectName().isEmpty())
            PersonData->setObjectName(QString::fromUtf8("PersonData"));
        PersonData->resize(1280, 684);
        verticalLayout = new QVBoxLayout(PersonData);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PersonData);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout->addWidget(label);

        startTimeEdit = new QDateTimeEdit(PersonData);
        startTimeEdit->setObjectName(QString::fromUtf8("startTimeEdit"));

        horizontalLayout->addWidget(startTimeEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(PersonData);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout->addWidget(label_2);

        endTimeEdit = new QDateTimeEdit(PersonData);
        endTimeEdit->setObjectName(QString::fromUtf8("endTimeEdit"));

        horizontalLayout->addWidget(endTimeEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSearch = new QPushButton(PersonData);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setMinimumSize(QSize(110, 35));
        btnSearch->setMaximumSize(QSize(110, 35));
        btnSearch->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout->addWidget(btnSearch);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(PersonData);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        lineEditPage = new QLineEdit(PersonData);
        lineEditPage->setObjectName(QString::fromUtf8("lineEditPage"));
        lineEditPage->setMinimumSize(QSize(40, 0));
        lineEditPage->setMaximumSize(QSize(40, 16777215));
        lineEditPage->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout_2->addWidget(lineEditPage);

        label_3 = new QLabel(PersonData);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        labelPageSum = new QLabel(PersonData);
        labelPageSum->setObjectName(QString::fromUtf8("labelPageSum"));
        labelPageSum->setMinimumSize(QSize(80, 0));
        labelPageSum->setMaximumSize(QSize(80, 16777215));
        labelPageSum->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout_2->addWidget(labelPageSum);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btnPre = new QPushButton(PersonData);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        btnPre->setMinimumSize(QSize(110, 35));
        btnPre->setMaximumSize(QSize(110, 35));
        btnPre->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout_2->addWidget(btnPre);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnNext = new QPushButton(PersonData);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(110, 35));
        btnNext->setMaximumSize(QSize(110, 35));
        btnNext->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout_2->addWidget(btnNext);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PersonData);

        QMetaObject::connectSlotsByName(PersonData);
    } // setupUi

    void retranslateUi(QWidget *PersonData)
    {
        PersonData->setWindowTitle(QApplication::translate("PersonData", "PersonData", nullptr));
        label->setText(QApplication::translate("PersonData", "Start time:", nullptr));
        label_2->setText(QApplication::translate("PersonData", "End time:", nullptr));
        btnSearch->setText(QApplication::translate("PersonData", "Search", nullptr));
        label_3->setText(QApplication::translate("PersonData", "/", nullptr));
        labelPageSum->setText(QString());
        btnPre->setText(QApplication::translate("PersonData", "Previous", nullptr));
        btnNext->setText(QApplication::translate("PersonData", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonData: public Ui_PersonData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONDATA_H
