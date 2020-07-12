#include "vibe.h"

/*===================================================================
* ���캯����ViBe
* ˵������ʼ��ViBe�㷨���ֲ�����
* ������
*   int num_sam:  ÿ�����ص����������
*   int min_match:  #minָ��
*   int r:  Sqthere�뾶
*   int rand_sam:  �Ӳ�������
=====================================================================
*/
ViBe::ViBe(int num_sam, int min_match, int r, int rand_sam)
{
	num_samples = num_sam;
	num_min_matches = min_match;
	radius = r;
	random_sample = rand_sam;
	int c_off[9] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };
	for (int i = 0; i < 9; i++) {
		c_xoff[i] = c_yoff[i] = c_off[i];
	}
}
/*===================================================================
* ����������~ViBe
* ˵�����ͷ��������ڴ棻
*------------------------------------------------------------------
=====================================================================
*/
ViBe::~ViBe()
{
	deleteSamples();
}

/*===================================================================
* ��������init
* ˵��������ģ�ͳ�ʼ����
*    Ϊ���������ռ䣻
* ������
*   Mat img:  Դͼ��
* ����ֵ��void
=====================================================================
*/
void ViBe::init(Mat img)
{
	// ��̬������ά���飬samples[][][num_samples]�洢ǰ�����������Ĵ���
	samples = new unsigned char **[img.rows];
	for (int i = 0; i < img.rows; i++)
	{
		samples[i] = new uchar *[img.cols];
		for (int j = 0; j < img.cols; j++)
		{
			// �����У���num_samples֮�������һ��ֵ������ͳ�Ƹ����ص�������Ϊǰ���Ĵ�����
			samples[i][j] = new uchar[num_samples + 1];
			for (int k = 0; k < num_samples + 1; k++)
			{
				// ����������ʱ����������ȫ����ʼ��Ϊ0
				samples[i][j][k] = 0;
			}
		}
	}

	FGModel = Mat::zeros(img.size(), CV_8UC1);
}

/*===================================================================
* ��������ProcessFirstFrame
* ˵���������һ֡ͼ��
*    ��ȡ��Ƶ���е�һ֡�������ѡȡ���ص�������������������⣬��ʼ������ģ�ͣ�
* ������
*   Mat img:  Դͼ��
* ����ֵ��void
*/
void ViBe::ProcessFirstFrame(Mat img)
{
	RNG rng;
	int row, col;

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			for (int k = 0; k < num_samples; k++)
			{
				// ���ѡ��num_samples���������ص㣬��������ģ��
				int random;/*����0-9����� ���������ƶ�0-9 ����� ����*/
				random = rng.uniform(0, 9); row = i + c_yoff[random];
				random = rng.uniform(0, 9); col = j + c_xoff[random];

				// ��ֹѡȡ�����ص�Խ��
				if (row < 0)  row = 0;
				if (row >= img.rows)  row = img.rows - 1;
				if (col < 0)  col = 0;
				if (col >= img.cols)   col = img.cols - 1;

				// Ϊ�����⸳���ֵ
				samples[i][j][k] = img.at<uchar>(row, col);
			}
		}
	}
}

/*===================================================================
* ��������Run
* ˵�������� ViBe �㷨����ȡǰ�����򲢸��±���ģ�������⣻
* ������
*   Mat img:  Դͼ��
* ����ֵ��void
*/
void ViBe::Run(Mat img)
{
	RNG rng;
	int k = 0, dist = 0, matches = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			//========================================
			//        ǰ����ȡ   |   Extract Foreground Areas
			//========================================
			/*===================================================================
			* ˵�������㵱ǰ����ֵ���������ƥ�������
			* ������
			*   int matches: ��ǰ����ֵ����������ֵ֮��С����ֵ��ΧRADIUS�ĸ�����
			*   int count: ����������Ļ��������
			*/
			for (k = 0, matches = 0; matches < num_min_matches && k < num_samples; k++)
			{
				dist = abs(samples[i][j][k] - img.at<uchar>(i, j));
				if (dist < radius)/*�����ǰ����ֵ����������ֵ֮��С����ֵ��ΧRADIUS*/
					matches++;
			}
			/*===================================================================
			* ˵����
			*      ��ǰ����ֵ����������ֵƥ������ϸߣ�����Ϊ�Ǳ������ص㣻
			*      ��ʱ����ǰ��ͳ�ƴ���������ǰ��ģ�͡����¸�����ģ������ֵ�����¸����ص��������ص��ģ������ֵ
			*/
			if (matches >= num_min_matches)
			{
				// �Ѿ���Ϊ�Ǳ������أ��ʸ����ص�ǰ��ͳ�ƴ�����0
				samples[i][j][num_samples] = 0;

				// �����ص㱻��ǰ��ģ������ֵ��0
				FGModel.at<uchar>(i, j) = 0;
			}
			/*===================================================================
			* ˵����
			*      ��ǰ����ֵ����������ֵƥ������ϵͣ�����Ϊ��ǰ�����ص㣻
			*      ��ʱ��Ҫ����ǰ��ͳ�ƴ������жϸ���ǰ��ģ�ͣ�
			*/
			else
			{
				// �Ѿ���Ϊ��ǰ�����أ��ʸ����ص�ǰ��ͳ�ƴ���+1
				samples[i][j][num_samples]++;

				// �����ص㱻��ǰ��ģ������ֵ��255
				FGModel.at<uchar>(i, j) = 255;

				// ���ĳ�����ص�����50�α����Ϊǰ��������Ϊһ�龲ֹ��������Ϊ�˶����������Ϊ������
				if (samples[i][j][num_samples] > 50)
				{
					int random = rng.uniform(0, num_samples);   //���µ�ǰ���ص��������
					samples[i][j][random] = img.at<uchar>(i, j);
				}
			}


			//        ����ģ��������    |    
			if (matches >= num_min_matches)
			{
				// �Ѿ���Ϊ�������Ǳ������أ���ô���� 1 / �� �ĸ���ȥ�����Լ���ģ������ֵ
				int random = rng.uniform(0, random_sample);
				if (random == 0)
				{
					random = rng.uniform(0, num_samples);
					samples[i][j][random] = img.at<uchar>(i, j);
				}

				// ͬʱҲ�� 1 / �� �ĸ���ȥ���������ھӵ��ģ������ֵ
				random = rng.uniform(0, random_sample);
				if (random == 0)
				{
					int row, col;
					random = rng.uniform(0, 9); row = i + c_yoff[random];
					random = rng.uniform(0, 9); col = j + c_xoff[random];

					// ��ֹѡȡ�����ص�Խ��
					if (row < 0) row = 0;
					if (row >= img.rows)  row = img.rows - 1;
					if (col < 0) col = 0;
					if (col >= img.cols) col = img.cols - 1;

					// Ϊ�����⸳���ֵ
					random = rng.uniform(0, num_samples);
					samples[row][col][random] = img.at<uchar>(i, j);
				}
			}
		}
	}
}

/*===================================================================
* ��������getFGModel
* ˵������ȡǰ��ģ�Ͷ�ֵͼ��
* ����ֵ��Mat
*/
Mat ViBe::getFGModel()
{
	return FGModel;
}

/*===================================================================
* ��������deleteSamples
* ˵����ɾ�������⣻
* ����ֵ��void
*/
void ViBe::deleteSamples()
{
	delete samples;
}

