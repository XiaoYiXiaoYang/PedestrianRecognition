/********************************************************************************
** Form generated from reading UI file 'pedestrianrecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDESTRIANRECOGNITION_H
#define UI_PEDESTRIANRECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "persondata.h"
#include "realtimerecognition.h"

QT_BEGIN_NAMESPACE

class Ui_PedestrianRecognitionClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    RealTimeRecognition *widget;
    QWidget *tab2;
    PersonData *widget_2;

    void setupUi(QWidget *PedestrianRecognitionClass)
    {
        if (PedestrianRecognitionClass->objectName().isEmpty())
            PedestrianRecognitionClass->setObjectName(QString::fromUtf8("PedestrianRecognitionClass"));
        PedestrianRecognitionClass->resize(1290, 730);
        horizontalLayout = new QHBoxLayout(PedestrianRecognitionClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(PedestrianRecognitionClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        tab1->setStyleSheet(QString::fromUtf8(""));
        widget = new RealTimeRecognition(tab1);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-10, 0, 1280, 684));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        tab2->setStyleSheet(QString::fromUtf8(""));
        widget_2 = new PersonData(tab2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(-1, -1, 1280, 684));
        tabWidget->addTab(tab2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(PedestrianRecognitionClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PedestrianRecognitionClass);
    } // setupUi

    void retranslateUi(QWidget *PedestrianRecognitionClass)
    {
        PedestrianRecognitionClass->setWindowTitle(QApplication::translate("PedestrianRecognitionClass", "PedestrianRecognition", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("PedestrianRecognitionClass", "Real-Time Recognition", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("PedestrianRecognitionClass", "Pedestrian Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PedestrianRecognitionClass: public Ui_PedestrianRecognitionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDESTRIANRECOGNITION_H
