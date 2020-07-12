#include "listmodelex.h"

ListModelEx::ListModelEx(const QList<VideoItem> itemList, QObject *parent)
	: QAbstractListModel(parent)
{
	m_ItemList = itemList;
}

ListModelEx::~ListModelEx()
{
}

int ListModelEx::rowCount(const QModelIndex &parent) const
{
	return m_ItemList.count();      //����item�ĸ���
}
//��ȡ�������Ӧ������
QVariant ListModelEx::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	}
	if (index.row() >= m_ItemList.size())
	{
		return QVariant();
	}
	if (role == Qt::DisplayRole) /*��������*/
	{
		return m_ItemList.at(index.row()).m_fileName;
	}
	else
	{
		return QVariant();
	}
}
//���ñ�ͷ��Ӧ������
QVariant ListModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole) return QVariant();
	if (orientation == Qt::Horizontal)
		return QString("Column %1").arg(section); //��ͷ��ʾ������
	else
		return QString("Row %1").arg(section);
}
