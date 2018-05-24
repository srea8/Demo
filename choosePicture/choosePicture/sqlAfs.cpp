#include "sqlAfs.h"
#include "choosepicture.h"
#include <qdebug>
#include <qdatetime.h>
#include <QTextCodec>

sqlAfs::sqlAfs()
{
	DbConectInfo m_dbInfo;
	m_dbInfo.qstrDbIp = "localhost";
	m_dbInfo.qstrDbPort = 3306;
	m_dbInfo.qstrDbUserName = "root";
	m_dbInfo.qstrDbPassWord = "123456";
	m_dbInfo.qstrDbName = "afs";
	m_dbInfo.qstrDbType = "MySql";
	m_MySql = new QSqliteUtil(m_dbInfo);
};

sqlAfs::~sqlAfs()
{

};

bool sqlAfs::GetRecordTable(list<TableData> &data, QDateTime TStart, QDateTime TEnd)
{
	QString TableSql;
	TableSql = QStringLiteral("select TABLE_NAME from information_schema.TABLES t where t.TABLE_NAME like 'test_%'");
	bool bok_Table = false;
	QSqlQuery query_table = m_MySql->ExecuteSqlQuery(TableSql, bok_Table);
	if (!bok_Table) return bok_Table;
	bool bfind_Table = false;
	while (query_table.next())
	{
		bfind_Table = true;
		TableData info_table;
		info_table.TABLE_NAME = query_table.value(0).toString();
		data.push_back(info_table);
	}
	return bfind_Table;
}

bool sqlAfs::MysqlColor(QString& strSql,vector<int> Check, list<QString> yearTable,QString tmp_YearTime,QDateTime TStart, QDateTime TEnd)
{
	int num = 0;
	for(auto check=Check.begin();check!=Check.end();check++)
	{
		num += *check;
	}
	if(num == 0)
	{
		return false;
	}
	else
	{
		if (yearTable.size() == NULL)    //输入年份数据库中不存在
		{
			return false;
		}
		else if (yearTable.size() == 1)              //只有一年存在数据库中
		{
			strSql = QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_") 
				+ *yearTable.begin() +QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *yearTable.begin() + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
				+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + "' and ( 1 = 2 ";	
			judgementColor(strSql,Check);
			strSql += QStringLiteral(");");

		}
		else
		{
			for (list<QString>::iterator it = yearTable.begin(); it != --yearTable.end(); it++)
			{
				tmp_YearTime = *it;
				if (tmp_YearTime == *yearTable.begin())
				{
					strSql.append(QStringLiteral("select * from("));
				}
				strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
					+ *it + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *it + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
					+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + "' and ( 1 = 2 " );
				judgementColor(strSql,Check);
				strSql += QStringLiteral(" ) union ");
			}
			strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
				+ *--yearTable.end() + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *--yearTable.end() + QStringLiteral(") t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
				+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2"));
				judgementColor(strSql,Check);
				strSql += QStringLiteral(" ))t;");
		}	
	}	
	return true;
}

void sqlAfs::judgementColor(QString& strSql,vector<int> Check)
{
	auto m_Check = Check.begin();
	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item00 ='黄色'");
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item00 ='红色'");		
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item00 ='褐色'");
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item00 ='黑色'");
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	strSql +=QStringLiteral(" ) and ( 1 = 2 ");

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item01 ='软便'");
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item01 ='稀便'");
	//strSql = QString::fromUtf8(strSql.toLocal8Bit());
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}
}


bool sqlAfs::MysqlCell(QString& strSql,vector<int> Check, list<QString> yearTable,QString tmp_YearTime,QDateTime TStart, QDateTime TEnd)
{
	int num = 0;
	for(auto check=Check.begin();check!=Check.end();check++)
	{
		num += *check;
	}
	if(num == 0)
	{
		return false;
	}
	else
	{
		if (yearTable.size() == NULL)    //输入年份数据库中不存在
		{
			return false;
		}
		else if (yearTable.size() == 1)              //只有一年存在数据库中
		{
			strSql = QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_") 
				+ *yearTable.begin() +QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *yearTable.begin() + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
				+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2 ");
			judgementCell(strSql,Check);
			strSql += QStringLiteral(");");
		}
		else
		{
			for (list<QString>::iterator it = yearTable.begin(); it != --yearTable.end(); it++)
			{
				tmp_YearTime = *it;
				if (tmp_YearTime == *yearTable.begin())
				{
					strSql.append(QStringLiteral("select * from("));
				}
				strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
					+ *it + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *it + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
					+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2" ));
				judgementCell(strSql,Check);
				strSql += QStringLiteral(" ) union ");
			}
			strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
				+ *--yearTable.end() + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *--yearTable.end() + QStringLiteral(") t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
				+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2"));
			judgementCell(strSql,Check);
			strSql += QStringLiteral(" ))t;");
		}
	}
	return true;
}

void sqlAfs::judgementCell(QString& strSql,vector<int> Check)
{
	auto m_Check = Check.begin();
	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item02 != '阴性'");
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item03 != '阴性'");		
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item04 != '阴性'");
	//strSql = QString::fromUtf8(strSql.toLocal8Bit());
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}
}

