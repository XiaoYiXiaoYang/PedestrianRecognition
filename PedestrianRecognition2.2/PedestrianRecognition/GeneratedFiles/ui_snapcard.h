/********************************************************************************
** Form generated from reading UI file 'snapcard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPCARD_H
#define UI_SNAPCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnapCard
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *snappic;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnsrc;
    QLabel *srcVedioNameLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btntime;
    QLabel *timeLabel;

    void setupUi(QWidget *SnapCard)
    {
        if (SnapCard->objectName().isEmpty())
            SnapCard->setObjectName(QString::fromUtf8("SnapCard"));
        SnapCard->resize(220, 250);
        SnapCard->setMinimumSize(QSize(220, 250));
        horizontalLayout_4 = new QHBoxLayout(SnapCard);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        snappic = new QLabel(SnapCard);
        snappic->setObjectName(QString::fromUtf8("snappic"));
        snappic->setMinimumSize(QSize(120, 150));
        snappic->setMaximumSize(QSize(120, 150));

        horizontalLayout_3->addWidget(snappic);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnsrc = new QPushButton(SnapCard);
        btnsrc->setObjectName(QString::fromUtf8("btnsrc"));
        btnsrc->setMinimumSize(QSize(20, 20));
        btnsrc->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(btnsrc);

        srcVedioNameLabel = new QLabel(SnapCard);
        srcVedioNameLabel->setObjectName(QString::fromUtf8("srcVedioNameLabel"));

        horizontalLayout->addWidget(srcVedioNameLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btntime = new QPushButton(SnapCard);
        btntime->setObjectName(QString::fromUtf8("btntime"));
        btntime->setMinimumSize(QSize(18, 18));
        btntime->setMaximumSize(QSize(18, 18));

        horizontalLayout_2->addWidget(btntime);

        timeLabel = new QLabel(SnapCard);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        horizontalLayout_2->addWidget(timeLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(SnapCard);

        QMetaObject::connectSlotsByName(SnapCard);
    } // setupUi

    void retranslateUi(QWidget *SnapCard)
    {
        SnapCard->setWindowTitle(QApplication::translate("SnapCard", "SnapCard", nullptr));
        snappic->setText(QString());
        btnsrc->setText(QString());
        srcVedioNameLabel->setText(QString());
        btntime->setText(QString());
        timeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SnapCard: public Ui_SnapCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPCARD_H
