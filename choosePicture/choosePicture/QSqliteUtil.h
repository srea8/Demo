#ifndef QSQLITEUTIL_H
#define QSQLITEUTIL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include "SemMgr.h"

struct DbConectInfo
{
	QString qstrDbType;
	QString qstrDbName;
	QString qstrDbIp;
	int     qstrDbPort;
	QString qstrDbUserName;
	QString qstrDbPassWord;
};


class QSqliteUtil
{
public:
	explicit QSqliteUtil(const QString& strDatabase = "smart.db");
	explicit QSqliteUtil(const DbConectInfo & qstrDatabaseInfo);
	~QSqliteUtil();

	bool createConnection(const QString& strConn);
	bool JudgeDatabaseConnect();

	QSqlRecord ExecuteRecord(const QString& strQuery,bool&);
	QSqlRecord ExecuteRecord(const QString& strQuery, QList<QVariant> lstParameter,bool&);
	QSqlRecord ExecuteRecord(const QString& strQuery, QVariant Parameter,bool&);

	QSqlQuery ExecuteSqlQuery(const QString& strQuery, QList<QVariant> lstParameter,bool&);
	QSqlQuery ExecuteSqlQuery(const QString& strQuery, QVariant Parameter,bool&);
	QSqlQuery ExecuteSqlQuery(const QString& strQuery,bool&);

	int ExecuteInt(const QString& strQuery,bool&);
	int ExecuteInt(const QString& strQuery, QList<QVariant> lstParameter,bool&);
	int ExecuteInt(const QString& strQuery, QVariant Parameter,bool&);

	bool Execute(const QString& strQuery, QVariant Parameter);
	bool Execute(const QString& strQuery, QList<QVariant> lstParameter);

	QString ExecuteString(const QString& strQuery,bool&);

	void ExecuteQueryModel(QSqlQueryModel *p_queryModel, const QString& strQuery);
	void ExecuteQueryModel(QSqlQueryModel *p_queryModel, const QString& strQuery,
		QList<QVariant> lstParameter);
	void ExecuteQueryModel(QSqlQueryModel *p_queryModel, const QString& strQuery, QVariant Parameter);

	QSqlDatabase  GetsqlDB() {return m_db;}

private:
	QSqlDatabase m_db;
	QString m_strDatabase;
	DbConectInfo  m_dbInfo;
	bool m_CreatDatabaseFlag;
	HANDLE m_semInfo;
};

#endif // QSQLITEUTIL_H