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
	ui->tabWidget->setCurrentIndex(0);   /*默认显示第一页*/
}
void PedestrianRecognition::connectEvent()
{

}

void PedestrianRecognition::setControlStyle()
{

}


