#pragma once
#ifndef _SQLAFS_H_
#define _SQLAFS_H_

#include "QSqliteUtil.h"
#include <Qstring>
#include <list>
#include <QDateTime>
#include "TypeDef.h"
using namespace std;

struct RecordData
{
	int UID;//用户ID
	QDateTime TInsEnd;//时间
	QString Item00;//颜色
	QString Item01;//粪便性状
	QString Item02;//红细胞
	QString Item03;//白细胞
	QString Item04;//酵母细胞
	QString Item10;//FOB1
	QString Item11;//FOB2
	QString Address;//文件存放地址
};

struct TableData
{
	QString TABLE_NAME;//用户ID
};

class sqlAfs
{
public:
	sqlAfs();
	~sqlAfs();
	QSqliteUtil*    m_MySql;

	void SetCheckCollect(vector<int> colorCheck,vector<int> cellCheck,vector<int> fobCheck){m_colorCollect = colorCheck;m_cellCollect = cellCheck;m_fobCollect = fobCheck;};
	//void GetCheckBoxChoose();
	void judgementColor(QString& strSql,vector<int> Check);
	void judgementCell(QString& strSql,vector<int> Check);
	void judgementFob(QString& strSql,vector<int> Check);
	bool GetRecordDataFromCode(list<RecordData> &dataCell,list<RecordData> &dataColor,list<RecordData> &dataFob, QDateTime TStart, QDateTime TEnd);//根据时间查询记录数据
	bool GetRecordTable(list<TableData> &data, QDateTime TStart, QDateTime TEnd);//查询记录表
	bool MysqlColor(QString& strSql,vector<int> Check, list<QString> yearTable,QString tmp_YearTime,QDateTime TStart, QDateTime TEnd);
	bool MysqlCell(QString& strSql,vector<int> Check, list<QString> yearTable,QString tmp_YearTime,QDateTime TStart, QDateTime TEnd);
	bool MysqlFOB(QString& strSql,vector<int> Check, list<QString> yearTable,QString tmp_YearTime,QDateTime TStart, QDateTime TEnd);
protected:

private:
	QString strSqlColor;
	QString strSqlFOB;
	QString strSqlCell;
	vector<int> m_colorCollect;
	vector<int> m_cellCollect;
	vector<int> m_fobCollect;
};
#endif
