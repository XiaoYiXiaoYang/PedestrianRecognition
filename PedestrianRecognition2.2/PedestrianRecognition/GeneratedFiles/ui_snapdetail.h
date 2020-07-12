/********************************************************************************
** Form generated from reading UI file 'snapdetail.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPDETAIL_H
#define UI_SNAPDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnapDetail
{
public:

    void setupUi(QWidget *SnapDetail)
    {
        if (SnapDetail->objectName().isEmpty())
            SnapDetail->setObjectName(QString::fromUtf8("SnapDetail"));
        SnapDetail->resize(400, 300);

        retranslateUi(SnapDetail);

        QMetaObject::connectSlotsByName(SnapDetail);
    } // setupUi

    void retranslateUi(QWidget *SnapDetail)
    {
        SnapDetail->setWindowTitle(QApplication::translate("SnapDetail", "SnapDetail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnapDetail: public Ui_SnapDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPDETAIL_H
apDetail);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bigPicLabel = new QLabel(SnapDetail);
        bigPicLabel->setObjectName(QString::fromUtf8("bigPicLabel"));
        bigPicLabel->setMinimumSize(QSize(400, 250));
        bigPicLabel->setMaximumSize(QSize(400, 250));

        verticalLayout->addWidget(bigPicLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        snapCardWdt = new SnapCard(SnapDetail);
        snapCardWdt->setObjectName(QString::fromUtf8("snapCardWdt"));
        snapCardWdt->setMinimumSize(QSize(300, 250));
        snapCardWdt->setMaximumSize(QSize(300, 250));

        verticalLayout_2->addWidget(snapCardWdt);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(SnapDetail);

        QMetaObject::connectSlotsByName(SnapDetail);
    } // setupUi

    void retranslateUi(QWidget *SnapDetail)
    {
        SnapDetail->setWindowTitle(QApplication::translate("SnapDetail", "SnapDetail", nullptr));
        bigPicLabel->setText(QApplication::translate("SnapDetail", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnapDetail: public Ui_SnapDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPDETAIL_H
