#include "process.h"

Process::Process(QObject *parent)
	: QThread(parent)
{
	m_dbutil = new DbUtil();

	connectEvent();
	
	/*bool res = m_dbutil->createTable();*/  /*ֻ��Ҫ����һ��*/
	bool a = m_dbutil->deleteTable();		/*��ձ�*/
	m_personNum = m_dbutil->getCount();
	
	m_pause = false;  /*����ͣ*/
	m_stop = false;  /*��ֹͣ*/
}

Process::~Process()
{
	delete m_dbutil;
}
void Process::connectEvent()
{
	connect(m_dbutil, SIGNAL(showErrorMsg(QString&)), this, SIGNAL(showErrorMsg(QString&)));
}

/*gamma ����*/
typedef unsigned char UNIT8; //�� 8 λ�޷�������ʾ 0��255 ֮�������
UNIT8 g_GammaLUT[256];//ȫ�����飺����256��Ԫ�ص�gammaУ�����ұ�
					  // ͼ��Ԥ���� ���յ���
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
		f = (i + 0.5F) / 256;//��һ��
		f = (float)pow(f, fPrecompensation);
		g_GammaLUT[i] = (UNIT8)(f * 256 - 0.5F);//����һ��
	}
}

void Process::GammaCorrectiom(Mat src, int iWidth, int iHeight, float fGamma, Mat &dst)
{
	int iCols, iRows;
	BuildTable(1 / fGamma);//gammaУ�����ұ��ʼ��
						   //��ͼ���ÿ�����ؽ��в��ұ����
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


/*�������� ��������*/
Mat Process::removeNoise(Mat foreGroundImg)
{
	Mat img = foreGroundImg.clone();
	Mat result;

	 //��ʴ������������
	Mat element1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat element2 = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(img, img, element1);
	dilate(img, img, element2);

	//��ֵ����ʹ����ֵ�˲�+����
	Mat element = getStructuringElement(MORPH_RECT, Size(11, 11));
	medianBlur(img, img, 5);//��ֵ�˲�
							
	dilate(img, result, element);
	
	return result;
}

/*�������� �ж�roi�Ƿ�������*/
int Process::isPerson(Mat roi)
{
	//CvSVM SVM;//ѵ��ģ��
	//SVM.load(SVMName);

	cv::Ptr<cv::ml::SVM> SVM = cv::ml::SVM::load(SVM_XML_NAME);
	cv::Size imgSize = cv::Size(64, 128);

	Mat beforeImg;
	preTreat(roi, beforeImg); //�õ�Ԥ������
	cvtColor(beforeImg, roi, CV_RGB2GRAY);

	Mat trainImage;
	resize(roi, trainImage, imgSize);

	Mat gradX, absGradX;
	Sobel(trainImage, gradX, CV_16S, 1, 0);
	cv::convertScaleAbs(gradX, absGradX);

	/// ��ֱ�����ݶ�
	Mat gradY, absGradY;
	cv::Sobel(trainImage, gradY, CV_16S, 0, 1);
	cv::convertScaleAbs(gradY, absGradY);

	addWeighted(absGradX, 0.5, absGradY, 0.5, 0, trainImage);

	/*imshow("Ԥ����", trainImage);	waitKey(10);*/

	HOGDescriptor hog(cvSize(64, 128), cvSize(16, 16), cvSize(8, 8), cvSize(8, 8), 9);
	vector<float> descriptors;
	hog.compute(trainImage, descriptors, Size(1, 1), Size(0, 0));//����������ü�ⴰ�ڲ��������ͼƬ��С����32*32����������winStride

	Mat pre(1, descriptors.size(), CV_32FC1);
	float *p = pre.ptr<float>(0);
	for (int i = 0; i <= descriptors.size() - 1; ++i) 
	{
		p[i] = descriptors[i];				//��test���ݣ�unchar��copy��sampleMat(float)��ͼ������
	}

	Mat label;
	SVM->predict(pre, label);
	int res = label.at<float>(0, 0);

	if ((int)res == 0)
	{
		return 1; //������
	}
	return 0;
}

/*��������  ����ǰ�� ����ǰ֡  �������е�����*/
Mat Process::getPerson(Mat src, Mat foreground)
{
	Mat result = src.clone();
	Mat img = removeNoise(foreground);

	//���Ҳ���������  /*�����ж��*/
	vector<vector<Point>> contours;
	vector<Vec4i> hierarcy;
	findContours(img, contours, hierarcy, CV_RETR_EXTERNAL, CHAIN_APPROX_NONE); //��������
	vector<Rect> boundRect(contours.size()); //������Ӿ��μ���
											 //drawContours(img2, contours, -1, Scalar(0, 0, 255), 1, 8);  //��������

											 //��������Ӿ���
	int x0 = 0, y0 = 0, w0 = 0, h0 = 0;
	double Area = 0, AreaAll = 0;
	for (int i = 0; i<contours.size(); i++)
	{
		boundRect[i] = boundingRect((Mat)contours[i]); //����ÿ����������Ӿ���
		Rect rect = boundRect[i];
		x0 = boundRect[i].x;  //��õ�i����Ӿ��ε����Ͻǵ�x����
		y0 = boundRect[i].y; //��õ�i����Ӿ��ε����Ͻǵ�y����
		w0 = boundRect[i].width; //��õ�i����Ӿ��εĿ��
		h0 = boundRect[i].height; //��õ�i����Ӿ��εĸ߶�

								  /*��Ӿ���ɸѡ*/

		Mat roiImage;
		src(rect).copyTo(roiImage);

		//�ж� ����
		if (isPerson(roiImage))
		{

			float ratio = (float)rect.width / (float)rect.height;   /*��߱�*/
			float dConArea = (float)contourArea(contours[i]);       /*���*/
			if (dConArea < 1500)
			{
				continue;
			}
			if (ratio > 0.9 || ratio < 0.3)
			{
				continue;
			}

			rectangle(result, Point(x0, y0), Point(x0 + w0, y0 + h0), Scalar(0, 255, 0), 2, 8); //���Ƶ�i����Ӿ���																					/*��ʾ�µ�����*/
			
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

/*�������� ͼ����main*/
void Process::processMain(QString path)
{
	Mat frame, gray, FGModel;
	VideoCapture capture;
	if ("camera" == path)
	{
		capture.open(0);  /*������ͷ*/
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

	

	// ��������ʱ��ͳ�Ʊ���
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
		if (isFirstFrame)/*��һ֡*/
		{
			emit showProcessFrame(frame);  /*��һ֡��ʾԭͼ*/
			vibe.init(gray);
			vibe.ProcessFirstFrame(gray);
			isFirstFrame = false;
		}
		else
		{
			start = static_cast<double>(getTickCount());			
			vibe.Run(gray);
			FGModel = vibe.getFGModel();/*	imshow("ViBe������ģ", FGModel);waitKey(10);*/

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
