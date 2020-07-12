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

/*��С����  �������
��Ƶ�б�
��Ƶ��ȼӴ�
����Ӵ֣����廻һ��
��Ƶ�б����
����б��߿���ұ���ͬ������
��ť�ļ�ͼ�껻Сһ��
��ѯ �ٴβ�ѯ��bug
s
*/