bool sqlAfs::MysqlFOB(QString& strSql,vector<int> Check, list<QString> yearTable,QString tmp_YearTime,QDateTime TStart, QDateTime TEnd)
{
	int num = 0;
	for(auto check=Check.begin();check!=Check.end();check++)
	{
		num += *check;
	}
	if(num == 0)
	{
		return false;
	}
	else
	{
		if (yearTable.size() == NULL)    //输入年份数据库中不存在
		{
			return false;
		}
		else if (yearTable.size() == 1)              //只有一年存在数据库中
		{
			strSql = QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_") 
				+ *yearTable.begin() +QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *yearTable.begin() + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
				+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2 ");
			judgementFob(strSql,Check);
			strSql += QStringLiteral(");");
		}
		else
		{
			for (list<QString>::iterator it = yearTable.begin(); it != --yearTable.end(); it++)
			{
				tmp_YearTime = *it;
				if (tmp_YearTime == *yearTable.begin())
				{
					strSql.append(QStringLiteral("select * from("));
				}
				strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
					+ *it + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *it + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
					+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2" ));
				judgementFob(strSql,Check);
				strSql += QStringLiteral(" ) union ");
			}
			strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
				+ *--yearTable.end() + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *--yearTable.end() + QStringLiteral(") t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
				+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + QStringLiteral("' and ( 1 = 2"));
			judgementFob(strSql,Check);
			strSql += QStringLiteral(" ))t;");
		}
	}
	return true;
}

void sqlAfs::judgementFob(QString& strSql,vector<int> Check)
{
	auto m_Check = Check.begin();
	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item10 = '阳性' or t1.Item11 = '阳性'");
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item10 = '弱阳性' or t1.Item11 = '弱阳性'");		
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}

	if(*m_Check == 1)
		strSql +=QStringLiteral(" or t1.Item10 = '阴性' or t1.Item11 = '阴性'");
	//strSql = QString::fromUtf8(strSql.toLocal8Bit());
	m_Check++;
	if(m_Check==Check.end())
	{
		return;
	}
}

