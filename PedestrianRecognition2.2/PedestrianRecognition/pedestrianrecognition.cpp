#include "pedestrianrecognition.h"

PedestrianRecognition::PedestrianRecognition(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::PedestrianRecognitionClass)
{
	ui->setupUi(this);
	
	initUI();
}
PedestrianRecognition::~PedestrianRecognition()
{
	delete ui;
}

void PedestrianRecognition::initUI()
{
	ui->tabWidget->setCurrentIndex(0);   /*Ĭ����ʾ��һҳ*/
}
void PedestrianRecognition::connectEvent()
{

}

void PedestrianRecognition::setControlStyle()
{

}


