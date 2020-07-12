#pragma once

#include <QWidget>
#include "ui_realtimerecognition.h"
#include<qdir.h>
#include"data.h"
#include"snapcard.h"
#include<listmodelex.h>
#include<qdebug.h>
#include<qstringlistmodel.h>
#include<qfiledialog.h>
#include"vibe.h"
#include"process.h"
#include"snapdatadetail.h"

#include <QMetaType>



class RealTimeRecognition : public QWidget
{
	Q_OBJECT

public:
	RealTimeRecognition(QWidget *parent = Q_NULLPTR);
	~RealTimeRecognition();

	void initUI();
	void connectEvent();
	void setControlStyle();
	void selectVideo();
	
signals:
	void showProcessFrame(Mat &frame);
	void showNewPerson(SnapData &snap);
	void showErrorMsg(QString &strError);
private slots:
	void slotBtnOpenFileClick();
	void slotBtnOpenCameraClick();
	void slotShowProcessFrame(Mat &frameImg);
	void slotShowNewPerson(SnapData &snapPerson);
	void slotShowItemDetail(QListWidgetItem *);
	void slotBtnPauseClick(bool checked);
	void slotBtnFullScreenClick(bool checked);
	void slotBtnStopClick(bool checked);
	void slotListItemClick(const QModelIndex &index);
	void slotShowErrorMsg(QString &strError);
private:

	Ui::RealTimeRecognition *ui;
	Process *process;					/*图像处理子线程*/
	QList<VideoItem> m_videoItemList;    /*视频文件列表*/
	SnapDataDetail *m_snapDetailDlg;     /*详情对话框指针*/

};
