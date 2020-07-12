#pragma once
#include<qtabwidget.h>
#include <QtWidgets/QWidget>
#include "ui_pedestrianrecognition.h"
#include<realtimerecognition.h>

class PedestrianRecognition : public QWidget
{
	Q_OBJECT

public:
	PedestrianRecognition(QWidget *parent = Q_NULLPTR);
	~PedestrianRecognition();

	void initUI();
	void connectEvent();
	void setControlStyle();
private:
	Ui::PedestrianRecognitionClass *ui;
};

/* 240 *320
240*360
240*360
576*720
*/

/*大小调节  调外面的
视频列表：
视频宽度加大
字体加粗，字体换一下
视频列表居中
左侧列表框边框和右边相同，靠外
按钮文件图标换小一点
查询 再次查询有bug
s
*/
