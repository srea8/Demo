#include "sqlOperation.h"
#include <qdatetime.h>
sqlOperation::sqlOperation()
{
	DbConectInfo m_dbInfo;
	m_dbInfo.qstrDbIp       = "localhost";
	m_dbInfo.qstrDbPort     = 3306;
	m_dbInfo.qstrDbUserName = "root";
	m_dbInfo.qstrDbPassWord = "123456";
	m_dbInfo.qstrDbName     = "vdadetect";
	m_dbInfo.qstrDbType     = "MySql";
	m_MySql= new QSqliteUtil(m_dbInfo);

};

sqlOperation::~sqlOperation()
{
	int  i = 344;
};

// 医生用户表

bool sqlOperation::InsertUserData(UserPri data)
{
	bool bok = false;
	

	QString strSql = QStringLiteral("insert into user\
									(name,passwd,privilege) values ('")\
									+data.name     + QStringLiteral("','")
									+data.passwd   + QStringLiteral("','")
									+data.privilege+ QStringLiteral("');");					
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	QString s = query.lastError().text();
	return bok;
}

bool sqlOperation::GetUserDatabyName(UserPri& data)
{
	QString strSql = QStringLiteral("select * from user where name = '")
			+data.name+"';";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	QString s = query.lastError().text();
	if(!bok) return bok;
	bool bfind = false;

	while (query.next())
	{
		bfind = true;
		int t =query.value(0).toInt();
		data.UID        = query.value(0).toInt();
		data.passwd     = query.value(2).toString();
		data.privilege  = query.value(3).toString();
		data.qstrState  = query.value(4).toString();
	}
	return bfind;
}

bool sqlOperation::GetUserData(UserPri &data)
{
	QString strSql = QStringLiteral("select * from user where UID = ")
		+QString::number(data.UID)+";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
		QString s = query.lastError().text();
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.name     = query.value(1).toString();
		data.passwd   = query.value(2).toString();
		data.privilege= query.value(3).toString();
	}
	return bfind;
}

bool sqlOperation::DeleteUserData(UserPri data)
{
	bool bok = false;
	QString sqlStr = QStringLiteral("delete from user where UID =")
		+QString::number(data.UID)+";";
	QSqlQuery query = m_MySql->ExecuteSqlQuery(sqlStr,bok);
	return bok;
}

bool sqlOperation::UpdateUserData(UserPri data)
{
	QString strSql = QStringLiteral("update user set ")
		+"name='"	        +data.name
		+"',passwd='"	    +data.passwd
		+"',privilege='"	+data.privilege		
		+QStringLiteral("' where UID = ")+ QString::number(data.UID);

	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	QString s = query.lastError().text();
	return bok;
}

bool sqlOperation::GetProductNameList(list<UserPri> &lstProduct)
{
	QString strSql = "select * from user";
	bool bOK = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bOK);
	if(!bOK)
		return bOK;
	bool bFind = false;
	while (query.next())
	{
		bFind = true;
		UserPri info;
		info.UID       = query.value(0).toInt();
		info.name      = query.value(1).toString();
		info.passwd    = query.value(2).toString();
		info.privilege = query.value(3).toString();
		lstProduct.push_back(info);
	}
	return bFind;
}

// 病人信息表

bool sqlOperation::InsertRecordData(RecordData &data)
{
	bool bok = false;

	QString strSql = QStringLiteral("insert into record\
									(SampleCode,StartDetectTime,EndDetectTime,UID,xstep,ystep) values (?,?,?,?,?,?)");

	QVariant var;
    QList<QVariant> listVar;
	var.setValue(data.SampleCode);
	listVar.push_back(var);
	var.setValue(data.StartDetectTime);
	listVar.push_back(var);
	var.setValue(data.EndDetectTime);
	listVar.push_back(var);
	var.setValue(data.UID);
	listVar.push_back(var);
	var.setValue(data.xStep);
	listVar.push_back(var);
	var.setValue(data.yStep);
	listVar.push_back(var);
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,listVar,bok);
	data.RID  = query.lastInsertId().toInt();
	return bok;
}

