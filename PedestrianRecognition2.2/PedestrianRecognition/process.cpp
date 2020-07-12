#include "process.h"

Process::Process(QObject *parent)
	: QThread(parent)
{
	m_dbutil = new DbUtil();

	connectEvent();
	
	/*bool res = m_dbutil->createTable();*/  /*只需要创建一次*/
	bool a = m_dbutil->deleteTable();		/*清空表*/
	m_personNum = m_dbutil->getCount();
	
	m_pause = false;  /*不暂停*/
	m_stop = false;  /*不停止*/
}

Process::~Process()
{
	delete m_dbutil;
}
void Process::connectEvent()
{
	connect(m_dbutil, SIGNAL(showErrorMsg(QString&)), this, SIGNAL(showErrorMsg(QString&)));
}

/*gamma 矫正*/
typedef unsigned char UNIT8; //用 8 位无符号数表示 0～255 之间的整数
UNIT8 g_GammaLUT[256];//全局数组：包含256个元素的gamma校正查找表
					  // 图像预处理 光照调节
void Process::preTreat(Mat &image, Mat &result)
{
	image.copyTo(result);
	GammaCorrectiom(image, image.cols, image.rows, 0.9, result);
}

void Process::BuildTable(float fPrecompensation)
{
	int i;
	float f;
	for (i = 0; i<256; i++)
	{
		f = (i + 0.5F) / 256;//归一化
		f = (float)pow(f, fPrecompensation);
		g_GammaLUT[i] = (UNIT8)(f * 256 - 0.5F);//反归一化
	}
}

void Process::GammaCorrectiom(Mat src, int iWidth, int iHeight, float fGamma, Mat &dst)
{
	int iCols, iRows;
	BuildTable(1 / fGamma);//gamma校正查找表初始化
						   //对图像的每个像素进行查找表矫正
	for (iRows = 0; iRows<iHeight; iRows++)
	{
		for (iCols = 0; iCols<iWidth; iCols++)
		{
			dst.at<Vec3b>(iRows, iCols)[0] = g_GammaLUT[src.at<Vec3b>(iRows, iCols)[0]];
			dst.at<Vec3b>(iRows, iCols)[1] = g_GammaLUT[src.at<Vec3b>(iRows, iCols)[1]];
			dst.at<Vec3b>(iRows, iCols)[2] = g_GammaLUT[src.at<Vec3b>(iRows, iCols)[2]];
		}
	}
}


/*函数描述 消除噪音*/
Mat Process::removeNoise(Mat foreGroundImg)
{
	Mat img = foreGroundImg.clone();
	Mat result;

	 //腐蚀膨胀消除噪音
	Mat element1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat element2 = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(img, img, element1);
	dilate(img, img, element2);

	//二值化后使用中值滤波+膨胀
	Mat element = getStructuringElement(MORPH_RECT, Size(11, 11));
	medianBlur(img, img, 5);//中值滤波
							
	dilate(img, result, element);
	
	return result;
}

/*函数描述 判断roi是否是行人*/
int Process::isPerson(Mat roi)
{
	//CvSVM SVM;//训练模型
	//SVM.load(SVMName);

	cv::Ptr<cv::ml::SVM> SVM = cv::ml::SVM::load(SVM_XML_NAME);
	cv::Size imgSize = cv::Size(64, 128);

	Mat beforeImg;
	preTreat(roi, beforeImg); //得到预处理结果
	cvtColor(beforeImg, roi, CV_RGB2GRAY);

	Mat trainImage;
	resize(roi, trainImage, imgSize);

	Mat gradX, absGradX;
	Sobel(trainImage, gradX, CV_16S, 1, 0);
	cv::convertScaleAbs(gradX, absGradX);

	/// 垂直方向梯度
	Mat gradY, absGradY;
	cv::Sobel(trainImage, gradY, CV_16S, 0, 1);
	cv::convertScaleAbs(gradY, absGradY);

	addWeighted(absGradX, 0.5, absGradY, 0.5, 0, trainImage);

	/*imshow("预处理", trainImage);	waitKey(10);*/

	HOGDescriptor hog(cvSize(64, 128), cvSize(16, 16), cvSize(8, 8), cvSize(8, 8), 9);
	vector<float> descriptors;
	hog.compute(trainImage, descriptors, Size(1, 1), Size(0, 0));//这里可以设置检测窗口步长，如果图片大小超过32*32，可以设置winStride

	Mat pre(1, descriptors.size(), CV_32FC1);
	float *p = pre.ptr<float>(0);
	for (int i = 0; i <= descriptors.size() - 1; ++i) 
	{
		p[i] = descriptors[i];				//将test数据（unchar）copy到sampleMat(float)中图像特征
	}

	Mat label;
	SVM->predict(pre, label);
	int res = label.at<float>(0, 0);

	if ((int)res == 0)
	{
		return 1; //是行人
	}
	return 0;
}

