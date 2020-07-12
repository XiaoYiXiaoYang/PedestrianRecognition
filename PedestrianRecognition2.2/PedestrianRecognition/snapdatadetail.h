#pragma once

#include <QWidget>
#include "ui_snapdatadetail.h"
#include"data.h"

class SnapDataDetail : public QWidget
{
	Q_OBJECT

public:
	SnapDataDetail(QWidget *parent = Q_NULLPTR);
	~SnapDataDetail();

	void initUi();
	void setControlStyle();
	void setDetailData(SnapData &snapPerson);
private:
	Ui::SnapDataDetail *ui;
};
