#include "realtimerecognition.h"

RealTimeRecognition::RealTimeRecognition(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::RealTimeRecognition)
{
	ui->setupUi(this);
	process = new Process();
	
	initUI();
	connectEvent();
	selectVideo();

	ListModelEx *listModel = new ListModelEx(m_videoItemList);
	ui->videoListView->setModel(listModel);
}

RealTimeRecognition::~RealTimeRecognition()
{
	delete ui;
	delete process;
}
void RealTimeRecognition::initUI()
{
	ui->btnOpenFile->setToolTip(tr("Open File"));
	ui->btnOpenCamera->setToolTip(tr("Open Camera"));

	ui->btnPause->setToolTip(tr("Play/Pause"));
	ui->btnFullScreen->setToolTip(tr("Full Screen/Exit Full Screen"));
	ui->btnStop->setToolTip(tr("Stop/Start"));

	ui->btnPause->setCheckable(true);
	ui->btnFullScreen->setCheckable(true);
	ui->btnStop->setCheckable(true);

	ui->btnPause->setProperty("status","pause");
	ui->btnPause->style()->unpolish(ui->btnPause);
	ui->btnPause->style()->polish(ui->btnPause); /*���¼���qss*/

	ui->btnFullScreen->setProperty("status", "exit_full");
	ui->btnFullScreen->style()->unpolish(ui->btnFullScreen);
	ui->btnFullScreen->style()->polish(ui->btnFullScreen); /*���¼���qss*/

	ui->btnStop->setProperty("status", "stop");
	ui->btnStop->style()->unpolish(ui->btnStop);
	ui->btnStop->style()->polish(ui->btnStop);


	ui->showVideoLabel->setAlignment(Qt::AlignCenter); /*����*/

	//ui->videoListView->setSpacing(15);                   //Ϊ��ͼ���ÿؼ����
	ui->videoListView->setViewMode(QListView::ListMode); //����Itemͼ����ʾ

		//ui->SnapListWidget->setResizeMode(QListView::Adjust);   //�Զ���Ӧ����
	ui->SnapListWidget->setSortingEnabled(true);
	ui->SnapListWidget->setIconSize(QSize(220, 250));         //����ͼ���С
	ui->SnapListWidget->setViewMode(QListView::ListMode);   //������ʾͼ��ģʽ
	ui->SnapListWidget->setGridSize(QSize(220, 250));       //����item��С	
	ui->SnapListWidget->setMovement(QListView::Static);
}
void RealTimeRecognition::connectEvent()
{
	connect(ui->btnOpenFile, SIGNAL(clicked()), this, SLOT(slotBtnOpenFileClick()));
	connect(ui->btnOpenCamera, SIGNAL(clicked()), this, SLOT(slotBtnOpenCameraClick()));
	connect(ui->btnPause, SIGNAL(clicked(bool)), this, SLOT(slotBtnPauseClick(bool)));
	connect(ui->btnFullScreen, SIGNAL(clicked(bool)), this, SLOT(slotBtnFullScreenClick(bool)));
	connect(ui->btnStop, SIGNAL(clicked(bool)), this, SLOT(slotBtnStopClick(bool)));

	connect(process, SIGNAL(showProcessFrame(Mat&)), this, SLOT(slotShowProcessFrame(Mat&)));
	connect(process, SIGNAL(showNewPerson(SnapData&)), this, SLOT(slotShowNewPerson(SnapData&)));
	connect(process, SIGNAL(showErrorMsg(QString&)), this, SLOT(slotShowErrorMsg(QString&)),Qt::DirectConnection);
	connect(this, SIGNAL(showErrorMsg(QString&)), this, SLOT(slotShowErrorMsg(QString&)));

	connect(ui->videoListView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotListItemClick(const QModelIndex &)));
	connect(ui->SnapListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(slotShowItemDetail(QListWidgetItem *)));
}

/*qss ����*/
void RealTimeRecognition::setControlStyle()
{
	ui->leftFrame->setObjectName("frameLeft");
	ui->btnOpenFile->setObjectName("btnOpenFile");
	ui->btnOpenCamera->setObjectName("btnOpenCamera");

	ui->btnPause->setObjectName("btnPause");
	ui->btnFullScreen->setObjectName("btnFullScreen");
	ui->btnStop->setObjectName("btnStop");

	ui->videoLabel->setObjectName("	labelVideoHead");
	ui->showVideoLabel->setObjectName("labelShowVideo");
	ui->controlFrame->setObjectName("frameControl");
	
	ui->messageLabel->setObjectName("labelMsgHead");
	ui->msgLabel->setObjectName("labelShowMsg");
}
/*�������� ��ʼ����Ƶ�ļ�*/
void RealTimeRecognition::selectVideo()
{
	QString path = VIDEO_PATH;
	QDir *dir = new QDir(path);
	if (dir->isEmpty())
	{
		emit showErrorMsg(tr("Video dir is empty."));
		return;
	}

	QStringList filter;
	filter << "*.mp4" << "*.avi" <<"*.wmv";
	dir->setNameFilters(filter); //�����ļ�����
	QList<QFileInfo> *fileInfos = new QList<QFileInfo>(dir->entryInfoList(filter)); /*·���µ�ȫ���ļ�*/

	if (fileInfos->isEmpty())
	{
		emit showErrorMsg(tr("Video dir is empty."));
		return;
	}

	QList<VideoItem> videoItemList;
	QList<QFileInfo>::iterator it; int i = 0;
	for (it = fileInfos->begin(); it != fileInfos->end(); it++)
	{
		QString tmpPath = it->filePath();
		QString tmpFileName = it->fileName();

		VideoItem tmpItem(tmpFileName, tmpPath);
		videoItemList.append(tmpItem);
	}
	
	m_videoItemList = videoItemList;
}

/*�������� ����Ƶ�ļ�*/
void RealTimeRecognition::slotBtnOpenFileClick()
{
	QString filePath = QFileDialog::getOpenFileName(
		this,
		tr("Open a file."),
		VIDEO_PATH,
		tr("video files(*.avi *.mp4 *.wmv);;All files(*.*)"));

	QFileInfo file(filePath);
	if (!file.exists())
	{
		emit showErrorMsg(tr("This file is not exists."));
		return;
	}

	if (process->isRunning())
	{
		process->setStop(true);
		process->wait();
	}
	process->setVideoItem(VideoItem(file.fileName(),filePath));
	ui->btnPause->setProperty("status", "play");
	ui->btnPause->style()->unpolish(ui->btnPause);
	ui->btnPause->style()->polish(ui->btnPause); /*���¼���qss*/

	ui->btnStop->setProperty("status", "stop");
	ui->btnStop->style()->unpolish(ui->btnStop);
	ui->btnStop->style()->polish(ui->btnStop); /*���¼���qss*/

	process->setStop(false);
	process->start();
}

/*�������� ������ͷ*/
void RealTimeRecognition::slotBtnOpenCameraClick()
{
	if (process->isRunning())
	{
		process->setStop(true);
		process->wait();
	}
	process->setVideoItem(VideoItem("camera","camera"));/*������ͷ*/
	ui->btnPause->setProperty("status", "play");
	ui->btnPause->style()->unpolish(ui->btnPause);
	ui->btnPause->style()->polish(ui->btnPause); /*���¼���qss*/

	ui->btnStop->setProperty("status", "stop");
	ui->btnStop->style()->unpolish(ui->btnStop);
	ui->btnStop->style()->polish(ui->btnStop); /*���¼���qss*/

	process->setStop(false);
	process->start();
}

/*�������� ��ʾ��ǰ֡������*/
void RealTimeRecognition::slotShowProcessFrame(Mat &frameImg)
{
	Mat ImgShow = frameImg.clone();
	if (!ImgShow.data)
	{
		emit showErrorMsg(tr("This image is empty."));
		return;
	}
	QImage qimg = MatToQImage::cvMat2QImage(ImgShow);

	QPixmap qpixmap = QPixmap::fromImage(qimg);

	QSize size = ui->showVideoLabel->size();
	qpixmap = qpixmap.scaled(size, Qt::KeepAspectRatio);
	ui->showVideoLabel->setPixmap(qpixmap);
}

/*�������� ����listwidget����ʾ*/
void RealTimeRecognition::slotShowNewPerson(SnapData &snapPerson)
{
	QListWidgetItem* item = new QListWidgetItem();
	item->setData(Qt::DisplayRole, snapPerson.m_currentTime); /*Ψһ��*/
	CustomWidgetItem *customItem = new CustomWidgetItem(snapPerson,item);

	SnapCard *snap = new SnapCard(ui->SnapListWidget);
	snap->setCardData(snapPerson);

	ui->SnapListWidget->addItem((QListWidgetItem*)customItem);
	ui->SnapListWidget->setItemWidget((QListWidgetItem*)customItem,snap);
	ui->SnapListWidget->sortItems(Qt::DescendingOrder);

	if (ui->SnapListWidget->count() > 20)
	{
		QListWidgetItem* removeItem = ui->SnapListWidget->takeItem(ui->SnapListWidget->count() - 1);
		ui->SnapListWidget->removeItemWidget(removeItem);
		delete removeItem;
	}
}