bool sqlOperation::GetRecordData(RecordData &data)
{
	QString strSql = QStringLiteral("select * from record where RID = ")
		+QString::number(data.RID)+";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	//	QString s = query.lastError().text();
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.SampleCode      = query.value(1).toString();
		data.StartDetectTime = query.value(2).toDateTime();
		data.EndDetectTime   = query.value(3).toDateTime();
		data.UID             = query.value(4).toInt();
		data.QJD             = query.value(5).toInt();
		data.MJ              = query.value(6).toInt();
		data.DC              = query.value(7).toInt();
		data.PH              = query.value(8).toDouble();
		data.H202            = query.value(9).toInt();
		data.LE              = query.value(10).toInt();
		data.PA              = query.value(11).toInt();
		data.SNA             = query.value(12).toInt();
		data.ok              = query.value(13).toInt();
		data.xStep           = query.value(14).toInt();
		data.yStep           = query.value(15).toInt();
		data.WarningState    = query.value(16).toInt();
		data.remark          = query.value(17).toString();
	}
	return bfind;
}

bool sqlOperation::GetRecordDataFromTDCode(RecordData &data)
{
	QString strSql = QStringLiteral("select * from record where SampleCode = '") 
		+ data.SampleCode + "';";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.RID             = query.value(0).toInt();
		data.SampleCode      = query.value(1).toString();
		data.StartDetectTime = query.value(2).toDateTime();
		data.EndDetectTime   = query.value(3).toDateTime();
		data.UID             = query.value(4).toInt();
		data.QJD             = query.value(5).toInt();
		data.MJ              = query.value(6).toInt();
		data.DC              = query.value(7).toInt();
		data.PH              = query.value(8).toDouble();
		data.H202            = query.value(9).toInt();
		data.LE              = query.value(10).toInt();
		data.PA              = query.value(11).toInt();
		data.SNA             = query.value(12).toInt();
		data.ok              = query.value(13).toInt();
		data.xStep           = query.value(14).toInt();
		data.yStep           = query.value(15).toInt();
		data.WarningState    = query.value(16).toInt();
		data.remark          = query.value(17).toString();
	}
	return bfind;
}

bool sqlOperation::GetRecordDataFromCode(RecordData &data)
{
	QString tempNum;
	tempNum.setNum(data.RID);
	QString strSql = QStringLiteral("select * from record where StartDetectTime > ") 
		+data.StartDetectTime.toString("yyyyMMddhhmmss") + QStringLiteral(" and EndDetectTime < ")
		+data.EndDetectTime.toString("yyyyMMddhhmmss") + " and RID = "
		+ tempNum +";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	//	QString s = query.lastError().text();
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.RID             = query.value(0).toInt();
		data.SampleCode      = query.value(1).toString();
		data.StartDetectTime = query.value(2).toDateTime();
		data.EndDetectTime   = query.value(3).toDateTime();
		data.UID             = query.value(4).toInt();
		data.QJD             = query.value(5).toInt();
		data.MJ              = query.value(6).toInt();
		data.DC              = query.value(7).toInt();
		data.PH              = query.value(8).toDouble();
		data.H202            = query.value(9).toInt();
		data.LE              = query.value(10).toInt();
		data.PA              = query.value(11).toInt();
		data.SNA             = query.value(12).toInt();
		data.ok              = query.value(13).toInt();
		data.xStep           = query.value(14).toInt();
		data.yStep           = query.value(15).toInt();
		data.WarningState    = query.value(16).toInt();
		data.remark          = query.value(17).toString();
	}
	return bfind;
}

