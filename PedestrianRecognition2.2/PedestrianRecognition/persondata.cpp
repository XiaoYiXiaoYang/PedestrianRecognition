#include "persondata.h"

PersonData::PersonData(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::PersonData)
{
	ui->setupUi(this);

	m_dbutil = new DbUtil();
	m_sum = 0;
	m_pageNum = 0;
	initUi();
	connectEvent();
	setControlStyle();
}

PersonData::~PersonData()
{
	delete ui;
	delete m_dbutil;
}

void PersonData::initUi()
{
	ui->startTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
	ui->endTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");

	QDateTime time = QDateTime::currentDateTime().addDays(-3);

	ui->startTimeEdit->setDateTime(time);	/*三天前*/
	ui->endTimeEdit->setDateTime(QDateTime::currentDateTime());
	
										//设置列宽不可变动，即不能通过鼠标拖动增加列宽        
	ui->tableWidget->setRowCount(2); //行数根据实际设置
	ui->tableWidget->setColumnCount(6); //设置列数为5

	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);  //单个选中的方式
	//注意：需要 #include <QHeaderView>
	ui->tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头
	ui->tableWidget->horizontalHeader()->setVisible(false); //隐藏行表头

	//设置表格的各列的宽度值        
	ui->tableWidget->setColumnWidth(0, 205);
	ui->tableWidget->setColumnWidth(1, 205);
	ui->tableWidget->setColumnWidth(2, 205);
	ui->tableWidget->setColumnWidth(3, 205);
	ui->tableWidget->setColumnWidth(4, 205);
	ui->tableWidget->setColumnWidth(5, 205);

	ui->lineEditPage->setText(QString::number(m_pageNum));
	ui->labelPageSum->setText(QString::number(m_sum));
	ui->lineEditPage->setAlignment(Qt::AlignCenter);
	ui->labelPageSum->setAlignment(Qt::AlignCenter);
}
void PersonData::connectEvent()
{
	connect(ui->btnSearch, SIGNAL(clicked()), this, SLOT(slotBtnSearchClick()));
	connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(slotBtnNextClick()));
	connect(ui->btnPre, SIGNAL(clicked()), this, SLOT(slotBtnPreClick()));
	connect(ui->lineEditPage, SIGNAL(editingFinished()), this, SLOT(slotLineEditingFinished()));

	connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(slotShowTableItemDetail(QTableWidgetItem *)));

	connect(this, SIGNAL(showErrorMsg(QString&)), this, SLOT(slotShowErrorMsg(QString&)));
	connect(m_dbutil, SIGNAL(showErrorMsg(QString&)), this, SLOT(slotShowErrorMsg(QString&)));
}
void PersonData::setControlStyle()
{

}

void PersonData::setTableRowCount(int rowCount)
{
	if (0 < rowCount)
	{
		ui->tableWidget->setRowCount(rowCount);
	}
}
/*函数描述 查询行人记录*/
void PersonData::slotBtnSearchClick()
{
	QDateTime start = ui->startTimeEdit->dateTime();
	QDateTime end = ui->endTimeEdit->dateTime();

	m_sum = qCeil(m_dbutil->getSelectCount(start,end) / PAGE_PERSON_NUM);
	ui->labelPageSum->setText(QString::number(m_sum));
	m_pageNum = 1;
	ui->lineEditPage->setText(QString::number(m_pageNum));

	bool res = m_dbutil->selectAll(start,end,0, PAGE_PERSON_NUM,m_personList);
	if (!res)
	{
		emit showErrorMsg(tr("Search person record failed."));
	}

	if (0 == m_personList.size())
	{
		emit showErrorMsg(tr("No person data."));
	}
	else
	{
		clearTableData();

		int columnCount = ui->tableWidget->columnCount();
		
		QList<PersonItem>::iterator it; int i = 0;
		for (it = m_personList.begin(); it != m_personList.end(); it++)
		{
			addTable(i / columnCount, i % columnCount, *it);
			i++;
		}
	}
}

/*函数描述  加入表格*/
void PersonData::addTable(int row,int col,PersonItem &item)
{
	if (item.isEmpty())
	{
		emit showErrorMsg(tr("Person data is empty."));
		return;
	}

	//qDebug() << item.m_littleFile << item.m_bigFile << item.m_srcVedioName << item.m_currentTime << endl;
	Mat littleImg = imread(item.m_littleFile.toStdString());
	if (!littleImg.data)
	{
		emit showErrorMsg(tr("Little image is empty."));
		return;
	}
	
	Mat bigImg = imread(item.m_bigFile.toStdString());
	if (!bigImg.data)
	{
		emit showErrorMsg(tr("Big image is empty."));
		return;
	}

	SnapData snapPerson(littleImg, bigImg, item.m_srcVedioName, item.m_currentTime);
	SnapCard *snap = new SnapCard(ui->tableWidget);
	snap->setCardData(snapPerson);

	ui->tableWidget->setRowHeight(row, 250);   /*行高250*/
	ui->tableWidget->setCellWidget(row, col, snap);


	QTableWidgetItem *pItem = new QTableWidgetItem();
	pItem->setData(Qt::DisplayRole, snapPerson.m_currentTime);
	CustomWidgetItem *customItem = new CustomWidgetItem(snapPerson,nullptr,pItem);
	ui->tableWidget->setItem(row, col, (QTableWidgetItem*)customItem);
	ui->tableWidget->sortItems(Qt::DescendingOrder);
}

