#pragma once
#include<QString>
#include<QDatetime>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMetaType>
#include<QListWidgetItem>
#include<QTableWidgetItem>

using namespace cv;

#define VIDEO_PATH "../../video"
#define SVM_XML_NAME "./xml/SVM_HOG.xml"

class VideoItem
{
public:
	VideoItem();
	VideoItem(QString filename,QString filepath);
	bool isEmpty();

	QString m_fileName;
	QString m_filePath;
};


class SnapData
{
public:
	SnapData();
	SnapData(Mat littleFile, Mat bigFile,QString srcVedioName,QDateTime currentTime);
	bool isEmpty();

	Mat m_littleFile;
	Mat m_bigFile;
	QString m_srcVedioName;
	QDateTime m_currentTime;
};

class PersonItem
{
public:
	PersonItem();
	PersonItem(QString littleFile, QString bigFile, QString srcVedioName, QDateTime currentTime);
	bool isEmpty();

	QString m_littleFile;
	QString m_bigFile;
	QString m_srcVedioName;
	QDateTime m_currentTime;
};

class CustomWidgetItem :public QListWidgetItem,public QTableWidgetItem
{
public:
	CustomWidgetItem(SnapData data, QListWidgetItem *parent1 = nullptr, QTableWidgetItem *parent2 = nullptr);
	~CustomWidgetItem();
	SnapData getItem();

private:
	SnapData m_snapData;
};

class MatToQImage
{
public:
	static QImage cvMat2QImage(const Mat& mat);
};