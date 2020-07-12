#pragma once

#include <QAbstractListModel>
#include<data.h>

class ListModelEx : public QAbstractListModel
{
	Q_OBJECT

public:
	explicit ListModelEx(const QList<VideoItem> itemList, QObject *parent = 0);
	~ListModelEx();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;  //����ģ�͵�����
	QVariant data(const QModelIndex &index, int role) const;    //����ģ�͵�������
																//���������ͱ����ͼ�ı�ͷ��ʾһЩ����
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	QList<VideoItem> m_ItemList;//��Ϊģ�������Դ
};
