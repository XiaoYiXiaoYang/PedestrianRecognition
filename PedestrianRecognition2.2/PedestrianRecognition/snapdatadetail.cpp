#include "snapdatadetail.h"

SnapDataDetail::SnapDataDetail(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::SnapDataDetail)
{
	ui->setupUi(this);
	initUi();
	setControlStyle();
}

SnapDataDetail::~SnapDataDetail()
{
	delete ui;
}

void SnapDataDetail::initUi()
{
	ui->bigPicLabel->setAlignment(Qt::AlignCenter);
}

void SnapDataDetail::setControlStyle()
{
	ui->bigPicLabel->setObjectName("labelBigPic");
}

void SnapDataDetail::setDetailData(SnapData &snapPerson)
{
	Mat ImgShow = snapPerson.m_bigFile.clone();
	QImage qimg = MatToQImage::cvMat2QImage(ImgShow);

	QPixmap qpixmap = QPixmap::fromImage(qimg);
	QSize size = ui->bigPicLabel->size();
	qpixmap = qpixmap.scaled(size, Qt::KeepAspectRatio);
	ui->bigPicLabel->setPixmap(qpixmap);

	ui->snapCardWdt->setCardData(snapPerson);
}