bool sqlOperation::GetRecordDataFromTime(list<RecordData> &lstRecordDate,RecordData &data, vector<bool*> m_vState, int ifok)
{
	QString strSql = QStringLiteral("select * from record where StartDetectTime >= ")\
		+(data.StartDetectTime).toString("yyyyMMddhhmmss") + QStringLiteral(" and EndDetectTime <= ") \
		+(data.EndDetectTime).toString("yyyyMMddhhmmss");
	if (ifok == 0 || ifok == 1)
	{
		strSql += QStringLiteral(" and ok = ") + QString::number(ifok);
	}
	QString addString;
	QString arrayString[7] = {"QJD", "MJ", "DC", "HO", "LE", "PA", "SNA"};
	for (int k = 0; k < 7; ++k)
	{
		bool*temp = m_vState[k];
		if (temp[0])
		{
			continue;
		}
		if (k == 1 || k == 2)
		{
			bool isfirst = false;
			if (temp[1] && temp[2] || (!temp[1] && !temp[2]))
			{
				continue;
			}
			else if(temp[1] && !temp[2])
			{
				addString += QStringLiteral(" and (%1>%2)").arg(arrayString[k], QString::number(0));
			}
			else if(!temp[1] && temp[2])
			{
				addString += QStringLiteral(" and (%1=%2)").arg(arrayString[k], QString::number(0));
			}
		}
		else
		{
			bool isfirst = false;
			for (int t = 1; t < 6; ++t)
			{
				if (temp[t])
				{
					if (isfirst)
					{
						addString += QStringLiteral(" or %1=%2").arg(arrayString[k], QString::number(t));
					}
					else
					{
						addString += QStringLiteral(" and (%1=%2").arg(arrayString[k], QString::number(t));
						isfirst = true;
					}
				}
			}
			if (isfirst)
			{
				addString += ")";
			}
		}
		
	}
	addString += ";";
	strSql += addString;

	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	if (!bok)
	{
		QString s = query.lastError().text();
		s = s;
	}		
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.RID             = query.value(0).toInt();
		data.SampleCode      = query.value(1).toString();
		data.StartDetectTime = query.value(2).toDateTime();
		data.EndDetectTime   = query.value(3).toDateTime();
		data.UID             = query.value(4).toInt();
		data.QJD             = query.value(5).toInt();
		data.MJ              = query.value(6).toInt();
		data.DC              = query.value(7).toInt();
		data.PH              = query.value(8).toDouble();
		data.H202            = query.value(9).toInt();
		data.LE              = query.value(10).toInt();
		data.PA              = query.value(11).toInt();
		data.SNA             = query.value(12).toInt();
		data.ok              = query.value(13).toInt();
		data.xStep           = query.value(14).toInt();
		data.yStep           = query.value(15).toInt();
		data.WarningState    = query.value(16).toInt();
		data.remark          = query.value(17).toString();
		lstRecordDate.push_back(data);
	}
	return bfind;
}

bool sqlOperation::DeleteRecordData(RecordData data)
{
	bool bok = false;
	QString sqlStr = QStringLiteral("delete from record where RID =")
		+QString::number(data.RID)+";";
	QSqlQuery query = m_MySql->ExecuteSqlQuery(sqlStr,bok);
	return bok;
}

bool sqlOperation::UpdateRecordData(RecordData data)
{
	QString strSql = QStringLiteral("update record set ")
		+"SampleCode='"      + data.SampleCode+ "'"
		+",StartDetectTime=" + data.StartDetectTime.toString("yyyyMMddhhmmss")
		+",EndDetectTime="	 + data.EndDetectTime.toString("yyyyMMddhhmmss")
		+",UID="	 + QString::number(data.UID)
		+",QJD="	 + QString::number(data.QJD)
		+",MJ="	     + QString::number(data.MJ)
		+",DC="	     + QString::number(data.DC)
		+",PH="	     + QString::number(data.PH)
		+",HO="	     + QString::number(data.H202)
		+",LE="	     + QString::number(data.LE)
		+",PA="	     + QString::number(data.PA)
		+",SNA="     + QString::number(data.SNA)
		+",ok="	     + QString::number(data.ok) 
		+",xstep="	 + QString::number(data.xStep) 
		+",ystep="	 + QString::number(data.yStep) 
		+",Warning=" + QString::number(data.WarningState)
		+",Remark='"  + data.remark + "'"
		+QStringLiteral(" where RID = ")+ QString::number(data.RID)+";";

	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::GetRecordDateList(list<RecordData> &lstRecordDate)
{
	QString strSql = "select * from record";
	bool bOK = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bOK);
	if(!bOK)
		return bOK;
	bool bFind = false;
	while (query.next())
	{
		bFind = true;
		RecordData info;
		info.RID = query.value(0).toInt();
		info.SampleCode      = query.value(1).toString();
		info.StartDetectTime = query.value(2).toDateTime();
		info.EndDetectTime   = query.value(3).toDateTime();
		info.UID             = query.value(4).toInt();
		info.QJD             = query.value(5).toInt();
		info.MJ              = query.value(6).toInt();
		info.DC              = query.value(7).toInt();
		info.PH              = query.value(8).toDouble();
		info.H202            = query.value(9).toInt();
		info.LE              = query.value(10).toInt();
		info.PA              = query.value(11).toInt();
		info.SNA             = query.value(12).toInt();
		info.ok              = query.value(13).toInt();
		info.xStep           = query.value(14).toInt();
		info.yStep           = query.value(15).toInt();
		info.WarningState    = query.value(16).toInt();
		info.remark          = query.value(17).toString();
		lstRecordDate.push_back(info);
	}
	return bFind;
}

