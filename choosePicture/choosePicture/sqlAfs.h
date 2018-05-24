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
	int UID;//�û�ID
	QDateTime TInsEnd;//ʱ��
	QString Item00;//��ɫ
	QString Item01;//�����״
	QString Item02;//��ϸ��
	QString Item03;//��ϸ��
	QString Item04;//��ĸϸ��
	QString Item10;//FOB1
	QString Item11;//FOB2
	QString Address;//�ļ���ŵ�ַ
};

struct TableData
{
	QString TABLE_NAME;//�û�ID
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
	bool GetRecordDataFromCode(list<RecordData> &dataCell,list<RecordData> &dataColor,list<RecordData> &dataFob, QDateTime TStart, QDateTime TEnd);//����ʱ���ѯ��¼����
	bool GetRecordTable(list<TableData> &data, QDateTime TStart, QDateTime TEnd);//��ѯ��¼��
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
