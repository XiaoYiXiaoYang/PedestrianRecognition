#pragma once

#include <QWidget>
#include "ui_snapcard.h"
#include"data.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class SnapCard : public QWidget
{
	Q_OBJECT

public:
	SnapCard(QWidget *parent = Q_NULLPTR);
	~SnapCard();

	void initUi();
	void setControlStyle();
	void setCardData(SnapData &snapData);
	
private:

	Ui::SnapCard *ui;
};
