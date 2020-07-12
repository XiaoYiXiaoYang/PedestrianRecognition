#pragma once

#include <QObject>
#include<QThread>
#include<QMutex>
#include"vibe.h"
#include"data.h"
#include"dbutil.h"

class Process :public QThread
{
	Q_OBJECT

public:
	Process(QObject *parent = 0);
	~Process();

	void connectEvent();
	void GammaCorrectiom(Mat src, int iWidth, int iHeight, float fGamma, Mat &dst);
	void BuildTable(float fPrecompensation);
	void preTreat(Mat &image, Mat &result);
	Mat removeNoise(Mat foreGroundImg);
	int isPerson(Mat roi);
	Mat getPerson(Mat src, Mat foreground);
	void processMain(QString path);
	
	void setVideoItem(VideoItem vedioItem);
	void setPause();
	void setResume();
	void setStop(bool stop);
protected:
	void run();
signals:
	void showProcessFrame(Mat &frame);
	void showNewPerson(SnapData &snap);
	void showErrorMsg(QString &strMsg);
private:
	VideoItem m_vedioItem;  /**/
	int m_personNum;   /*行人个数*/
	bool m_pause; 
	bool m_stop;
	DbUtil *m_dbutil;		/*数据库工具*/
	QMutex m_mutex;			/*互斥量*/
	int m_hight = 480;		/*和QLabel的大小一致*/
	int m_width = 720;
};
