#include "pedestrianrecognition.h"
#include <QtWidgets/QApplication>
#include <QMetaType>
#include<QListView>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/*注册信号槽传递数据类型*/
	qRegisterMetaType<Mat>("Mat");
	qRegisterMetaType<Mat>("Mat&");
	qRegisterMetaType<SnapData>("SnapData");
	qRegisterMetaType<SnapData>("SnapData&");

	/*qss文件加载*/
	QString qss;
	QFile qssFile("./qss/myQss.qss");
	qssFile.open(QFile::ReadOnly);

	if (qssFile.isOpen())
	{
		qss = QLatin1String(qssFile.readAll());
		qApp->setStyleSheet(qss);
		qssFile.close();
	}


	/*翻译文件加载*/
	QTranslator *translator = new QTranslator;
	translator->load("./language/pedestrianrecognition_zh.qm");
	qApp->installTranslator(translator);

	PedestrianRecognition w;
	w.show();

	return a.exec();
}