/*�������� չʾitem����*/
void RealTimeRecognition::slotShowItemDetail(QListWidgetItem *item)
{
	CustomWidgetItem *customItem = dynamic_cast<CustomWidgetItem *>(item);
	if (nullptr == item)
	{
		emit showErrorMsg(tr("This ptr is empty."));
		return;
	}

	SnapData snap = customItem->getItem();
	if (snap.isEmpty())
	{
		emit showErrorMsg(tr("This person data is empty."));
		return;
	}

	m_snapDetailDlg = new SnapDataDetail();
	m_snapDetailDlg->setDetailData(snap);
	m_snapDetailDlg->show();
}

/*�������� ���Ż�����ͣ*/
void RealTimeRecognition::slotBtnPauseClick(bool checked)
{
	if (checked)/*��ͣ*/
	{
		process->setPause();

		ui->btnPause->setProperty("status","pause");
		ui->btnStop->setProperty("status", "start");
	}
	else
	{
		process->setResume();

		ui->btnPause->setProperty("status", "play");
		ui->btnStop->setProperty("status", "stop");
	}

	ui->btnPause->style()->unpolish(ui->btnPause);
	ui->btnPause->style()->polish(ui->btnPause); /*���¼���qss*/

	ui->btnStop->style()->unpolish(ui->btnStop);
	ui->btnStop->style()->polish(ui->btnStop); /*���¼���qss*/
}

/*�������� ȫ�����˳�ȫ��*/
void RealTimeRecognition::slotBtnFullScreenClick(bool checked)
{
	QRect rect0 = this->geometry();//��¼widgetλ�ã��ָ�ʱʹ��
	if (checked)/*ȫ��*/
	{
		ui->videoLabel->hide();
		ui->videoListView->hide();
		ui->btnOpenFile->hide();
		ui->btnOpenCamera->hide();
		ui->messageLabel->hide();
		ui->msgLabel->hide();
		ui->SnapListWidget->hide();
		//this->setWindowFlags(Qt::Window);
		this->showFullScreen();
		ui->btnFullScreen->setProperty("status", "full");
	}
	else
	{
		ui->videoLabel->show();
		ui->videoListView->show();
		ui->btnOpenFile->show();
		ui->btnOpenCamera->show();
		ui->messageLabel->show();
		ui->msgLabel->show();
		ui->SnapListWidget->show();
		//this->setWindowFlags(Qt::SubWindow);
		this->showNormal();
		ui->btnFullScreen->setProperty("status", "exit_full");
	}

	ui->btnFullScreen->style()->unpolish(ui->btnFullScreen);
	ui->btnFullScreen->style()->polish(ui->btnFullScreen);
}

/*�������� ���ֹͣ��ť*/
void RealTimeRecognition::slotBtnStopClick(bool checked)
{
	if (checked)/*ֹͣ*/
	{
		ui->showVideoLabel->clear();
		process->setStop(true);
		process->wait();
		ui->btnPause->setProperty("status", "pause");
		ui->btnStop->setProperty("status", "start");
	}
	else
	{
		ui->showVideoLabel->clear();
		process->setStop(false);
		process->start();
		ui->btnPause->setProperty("status", "play");
		ui->btnStop->setProperty("status", "stop");
	}

	ui->btnPause->style()->unpolish(ui->btnPause);
	ui->btnPause->style()->polish(ui->btnPause); /*���¼���qss*/

	ui->btnStop->style()->unpolish(ui->btnStop);
	ui->btnStop->style()->polish(ui->btnStop);		/*���¼���qss*/
}

/*�������� ����б��Item*/
void RealTimeRecognition::slotListItemClick(const QModelIndex &index)
{
	if (!index.isValid())
	{
		emit showErrorMsg(tr("This index is invalid."));
		return;
	}

	VideoItem item = m_videoItemList.at(index.row());
	if (item.isEmpty())
	{
		emit showErrorMsg(tr("This video is empty."));
		return;
	}

	if (process->isRunning())
	{
		process->setStop(true);
		process->wait();
	}

	process->setVideoItem(item);
	ui->btnPause->setProperty("status", "play");
	ui->btnPause->style()->unpolish(ui->btnPause);
	ui->btnPause->style()->polish(ui->btnPause); /*���¼���qss*/

	ui->btnStop->setProperty("status", "stop");
	ui->btnStop->style()->unpolish(ui->btnStop);
	ui->btnStop->style()->polish(ui->btnStop); /*���¼���qss*/

	process->setStop(false);
	process->start();
}

/*�������� ��ʾ������Ϣ*/
void RealTimeRecognition::slotShowErrorMsg(QString &strError)
{
	if (!strError.isEmpty())
	{
		ui->msgLabel->setText(strError);
	}
	
}



