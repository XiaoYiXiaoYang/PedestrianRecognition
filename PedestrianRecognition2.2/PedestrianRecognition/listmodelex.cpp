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
	return m_ItemList.count();      //返回item的个数
}
//获取索引项对应的数据
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
	if (role == Qt::DisplayRole) /*返回数据*/
	{
		return m_ItemList.at(index.row()).m_fileName;
	}
	else
	{
		return QVariant();
	}
}
//设置表头对应的数据
QVariant ListModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole) return QVariant();
	if (orientation == Qt::Horizontal)
		return QString("Column %1").arg(section); //表头显示的数据
	else
		return QString("Row %1").arg(section);
}