// 算法表

bool sqlOperation::InsertAlgData(AlgData data)
{
	bool bok = false;

	QString strSql = QStringLiteral("insert into algoresult(RID,type,viewNum,picNum,CellNum,Leftr,Top,Width,Height) values (")\
									+QString::number(data.RID)    +QStringLiteral(",")
									+QString::number(data.type)   +QStringLiteral(",")
									+QString::number(data.viewNum)+QStringLiteral(",")
									+QString::number(data.picNum) +QStringLiteral(",")
									+QString::number(data.CellNum)+QStringLiteral(",")
									+QString::number(data.Left)   +QStringLiteral(",")
									+QString::number(data.Top)    +QStringLiteral(",")
									+QString::number(data.Width)  +QStringLiteral(",")
									+QString::number(data.Height) +QStringLiteral(");");

	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::GetAlgData(AlgData &data)
{
	QString strSql = QStringLiteral("select * from algoresult where RID = ")
		+QString::number(data.RID)+" and type ="
		+QString::number(data.type)+";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	QString s = query.lastError().text();
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.type    = query.value(1).toInt();
		data.viewNum = query.value(2).toInt();
		data.picNum  = query.value(3).toInt();
		data.CellNum = query.value(4).toInt();
		data.Left    = query.value(5).toInt();
		data.Top     = query.value(6).toInt();
		data.Width   = query.value(7).toInt();
		data.Height  = query.value(8).toInt();
	}
	return bfind;
}

bool sqlOperation::DeleteAlgData(AlgData data)
{
	bool bok = false;
	QString sqlStr = QStringLiteral("delete from algoresult where RID =")
		+QString::number(data.RID)+";";
	QSqlQuery query = m_MySql->ExecuteSqlQuery(sqlStr,bok);
	return bok;
}

bool sqlOperation::DeleteAlgDataInfo(AlgData data)
{
	bool bok = false;
	QString sqlStr = QStringLiteral("delete from algoresult ")
		+"where RID = " + QString::number(data.RID)+     " and "
		+"type = "      + QString::number(6) +           " and "
		+"viewNum = "   + QString::number(data.viewNum)+ " and "
		+"picNum = "    + QString::number(data.picNum)+  " and "
		+"CellNum = "   + QString::number(data.CellNum)+ ";";
	QSqlQuery query = m_MySql->ExecuteSqlQuery(sqlStr,bok);
	return bok;
}

