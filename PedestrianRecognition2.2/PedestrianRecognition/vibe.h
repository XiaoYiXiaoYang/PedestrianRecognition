#pragma once
#ifndef BGDIFFERENCE_H
#define BGDIFFERENCE_H

#include<QString>
#include<qDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
// ÿ�����ص����������Ĭ��ֵ
#define DEFAULT_NUM_SAMPLES  20

// #minָ��Ĭ��ֵ
#define DEFAULT_MIN_MATCHES  2

// Sqthere�뾶Ĭ��ֵ
#define DEFAULT_RADIUS 20

// �Ӳ�������Ĭ��ֵ
#define DEFAULT_RANDOM_SAMPLE 16

class ViBe
{
public:
	ViBe(int num_sam = DEFAULT_NUM_SAMPLES,
		int min_match = DEFAULT_MIN_MATCHES,
		int r = DEFAULT_RADIUS,
		int rand_sam = DEFAULT_RANDOM_SAMPLE);
	~ViBe(void);

	// ����ģ�ͳ�ʼ��
	void init(Mat img);

	// �����һ֡ͼ��
	void ProcessFirstFrame(Mat img);

	// ���� ViBe �㷨����ȡǰ�����򲢸��±���ģ��������
	void Run(Mat img);

	// ��ȡǰ��ģ�Ͷ�ֵͼ��
	Mat getFGModel();

	// ɾ��������
	void deleteSamples();

	// x���ھӵ�
	int c_xoff[9];

	// y���ھӵ�
	int c_yoff[9];

private:
	// ������
	unsigned char ***samples;

	// ǰ��ģ�Ͷ�ֵͼ��
	Mat FGModel;

	// ÿ�����ص����������
	int num_samples;

	// #minָ��
	int num_min_matches;

	// Sqthere�뾶
	int radius;

	// �Ӳ�������
	int random_sample;
};


#endif // BGDIFFERENCE_H#pragma once