/*函数描述  根据前景 处理当前帧  画出其中的行人*/
Mat Process::getPerson(Mat src, Mat foreground)
{
	Mat result = src.clone();
	Mat img = removeNoise(foreground);

	//查找并绘制轮廓  /*可能有多个*/
	vector<vector<Point>> contours;
	vector<Vec4i> hierarcy;
	findContours(img, contours, hierarcy, CV_RETR_EXTERNAL, CHAIN_APPROX_NONE); //查找轮廓
	vector<Rect> boundRect(contours.size()); //定义外接矩形集合
											 //drawContours(img2, contours, -1, Scalar(0, 0, 255), 1, 8);  //绘制轮廓

											 //查找正外接矩形
	int x0 = 0, y0 = 0, w0 = 0, h0 = 0;
	double Area = 0, AreaAll = 0;
	for (int i = 0; i<contours.size(); i++)
	{
		boundRect[i] = boundingRect((Mat)contours[i]); //查找每个轮廓的外接矩形
		Rect rect = boundRect[i];
		x0 = boundRect[i].x;  //获得第i个外接矩形的左上角的x坐标
		y0 = boundRect[i].y; //获得第i个外接矩形的左上角的y坐标
		w0 = boundRect[i].width; //获得第i个外接矩形的宽度
		h0 = boundRect[i].height; //获得第i个外接矩形的高度

								  /*外接矩形筛选*/

		Mat roiImage;
		src(rect).copyTo(roiImage);

		//判断 画框
		if (isPerson(roiImage))
		{

			float ratio = (float)rect.width / (float)rect.height;   /*宽高比*/
			float dConArea = (float)contourArea(contours[i]);       /*面积*/
			if (dConArea < 1500)
			{
				continue;
			}
			if (ratio > 0.9 || ratio < 0.3)
			{
				continue;
			}

			rectangle(result, Point(x0, y0), Point(x0 + w0, y0 + h0), Scalar(0, 255, 0), 2, 8); //绘制第i个外接矩形																					/*显示新的行人*/
			
			SnapData snap(roiImage, result, m_vedioItem.m_fileName, QDateTime::currentDateTime());
			emit showNewPerson(snap);

			QString littleName = QString("./pic/person/little_%1.png").arg(m_personNum);
			QString bigName = QString("./pic/person/big_%1.png").arg(m_personNum);
			
			PersonItem person(littleName, bigName, m_vedioItem.m_fileName, QDateTime::currentDateTime());
			
			bool res = m_dbutil->insertData(person);
			if (!res)
			{
				emit showErrorMsg(tr("Insert record to database failed."));
				continue;
			}
			
			imwrite(littleName.toStdString(), roiImage);
			imwrite(bigName.toStdString(), result);
			m_personNum++;
		}
	}
	return result;
}

/*函数描述 图像处理main*/
void Process::processMain(QString path)
{
	Mat frame, gray, FGModel;
	VideoCapture capture;
	if ("camera" == path)
	{
		capture.open(0);  /*打开摄像头*/
		if (!capture.isOpened())
		{
			emit showErrorMsg(tr("Can not open camera."));
			return;
		}
	}
	else
	{
		capture.open(path.toStdString());
		if (!capture.isOpened())
		{
			emit showErrorMsg(tr("Can not open video."));
			return;
		}
	}

	

	// 程序运行时间统计变量
	// the Time Statistical Variable of Program Running Time
	double time;
	double start;

	ViBe vibe;
	bool isFirstFrame = true;

	while (!m_stop)
	{
		m_mutex.lock();

		capture >> frame;
		if (frame.empty())
		{
			emit showErrorMsg(tr("Next frame is empty."));
			return;
		}
		if (frame.cols > m_width || frame.rows > m_hight)
		{
			resize(frame, frame, Size(m_width, m_hight));
		}

		cvtColor(frame, gray, CV_RGB2GRAY);
		if (isFirstFrame)/*第一帧*/
		{
			emit showProcessFrame(frame);  /*第一帧显示原图*/
			vibe.init(gray);
			vibe.ProcessFirstFrame(gray);
			isFirstFrame = false;
		}
		else
		{
			start = static_cast<double>(getTickCount());			
			vibe.Run(gray);
			FGModel = vibe.getFGModel();/*	imshow("ViBe背景建模", FGModel);waitKey(10);*/

			Mat res = getPerson(frame, FGModel);
			time = ((double)getTickCount() - start) / getTickFrequency() * 1000;
			
			if (time < 40)
			{
				msleep(40-time);
			}
			time = ((double)getTickCount() - start) / getTickFrequency() * 1000;
			//qDebug() << time << endl;
			emit showProcessFrame(res);/*QString saveName = QString("./pic/frame.png");  imwrite(saveName.toStdString(), res);*/
		}

		m_mutex.unlock();
	}
	return;
}

void Process::setVideoItem(VideoItem vedioItem)
{
	m_vedioItem =  vedioItem;
}

void Process::setPause()
{
	m_mutex.lock();
}

void Process::setResume()
{
	m_mutex.unlock();
}

void Process::setStop(bool stop)
{
	m_stop = stop;
}

void Process::run()
{
	processMain(m_vedioItem.m_filePath);
}
