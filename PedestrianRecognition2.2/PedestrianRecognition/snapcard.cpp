#include "snapcard.h"

SnapCard::SnapCard(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::SnapCard)
{
	ui->setupUi(this);
	initUi();
	setControlStyle();
}

SnapCard::~SnapCard()
{
	delete ui;
}

void SnapCard::initUi()
{
	ui->snappic->setAlignment(Qt::AlignCenter);
	ui->srcVedioNameLabel->setAlignment(Qt::AlignCenter);
	ui->timeLabel->setAlignment(Qt::AlignCenter);
}

void SnapCard::setControlStyle()
{
	ui->snappic->setObjectName("labelSnapPic");
	ui->btnsrc->setObjectName("btnSrc");
	ui->btntime->setObjectName("btnTime");
}

void SnapCard::setCardData(SnapData &snapData)
{
	Mat ImgShow = snapData.m_littleFile.clone();
	QImage qimg = MatToQImage::cvMat2QImage(ImgShow);

	QPixmap qpixmap = QPixmap::fromImage(qimg);
	qpixmap = qpixmap.scaled(ui->snappic->size(), Qt::KeepAspectRatio);
	ui->snappic->setPixmap(qpixmap);						/*ͼƬ*/

	ui->srcVedioNameLabel->setText(snapData.m_srcVedioName);/*Դ*/
	ui->timeLabel->setText(snapData.m_currentTime.toString("yyyy-MM-dd hh:mm:ss"));			/*ʱ��*/
}


