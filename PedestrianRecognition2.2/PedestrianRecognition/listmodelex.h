#pragma once

#include <QAbstractListModel>
#include<data.h>

class ListModelEx : public QAbstractListModel
{
	Q_OBJECT

public:
	explicit ListModelEx(const QList<VideoItem> itemList, QObject *parent = 0);
	~ListModelEx();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;  //返回模型的行数
	QVariant data(const QModelIndex &index, int role) const;    //返回模型的数据项
																//可以在树和表格视图的表头显示一些内容
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	QList<VideoItem> m_ItemList;//作为模块的数据源
};
