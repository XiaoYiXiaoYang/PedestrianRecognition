#include<data.h>

VideoItem::VideoItem()
{
	m_fileName = "";
	m_filePath = "";
}

VideoItem::VideoItem(QString filename, QString filepath)
{
	m_fileName = filename;
	m_filePath = filepath;
}
bool VideoItem::isEmpty()
{
	if (m_fileName.isEmpty() || m_filePath.isEmpty())
	{
		return true;
	}
	return false;
}


SnapData::SnapData()
{
	m_littleFile = Mat::zeros(2, 2, CV_8UC3);
	m_bigFile = Mat::zeros(2, 2, CV_8UC3);
	m_srcVedioName = "";
	m_currentTime = QDateTime::currentDateTime();
}
SnapData::SnapData(Mat littleFile, Mat bigFile, QString srcVedioName, QDateTime currentTime)
{
	m_littleFile = littleFile.clone();
	m_bigFile = bigFile.clone();
	m_srcVedioName = srcVedioName;
	m_currentTime = currentTime;
}

bool SnapData::isEmpty()
{
	if ((!m_littleFile.data) || (!m_bigFile.data) || m_srcVedioName.isEmpty())
	{
		return true;
	}
	return false;
}

PersonItem::PersonItem()
{
	m_littleFile = "";
	m_bigFile = "";
	m_srcVedioName = "";
	m_currentTime = QDateTime::currentDateTime();
}
PersonItem::PersonItem(QString littleFile, QString bigFile, QString srcVedioName, QDateTime currentTime)
{
	m_littleFile = littleFile;
	m_bigFile = bigFile;
	m_srcVedioName = srcVedioName;
	m_currentTime = currentTime;
}

bool PersonItem::isEmpty()
{
	if ((m_littleFile.isEmpty()) || (m_bigFile.isEmpty()) || m_srcVedioName.isEmpty())
	{
		return true;
	}
	return false;
}

CustomWidgetItem::CustomWidgetItem(SnapData data, QListWidgetItem *parent1, QTableWidgetItem *parent2)
{
	if (nullptr != parent1)
	{
		QListWidgetItem(*parent1);
	}
	if (nullptr != parent2)
	{
		QTableWidgetItem(*parent2);
	}

	m_snapData = data;
}

CustomWidgetItem::~CustomWidgetItem()
{

}
SnapData CustomWidgetItem::getItem()
{
	return m_snapData;
}

QImage MatToQImage::cvMat2QImage(const Mat& mat)
{
	if (mat.type() == CV_8UC1)                  // 单通道
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		image.setColorCount(256);               // 灰度级数256
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		uchar *pSrc = mat.data;                 // 复制mat数据
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}

	else if (mat.type() == CV_8UC3)             // 3通道
	{
		const uchar *pSrc = (const uchar*)mat.data;         // 复制像素
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);    // R, G, B 对应 0,1,2
		return image.rgbSwapped();              // rgbSwapped是为了显示效果色彩好一些。
	}
	else if (mat.type() == CV_8UC4)
	{
		const uchar *pSrc = (const uchar*)mat.data;         // 复制像素
															// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);        // B,G,R,A 对应 0,1,2,3
		return image.copy();
	}
	else
	{
		return QImage();
	}
}