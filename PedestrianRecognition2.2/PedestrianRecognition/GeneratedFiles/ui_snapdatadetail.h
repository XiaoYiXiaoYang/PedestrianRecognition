/********************************************************************************
** Form generated from reading UI file 'snapdatadetail.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPDATADETAIL_H
#define UI_SNAPDATADETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "snapcard.h"

QT_BEGIN_NAMESPACE

class Ui_SnapDataDetail
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *bigPicLabel;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    SnapCard *snapCardWdt;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *SnapDataDetail)
    {
        if (SnapDataDetail->objectName().isEmpty())
            SnapDataDetail->setObjectName(QString::fromUtf8("SnapDataDetail"));
        SnapDataDetail->resize(1010, 560);
        horizontalLayout = new QHBoxLayout(SnapDataDetail);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(25, -1, -1, 25);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SnapDataDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 35));
        label->setMaximumSize(QSize(16777215, 35));
        label->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px"));

        verticalLayout->addWidget(label);

        bigPicLabel = new QLabel(SnapDataDetail);
        bigPicLabel->setObjectName(QString::fromUtf8("bigPicLabel"));
        bigPicLabel->setMinimumSize(QSize(720, 480));
        bigPicLabel->setMaximumSize(QSize(720, 480));

        verticalLayout->addWidget(bigPicLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(SnapDataDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 35));
        label_2->setMaximumSize(QSize(16777215, 35));
        label_2->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px"));

        verticalLayout_2->addWidget(label_2);

        snapCardWdt = new SnapCard(SnapDataDetail);
        snapCardWdt->setObjectName(QString::fromUtf8("snapCardWdt"));
        snapCardWdt->setMinimumSize(QSize(230, 250));
        snapCardWdt->setMaximumSize(QSize(300, 250));

        verticalLayout_2->addWidget(snapCardWdt);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(SnapDataDetail);

        QMetaObject::connectSlotsByName(SnapDataDetail);
    } // setupUi

    void retranslateUi(QWidget *SnapDataDetail)
    {
        SnapDataDetail->setWindowTitle(QApplication::translate("SnapDataDetail", "SnapDataDetail", nullptr));
        label->setText(QApplication::translate("SnapDataDetail", "Big image", nullptr));
        bigPicLabel->setText(QString());
        label_2->setText(QApplication::translate("SnapDataDetail", "Person Card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnapDataDetail: public Ui_SnapDataDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPDATADETAIL_H
