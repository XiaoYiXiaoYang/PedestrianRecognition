#include "dbutil.h"

DbUtil::DbUtil(QObject *parent)
	: QObject(parent)
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());//设置中文显示
	
	initDB();
}

DbUtil::~DbUtil()
{
}

void DbUtil::initDB()
{

	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		m_db = QSqlDatabase::database("qt_sql_default_connection");
	}
	else
	{
		m_db = QSqlDatabase::addDatabase("QSQLITE");
	}
	
	//db.setHostName("easybook-3313b0");     	//设置数据库主机名
	m_db.setDatabaseName("qtDB.db");         	//(b)
	m_db.setUserName("ytt");            	//设置数据库用户名
	m_db.setPassword("123456");               	//设置数据库密码
	m_db.open();

	m_query = QSqlQuery(m_db);
}
bool DbUtil::createTable()
{
	bool success = m_query.exec("create table snapInfos(little_file varchar,big_file varchar,video_name varchar,time varchar)");		
	if (!success)
	{
		qDebug() << m_query.lastError() << endl;
	}
	return success;
}

bool DbUtil::insertData(PersonItem &person)
{
	m_query.prepare("INSERT INTO snapInfos VALUES (?,?,?,?)");
	m_query.bindValue(0, person.m_littleFile);	//给每个插入值标识符设定具体值
	m_query.bindValue(1, person.m_bigFile);
	m_query.bindValue(2, person.m_srcVedioName);
	m_query.bindValue(3, person.m_currentTime.toString("yyyy-MM-dd hh:mm:ss"));

	bool res = m_query.exec();
	if(!res)
	{
		qDebug() << m_query.lastError() << endl;
	}
	return res;
}

bool DbUtil::selectAll()
{
	m_query.prepare("SELECT * FROM snapInfos");
	bool res = m_query.exec();	//执行
	if (!res)
	{
		return res;
	}

	QSqlRecord recode = m_query.record();		//recode保存查询到一些内容信息，如表头、列数等等
	while (m_query.next())
	{
		qDebug() << m_query.value("little_file").toString() << "--" << m_query.value("big_file").toString() << "--" << m_query.value("video_name").toString() << "--" << m_query.value("time").toString() << endl;;
	}
	return res;
}

int DbUtil::getCount()
{
	m_query.prepare("SELECT count(*) FROM snapInfos");
	bool res = m_query.exec();
	if (!res)
	{
		qDebug() << m_query.lastError() << endl;
	}
	if (m_query.next())
	{
		return (m_query.value(0).toInt());
	}
}

int DbUtil::getSelectCount(QDateTime start, QDateTime end)
{
	QString strSQL = QString("select count(*) from snapInfos where time > '%1' and time < '%2'").arg(start.toString("yyyy-MM-dd hh:mm:ss")).arg(end.toString("yyyy-MM-dd hh:mm:ss"));
	//qDebug() << strSQL << endl;
	m_query.prepare(strSQL);
	bool res = m_query.exec();

	if (!res)
	{
		qDebug() << m_query.lastError() << endl;
	}
	if (m_query.next())
	{
		return (m_query.value(0).toInt());
	}
}

bool DbUtil::selectAll(QDateTime start, QDateTime end, int startnum, int endnum, QList<PersonItem> &personList)
{
	QString strSQL = QString("select * from snapInfos where time > '%1' and time < '%2' limit %3,%4").arg(start.toString("yyyy-MM-dd hh:mm:ss")).arg(end.toString("yyyy-MM-dd hh:mm:ss")).arg(startnum).arg(endnum);

	m_query.prepare(strSQL);
	bool res = m_query.exec();
	if (!res)
	{
		qDebug() << m_query.lastError() << endl;
		return res;
	}
	QSqlRecord recode = m_query.record();		//recode保存查询到一些内容信息，如表头、列数等等

	while (m_query.next())
	{
		QString little = m_query.value("little_file").toString();
		QString big = m_query.value("big_file").toString();
		QString videoName = m_query.value("video_name").toString();
		QString strTime = m_query.value("time").toString();
		QDateTime time = QDateTime::fromString(strTime,"yyyy-MM-dd HH:mm:ss");

		PersonItem item(little, big, videoName, time);
		personList.append(item);
	}
	return res;
}
/*函数描述 清空表*/
bool DbUtil::deleteTable()
{
	m_query.prepare("delete from snapInfos");
	return (m_query.exec());
}
