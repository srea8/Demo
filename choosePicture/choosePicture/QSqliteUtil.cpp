#include "qsqliteutil.h"
#include <QDebug>


QSqliteUtil::QSqliteUtil(const QString &strDatabase) :
	m_strDatabase(strDatabase)
{
	m_semInfo = CreateSemaphore(0, 1, 1, NULL);
	m_dbInfo.qstrDbType = "Sqlite";
	m_dbInfo.qstrDbName = strDatabase;
	m_CreatDatabaseFlag = true;
	createConnection(m_strDatabase);
}

QSqliteUtil::QSqliteUtil(const DbConectInfo & qstrDatabaseInfo)
{
	m_semInfo = CreateSemaphore(0, 1, 1, NULL);
	m_dbInfo.qstrDbType = qstrDatabaseInfo.qstrDbType;
	m_dbInfo = qstrDatabaseInfo;
	m_CreatDatabaseFlag = true;
	createConnection(m_strDatabase);
}

QSqliteUtil::~QSqliteUtil()
{
	m_db.close(); 
}

bool QSqliteUtil::createConnection(const QString &database)
{
	////与数据库建立连接
	if (m_dbInfo.qstrDbType == "Sqlite")
	{
		if (QSqlDatabase::contains("my_conn_rect"))
		{
			m_db = QSqlDatabase::database("my_conn_rect");
		}
		else
		{
			m_db = QSqlDatabase::addDatabase("QSQLITE", "my_conn_rect");
		}
		//设置数据库名
		m_db.setDatabaseName(m_dbInfo.qstrDbName);

	}

	else if (m_dbInfo.qstrDbType == "MySql")
	{
		if (QSqlDatabase::contains("my_conn"))
		{
			m_db = QSqlDatabase::database("my_conn");
		}
		else
		{
			m_db = QSqlDatabase::addDatabase("QMYSQL", "my_conn");
		}
		m_db.setHostName(m_dbInfo.qstrDbIp);  //设置数据库所在位置
		m_db.setPort(m_dbInfo.qstrDbPort);
		m_db.setUserName(m_dbInfo.qstrDbUserName);       //设置数据库的用户名
		m_db.setPassword(m_dbInfo.qstrDbPassWord);     //设置数据库的密码
		m_db.setDatabaseName(m_dbInfo.qstrDbName);  //设置数据库名称
	}


	//打开数据库
	if (!m_db.open())
	{
		qDebug() << "     打开数据库失败!";
		QSqlError err = m_db.lastError();
		m_CreatDatabaseFlag = false;
		return false;
	}
	else
	{
		return true;
	}
}


QSqlRecord QSqliteUtil::ExecuteRecord(const QString& strQuery,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK = query.prepare(strQuery);
	bOK =  query.exec();
	return query.record();
}

QSqlRecord QSqliteUtil::ExecuteRecord(const QString& strQuery, QList<QVariant> lstParameter,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK = query.prepare(strQuery);
	QString str;
	if(!bOK)
		str = query.lastError().text();
	for(int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	bOK = query.exec();
	if(!bOK)
		str = query.lastError().text();
	return query.record();
}

QSqlRecord QSqliteUtil::ExecuteRecord(const QString& strQuery, QVariant Parameter,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK = query.prepare(strQuery);
	query.bindValue(0, Parameter);
	bOK = query.exec();
	return query.record();
}

QSqlQuery QSqliteUtil::ExecuteSqlQuery(const QString& strQuery, QList<QVariant> lstParameter,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK = query.prepare(strQuery);
	QString str;
	if(!bOK)
		str = query.lastError().text();
	query.setForwardOnly(true);
	for(int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);	
	bOK =  query.exec();
	if(!bOK)
		str = query.lastError().text();
	return query;
}

QSqlQuery QSqliteUtil::ExecuteSqlQuery(const QString& strQuery, QVariant Parameter,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	query.setForwardOnly(true);
	bOK =  query.prepare(strQuery);
	query.bindValue(0, Parameter);
	bOK =  query.exec();
	return query;
}

QSqlQuery QSqliteUtil::ExecuteSqlQuery(const QString& strQuery,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	query.setForwardOnly(true);
	bOK = query.prepare(strQuery);
	QString str;
	if(!bOK)
		str = query.lastError().text();
	bOK = query.exec();
	if(!bOK)
		str = query.lastError().text();
	return query;
}

int QSqliteUtil::ExecuteInt(const QString& strQuery,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK =  query.prepare(strQuery);
	bOK =  query.exec();
	int ID = 0;
	while(query.next())
	{
		ID = query.value(0).toInt();
	}
	return ID;
}

int QSqliteUtil::ExecuteInt(const QString& strQuery, QList<QVariant> lstParameter,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK =  query.prepare(strQuery);
	for(int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	bOK =  query.exec();
	int ID = 0;
	while(query.next())
	{
		ID = query.value(0).toInt();
	}
	return ID;
}

int QSqliteUtil::ExecuteInt(const QString& strQuery, QVariant Parameter,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK =  query.prepare(strQuery);
	query.bindValue(0, Parameter);
	bOK =  query.exec();
	int ID = 0;
	while(query.next())
	{
		ID = query.value(0).toInt();
	}
	return ID;
}

bool QSqliteUtil::Execute(const QString& strQuery, QVariant Parameter)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	return query.exec();
}

bool QSqliteUtil::Execute(const QString& strQuery, QList<QVariant> lstParameter)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	for(int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	bool bl =  query.exec();
	QSqlError err= query.lastError();
	return bl;
}

QString QSqliteUtil::ExecuteString(const QString& strQuery,bool& bOK)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	bOK = query.prepare(strQuery);
	bOK = query.exec();
	QString temp;
	while(query.next())
	{
		temp = query.value(0).toString();
	}
	return temp;
}

void QSqliteUtil::ExecuteQueryModel(QSqlQueryModel *p_queryModel, const QString& strQuery)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	p_queryModel->setQuery(strQuery, m_db);
}

void QSqliteUtil::ExecuteQueryModel(QSqlQueryModel *p_queryModel, const QString& strQuery,
								   QList<QVariant> lstParameter)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	for(int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	p_queryModel->setQuery(query);
}

void QSqliteUtil::ExecuteQueryModel(QSqlQueryModel *p_queryModel, const QString& strQuery,
								   QVariant Parameter)
{
	SemMgr sem(m_semInfo);
	if(!m_db.isOpen())
	{
		createConnection(m_strDatabase);
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	p_queryModel->setQuery(query);
}

bool QSqliteUtil::JudgeDatabaseConnect()
{
	SemMgr sem(m_semInfo);
	if (m_CreatDatabaseFlag == false)
	{
		return false;
	}
	return true;
}