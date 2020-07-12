#pragma once

#include <QObject>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include"data.h"

class DbUtil : public QObject
{
	Q_OBJECT

public:
	DbUtil(QObject *parent = 0);
	~DbUtil();

	void initDB();
	bool createTable();
	bool insertData(PersonItem &person);
	bool selectAll();
	bool selectAll(QDateTime start, QDateTime end,int startnum,int endnum,QList<PersonItem> &personList);
	int getCount();
	int getSelectCount(QDateTime start, QDateTime end);
	bool deleteTable();
signals:
	void showErrorMsg(QString &strMsg);

private:
	QSqlDatabase m_db;	/*Êý¾Ý¿â*/
	QSqlQuery m_query;	/*Ö´ÐÐÓï¾ä*/
};