bool sqlAfs::GetRecordDataFromCode(list<RecordData> &dataCell,list<RecordData> &dataColor,list<RecordData> &dataFob, QDateTime TStart, QDateTime TEnd)
{
	list<TableData> tabledata;
	list<QString> tmpTable, yearTable;
	GetRecordTable(tabledata, TStart, TEnd);
	if (tabledata.size() == NULL)
	{
		return false;
	}
	list<TableData>::iterator beginIter = tabledata.begin();//封装数据库年份
	for (int tmp = 0; tmp < tabledata.size(); tmp++)
	{
		QString tmpTableStart = (beginIter++)->TABLE_NAME.mid(5, 4);
		tmpTable.push_back(tmpTableStart);
	}
	
	int cnt_Year = TEnd.toString("yyyy").toInt() - TStart.toString("yyyy").toInt() + 1;
	for (int tmpYear = 0; tmpYear < cnt_Year; tmpYear++)//判断日历年份是否存在
	{
		for (list<QString>::iterator it = tmpTable.begin(); it != tmpTable.end(); it++)
		{
			if (QString::number((TStart.toString("yyyy").toInt() + tmpYear),10) == *it)
			{
				QString tmpTableYear = *it;
				yearTable.push_back(tmpTableYear);
				break;
			}
		}
	}

	strSqlColor.clear();
	strSqlFOB.clear();
	strSqlCell.clear();
	QString tmp_YearTime;
	//if (yearTable.size() == NULL)    //输入年份数据库中不存在
	//{
	//	return false;
	//}
	//else if (yearTable.size() == 1)              //只有一年存在数据库中
	//{
	//	strSql = QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_") 
	//		+ *yearTable.begin() +QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *yearTable.begin() + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
	//		+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + "';";
	//}
	//else
	//{
	//	for (list<QString>::iterator it = yearTable.begin(); it != --yearTable.end(); it++)
	//	{
	//		tmp_YearTime = *it;
	//		if (tmp_YearTime == *yearTable.begin())
	//		{
	//			strSql.append(QStringLiteral("select * from("));
	//		}
	//		strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
	//			+ *it + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *it + QStringLiteral(" )t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
	//			+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + "'" + QStringLiteral(" union "));
	//	}
	//	strSql.append(QStringLiteral("select t1.UID,t1.TInsEnd,t1.Item00,t1.Item01,t1.Item02,t1.Item03,t1.Item04,t1.Item10,t1.Item11,t2.Address from test_")
	//		+ *--yearTable.end() + QStringLiteral(" t1 inner join (select distinct uid, substring_index(address,'\\\\',5) address  from photo_") + *--yearTable.end() + QStringLiteral(") t2 on t1.UID = t2.UID where t1.TInsEnd >= '")
	//		+ TStart.toString("yyyy-MM-dd") + QStringLiteral("' and t1.TInsEnd <='") + TEnd.toString("yyyy-MM-dd") + "')t;");
	//}	
	//strSql = QStringLiteral("select UID,TInsEnd,Item00,Item01,Item02,Item03,Item04,Item10,Item11,Item12 from test_2017 where TInsEnd >= '2017-12-25' and TInsEnd <= '2017-12-30'");
	bool boolColor = MysqlColor(strSqlColor,m_colorCollect,yearTable,tmp_YearTime,TStart,TEnd);
	bool boolCell = MysqlCell(strSqlCell,m_cellCollect,yearTable,tmp_YearTime,TStart,TEnd);
	bool boolFob = MysqlFOB(strSqlFOB,m_fobCollect,yearTable,tmp_YearTime,TStart,TEnd);
	if(boolColor)
	{
		bool bok = false;
		QSqlQuery query = m_MySql->ExecuteSqlQuery(strSqlColor, bok);
		while (query.next())
		{
			RecordData dataRecord;
			dataRecord.UID = query.value(0).toInt();
			dataRecord.TInsEnd = query.value(1).toDateTime();
			dataRecord.Item00 = query.value(2).toString();
			dataRecord.Item01 = query.value(3).toString();
			dataRecord.Item02 = query.value(4).toString();
			dataRecord.Item03 = query.value(5).toString();
			dataRecord.Item04 = query.value(6).toString();
			dataRecord.Item10 = query.value(7).toString();
			dataRecord.Item11 = query.value(8).toString();
			dataRecord.Address = query.value(9).toString();
			dataColor.push_back(dataRecord);
		}
	}
	if(boolCell)
	{
		bool bok = false;
		QSqlQuery query = m_MySql->ExecuteSqlQuery(strSqlCell, bok);
		while (query.next())
		{
			RecordData dataRecord;
			dataRecord.UID = query.value(0).toInt();
			dataRecord.TInsEnd = query.value(1).toDateTime();
			dataRecord.Item00 = query.value(2).toString();
			dataRecord.Item01 = query.value(3).toString();
			dataRecord.Item02 = query.value(4).toString();
			dataRecord.Item03 = query.value(5).toString();
			dataRecord.Item04 = query.value(6).toString();
			dataRecord.Item10 = query.value(7).toString();
			dataRecord.Item11 = query.value(8).toString();
			dataRecord.Address = query.value(9).toString();
			dataCell.push_back(dataRecord);
		}
	}
	if(boolFob)
	{
		bool bok = false;
		QSqlQuery query = m_MySql->ExecuteSqlQuery(strSqlFOB, bok);
		while (query.next())
		{
			RecordData dataRecord;
			dataRecord.UID = query.value(0).toInt();
			dataRecord.TInsEnd = query.value(1).toDateTime();
			dataRecord.Item00 = query.value(2).toString();
			dataRecord.Item01 = query.value(3).toString();
			dataRecord.Item02 = query.value(4).toString();
			dataRecord.Item03 = query.value(5).toString();
			dataRecord.Item04 = query.value(6).toString();
			dataRecord.Item10 = query.value(7).toString();
			dataRecord.Item11 = query.value(8).toString();
			dataRecord.Address = query.value(9).toString();
			dataFob.push_back(dataRecord);
		}
	}
	return true;
}