#pragma once

#include <QWidget>
#include "ui_persondata.h"
#include"data.h"
#include"dbutil.h"
#include"snapcard.h"
#include <QHeaderView>
#include"qmath.h"
#include<QMessageBox>
#include"snapdatadetail.h"

#define PAGE_PERSON_NUM 12

class PersonData : public QWidget
{
	Q_OBJECT

public:
	PersonData(QWidget *parent = Q_NULLPTR);
	~PersonData();

	void initUi();
	void connectEvent();
	void setControlStyle();
	void setTableRowCount(int rowCount);
	void addTable(int row, int col, PersonItem &item);
	void clearTableData();
	
signals:
	void showErrorMsg(QString &strMsg);

private slots:
	void slotBtnSearchClick();
	void slotBtnPreClick();
	void slotBtnNextClick();
	void slotLineEditingFinished();
	void slotShowErrorMsg(QString& strError);
	void slotShowTableItemDetail(QTableWidgetItem *);
private:
	Ui::PersonData *ui;
	DbUtil *m_dbutil;					/*数据库工具*/
	QList<PersonItem> m_personList;
	SnapDataDetail *m_snapDetailDlg;     /*详情对话框指针*/
	int m_sum;							/*查询到的总数*/
	int m_pageNum;						/*当前页码*/
};