/*函数描述 显示错误信息*/
void PersonData::slotShowErrorMsg(QString& strError)
{
	if (!strError.isEmpty())
	{
		QMessageBox::critical(NULL, tr("Title"), strError, QMessageBox::Yes, QMessageBox::Yes);
	}
}

void PersonData::clearTableData()
{
	ui->tableWidget->clear();
}

/*函数描述 显示详情*/
void PersonData::slotShowTableItemDetail(QTableWidgetItem * item)
{
	CustomWidgetItem *customItem = dynamic_cast<CustomWidgetItem *>(item);
	if (nullptr == item)
	{
		emit showErrorMsg(tr("This ptr is empty."));
		return;
	}

	SnapData snap = customItem->getItem();
	if (snap.isEmpty())
	{
		emit showErrorMsg(tr("This person data is empty."));
		return;
	}

	m_snapDetailDlg = new SnapDataDetail();
	m_snapDetailDlg->setDetailData(snap);
	m_snapDetailDlg->show();

}

/*函数描述 点击上一页*/
void PersonData::slotBtnPreClick()
{
	int pageNum = ui->lineEditPage->text().toInt();

	if ((pageNum - 1) > m_sum || 0 >= (pageNum - 1))
	{
		emit showErrorMsg(tr("Pagenum is invalid"));
		return;
	}

	QDateTime start = ui->startTimeEdit->dateTime();
	QDateTime end = ui->endTimeEdit->dateTime();

	int startNum = (pageNum - 2)* PAGE_PERSON_NUM;
	int endNum = (pageNum - 1)* PAGE_PERSON_NUM;
	m_personList.clear();

	m_pageNum = pageNum - 1;
	ui->lineEditPage->setText(QString::number(m_pageNum));

	bool res = m_dbutil->selectAll(start, end, startNum, endNum, m_personList);
	if (!res)
	{
		emit showErrorMsg(tr("Search person record failed."));
	}

	if (0 == m_personList.size())
	{
		emit showErrorMsg(tr("No person data."));
	}
	else
	{
		clearTableData();
		int columnCount = ui->tableWidget->columnCount();

		QList<PersonItem>::iterator it; int i = 0;
		for (it = m_personList.begin(); it != m_personList.end(); it++)
		{
			addTable(i / columnCount, i % columnCount, *it);
			i++;
		}
	}
}

/*函数描述 点击下一页*/
void PersonData::slotBtnNextClick()
{
	int pageNum = ui->lineEditPage->text().toInt();

	if ((pageNum + 1) > m_sum || 0 >= (pageNum + 1))
	{
		emit showErrorMsg(tr("Pagenum is invalid"));
		return;
	}

	QDateTime start = ui->startTimeEdit->dateTime();
	QDateTime end = ui->endTimeEdit->dateTime();

	int startNum = pageNum * PAGE_PERSON_NUM;
	int endNum = (pageNum + 1)* PAGE_PERSON_NUM;
	m_personList.clear();

	m_pageNum = pageNum + 1;
	ui->lineEditPage->setText(QString::number(m_pageNum));

	bool res = m_dbutil->selectAll(start, end, startNum, endNum, m_personList);
	if (!res)
	{
		emit showErrorMsg(tr("Search person record failed."));
	}

	if (0 == m_personList.size())
	{
		emit showErrorMsg(tr("No person data."));
	}
	else
	{
		clearTableData();
		int columnCount = ui->tableWidget->columnCount();

		QList<PersonItem>::iterator it; int i = 0;
		for (it = m_personList.begin(); it != m_personList.end(); it++)
		{
			addTable(i / columnCount, i % columnCount, *it);
			i++;
		}
	}
}

/*函数描述 编辑完成 刷新页面*/
void PersonData::slotLineEditingFinished()
{
	int pageNum = ui->lineEditPage->text().toInt();

	if (pageNum > m_sum || 0 >= pageNum)
	{
		emit showErrorMsg(tr("Pagenum is invalid"));
		return;
	}

	QDateTime start = ui->startTimeEdit->dateTime();
	QDateTime end = ui->endTimeEdit->dateTime();

	int startNum = (pageNum - 1) * PAGE_PERSON_NUM;
	int endNum = pageNum* PAGE_PERSON_NUM;
	m_personList.clear();

	m_pageNum = pageNum;
	ui->lineEditPage->setText(QString::number(m_pageNum));

	bool res = m_dbutil->selectAll(start, end, startNum, endNum, m_personList);
	if (!res)
	{
		emit showErrorMsg(tr("Search person record failed."));
	}

	if (0 == m_personList.size())
	{
		emit showErrorMsg(tr("No person data."));
	}
	else
	{
		clearTableData();
		int columnCount = ui->tableWidget->columnCount();

		QList<PersonItem>::iterator it; int i = 0;
		for (it = m_personList.begin(); it != m_personList.end(); it++)
		{
			addTable(i / columnCount, i % columnCount, *it);
			i++;
		}
	}
}