bool sqlOperation::UpdateAlgData(AlgData data)
{
	QString strSql = QStringLiteral("update algoresult set ")
		+"viewNum ="   + QString::number(data.viewNum)
		+",CellNum = " + QString::number(data.CellNum)
		+QStringLiteral(" where RID = ") + QString::number(data.RID)
		+QStringLiteral(" and type =")   + QString::number(data.type)+";";
	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::UpdateAlgDataRect(AlgData data)
{
	QString strSql = QStringLiteral("update algoresult set")
		+" `Leftr`="   +QString::number(data.Left)
		+", `Top`="    +QString::number(data.Top)
		+", `Width`="  +QString::number(data.Width)
		+", `Height`=" +QString::number(data.Height)
		+QStringLiteral(" where `RID` = ")  + QString::number(data.RID)
		+QStringLiteral(" and `type` =")    + QString::number(data.type)
		+QStringLiteral(" and `viewNum` =") + QString::number(data.viewNum)
		+QStringLiteral(" and `CellNum` =") + QString::number(data.CellNum)+";";
	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::UpdateCellNum(AlgData data)
{
	QString strSql = QStringLiteral("update algoresult set")
		+" `CellNum`="   +QString::number(data.CellNum-1)
		+QStringLiteral(" where `RID` = ")  + QString::number(data.RID)
		+QStringLiteral(" and `type` =")    + QString::number(data.type)
		+QStringLiteral(" and `viewNum` =") + QString::number(data.viewNum)
		+QStringLiteral(" and `CellNum` =") + QString::number(data.CellNum)+";";
	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::GetAlgDataRect(AlgData &data)
{
	QString strSql = QStringLiteral("select * from algoresult where `RID` = ")
		+ QString::number(data.RID)     + " and `type` ="
		+ QString::number(data.type)    + " and `viewNum` ="
		+ QString::number(data.viewNum) + " and `picNum` ="
		+ QString::number(data.picNum)  + " and `CellNum` ="
		+ QString::number(data.CellNum) + ";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	QString s = query.lastError().text();
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.Left   = query.value(5).toInt();
		data.Top    = query.value(6).toInt();
		data.Width  = query.value(7).toInt();
		data.Height = query.value(8).toInt();
	}
	return bfind;
}

// 异常表

bool sqlOperation::InsertErrorData(ErrorInfo data)
{
	bool bok = false;
	QString strSql = QStringLiteral("insert into error\
									(RID) values ('")\
									+QString::number(data.RID)+QStringLiteral("');");					
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::UpdateErrorData(ErrorInfo data)
{
	QString strSql = QStringLiteral("update error set ");
	bool isFirst = true;
	if (data.BV > 0)
	{
		strSql = strSql +"BV = "+QString::number(data.BV);
		if (data.BV == 1)
		{
			strSql = strSql +", startTime = "+data.startTime.toString("yyyyMMddhhmmss") + " ";
		}
		isFirst = false;
	}
	if (data.MD > 0)	
	{
		if (isFirst)
		{
			strSql = strSql +"MD ="+QString::number(data.MD);
		}
		else
		{
			strSql = strSql +", MD ="+QString::number(data.MD);
		}
	}
	strSql = strSql + QStringLiteral(" where RID = ") + QString::number(data.RID)+";";
	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::GetErrorData(ErrorInfo &data)
{
	QString strSql = QStringLiteral("select * from error where `RID` = ")
		+QString::number(data.RID) + ";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.BV        = query.value(1).toInt();
		data.startTime = query.value(2).toDateTime();
		data.MD        = query.value(3).toInt();
	}
	return bfind;
}

bool sqlOperation::GetErrorDataList(list<ErrorInfo> &ErrorData)
{
	QString strSql = "select * from error";
	bool bOK = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bOK);
	if(!bOK)
	{
		return bOK;
	}
	bool bFind = false;
	while (query.next())
	{
		bFind = true;
		ErrorInfo info;
		info.RID       = query.value(0).toInt();
		info.BV        = query.value(1).toInt();
		info.startTime = query.value(2).toDateTime();
		info.MD        = query.value(3).toInt();
		ErrorData.push_back(info);
	}
	return bFind;
}

bool sqlOperation::DeleteErrorData(ErrorInfo data)
{
	bool bok = false;
	QString sqlStr = QStringLiteral("delete from error where RID =")
		+QString::number(data.RID)+";";
	QSqlQuery query = m_MySql->ExecuteSqlQuery(sqlStr,bok);
	return bok;
}

// 耗材表

bool sqlOperation::UpdateMaterialDataColor(MaterialNum data)
{	
	QString strSql = QStringLiteral("update materialstate set ")
		+"Color ="   + QString::number(data.ColorNum)
		+QStringLiteral(" where ID = ") + "1"+";";
	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::UpdateMaterialDataGlass(MaterialNum data)
{	
	QString strSql = QStringLiteral("update materialstate set ")
		+"Glass = " + QString::number(data.GlassNum)
		+QStringLiteral(" where ID = ") + "1"+";";
	bool bok;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	return bok;
}

bool sqlOperation::GetMaterialData(MaterialNum &data)
{
	QString strSql = QStringLiteral("select * from vdadetect.materialstate where ID = ")
		+"1" + ";";
	bool bok = false;
	QSqlQuery query = m_MySql->ExecuteSqlQuery(strSql,bok);
	if(!bok) return bok;
	bool bfind = false;
	while (query.next())
	{
		bfind = true;
		data.ColorNum = query.value(1).toInt();
		data.GlassNum = query.value(2).toInt();
	}
	return bfind;
}