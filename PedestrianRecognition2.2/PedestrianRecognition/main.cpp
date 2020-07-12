#include "pedestrianrecognition.h"
#include <QtWidgets/QApplication>
#include <QMetaType>
#include<QListView>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/*ע���źŲ۴�����������*/
	qRegisterMetaType<Mat>("Mat");
	qRegisterMetaType<Mat>("Mat&");
	qRegisterMetaType<SnapData>("SnapData");
	qRegisterMetaType<SnapData>("SnapData&");

	/*qss�ļ�����*/
	QString qss;
	QFile qssFile("./qss/myQss.qss");
	qssFile.open(QFile::ReadOnly);

	if (qssFile.isOpen())
	{
		qss = QLatin1String(qssFile.readAll());
		qApp->setStyleSheet(qss);
		qssFile.close();
	}


	/*�����ļ�����*/
	QTranslator *translator = new QTranslator;
	translator->load("./language/pedestrianrecognition_zh.qm");
	qApp->installTranslator(translator);

	PedestrianRecognition w;
	w.show();

	return a.exec();
}


