/********************************************************************************
** Form generated from reading UI file 'realtimerecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMERECOGNITION_H
#define UI_REALTIMERECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeRecognition
{
public:
    QHBoxLayout *horizontalLayout_3;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *videoLabel;
    QListView *videoListView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOpenFile;
    QPushButton *btnOpenCamera;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *showVideoLabel;
    QFrame *controlFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPause;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnFullScreen;
    QHBoxLayout *horizontalLayout_4;
    QLabel *messageLabel;
    QLabel *msgLabel;
    QListWidget *SnapListWidget;

    void setupUi(QWidget *RealTimeRecognition)
    {
        if (RealTimeRecognition->objectName().isEmpty())
            RealTimeRecognition->setObjectName(QString::fromUtf8("RealTimeRecognition"));
        RealTimeRecognition->resize(1280, 684);
        horizontalLayout_3 = new QHBoxLayout(RealTimeRecognition);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        leftFrame = new QFrame(RealTimeRecognition);
        leftFrame->setObjectName(QString::fromUtf8("leftFrame"));
        leftFrame->setStyleSheet(QString::fromUtf8("border:5px solid #CFCFCF;\n"
"border-radius:5px;"));
        verticalLayout_2 = new QVBoxLayout(leftFrame);
        verticalLayout_2->setSpacing(11);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        videoLabel = new QLabel(leftFrame);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setMinimumSize(QSize(0, 40));
        videoLabel->setStyleSheet(QString::fromUtf8("border:0px solid #000000;\n"
"border-radius:0px;\n"
"margin:10px;\n"
"font-size:20px;"));

        verticalLayout_2->addWidget(videoLabel);

        videoListView = new QListView(leftFrame);
        videoListView->setObjectName(QString::fromUtf8("videoListView"));
        videoListView->setStyleSheet(QString::fromUtf8("border:0px;"));

        verticalLayout_2->addWidget(videoListView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnOpenFile = new QPushButton(leftFrame);
        btnOpenFile->setObjectName(QString::fromUtf8("btnOpenFile"));
        btnOpenFile->setMinimumSize(QSize(32, 32));
        btnOpenFile->setMaximumSize(QSize(32, 32));
        btnOpenFile->setStyleSheet(QString::fromUtf8("border:0px;"));

        horizontalLayout->addWidget(btnOpenFile);

        btnOpenCamera = new QPushButton(leftFrame);
        btnOpenCamera->setObjectName(QString::fromUtf8("btnOpenCamera"));
        btnOpenCamera->setMinimumSize(QSize(32, 32));
        btnOpenCamera->setMaximumSize(QSize(32, 32));
        btnOpenCamera->setStyleSheet(QString::fromUtf8("border:0px;"));

        horizontalLayout->addWidget(btnOpenCamera);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(leftFrame);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        showVideoLabel = new QLabel(RealTimeRecognition);
        showVideoLabel->setObjectName(QString::fromUtf8("showVideoLabel"));
        showVideoLabel->setMinimumSize(QSize(720, 480));
        showVideoLabel->setStyleSheet(QString::fromUtf8("background-color:#8B8970;"));

        verticalLayout_3->addWidget(showVideoLabel);

        controlFrame = new QFrame(RealTimeRecognition);
        controlFrame->setObjectName(QString::fromUtf8("controlFrame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(controlFrame->sizePolicy().hasHeightForWidth());
        controlFrame->setSizePolicy(sizePolicy);
        controlFrame->setMinimumSize(QSize(0, 57));
        controlFrame->setMaximumSize(QSize(16777215, 57));
        controlFrame->setStyleSheet(QString::fromUtf8("background-color:#8B8B83;"));
        horizontalLayout_2 = new QHBoxLayout(controlFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPause = new QPushButton(controlFrame);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setMinimumSize(QSize(35, 35));
        btnPause->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(btnPause);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnStop = new QPushButton(controlFrame);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(35, 35));
        btnStop->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(btnStop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnFullScreen = new QPushButton(controlFrame);
        btnFullScreen->setObjectName(QString::fromUtf8("btnFullScreen"));
        btnFullScreen->setMinimumSize(QSize(35, 35));
        btnFullScreen->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(btnFullScreen);


        verticalLayout_3->addWidget(controlFrame);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        messageLabel = new QLabel(RealTimeRecognition);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setMaximumSize(QSize(120, 16777215));
        messageLabel->setStyleSheet(QString::fromUtf8("margin:5px;font-size:20px;"));

        horizontalLayout_4->addWidget(messageLabel);

        msgLabel = new QLabel(RealTimeRecognition);
        msgLabel->setObjectName(QString::fromUtf8("msgLabel"));
        msgLabel->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:#FF0000;"));

        horizontalLayout_4->addWidget(msgLabel);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_4);

        SnapListWidget = new QListWidget(RealTimeRecognition);
        SnapListWidget->setObjectName(QString::fromUtf8("SnapListWidget"));
        SnapListWidget->setMinimumSize(QSize(260, 0));
        SnapListWidget->setMaximumSize(QSize(240, 16777215));

        horizontalLayout_3->addWidget(SnapListWidget);


        retranslateUi(RealTimeRecognition);

        QMetaObject::connectSlotsByName(RealTimeRecognition);
    } // setupUi

    void retranslateUi(QWidget *RealTimeRecognition)
    {
        RealTimeRecognition->setWindowTitle(QApplication::translate("RealTimeRecognition", "RealTimeRecognition", nullptr));
        videoLabel->setText(QApplication::translate("RealTimeRecognition", "Videos\357\274\232", nullptr));
        btnOpenFile->setText(QString());
        btnOpenCamera->setText(QString());
        showVideoLabel->setText(QString());
        btnPause->setText(QString());
        btnStop->setText(QString());
        btnFullScreen->setText(QString());
        messageLabel->setText(QApplication::translate("RealTimeRecognition", "Error Message:", nullptr));
        msgLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RealTimeRecognition: public Ui_RealTimeRecognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMERECOGNITION_H
