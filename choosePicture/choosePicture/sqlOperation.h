#ifndef _SQLOPERATION_H_
#define _SQLOPERATION_H_

#include "QSqliteUtil.h"
#include <Qstring>
#include <list>
#include <QDateTime>
#include "TypeDef.h"
using namespace std;
struct UserPri 
{
	int UID;
	QString name;
	QString passwd;
	QString privilege;//权限：manager-管理员 common-普通
	QString   qstrState; //是否在职
	UserPri()
	{
		UID = -1;
		qstrState = QStringLiteral("否");
	}
};

struct RecordData
{
	int RID;      //记录编号，自动生成，关键字
	QString SampleCode;  //医生手动输入的编号或者扫描条形码
	QDateTime StartDetectTime;   //样本开始检测时间20160417121010
	QDateTime EndDetectTime;     //样本检测结束时间
	//string DetectDoctor;     //检测医生
	int UID;      //用户ID
	int  QJD; //清洁度
	BOOL MJ;   //霉菌有无，0代表无，1代表有
	BOOL DC;   //滴虫有无，0代表无，1代表有
	DOUBLE PH;     // PH值
	int H202;    //过氧化氢的值
	int LE;     //白细胞酯酶
	int PA;     //多胺酶
	int SNA;     //唾液酸酶
	BOOL ok;       //0代表没有确认，1代表已确认
	int xStep;
	int yStep;
	int WarningState;
	QString remark;
	RecordData()
	{
		ok = false;
		xStep = 10;
		yStep = 3;
		WarningState = 0;
	}

};

struct AlgData
{
	int RID;      // 表2传入的记录ID
	int type;     // 结果类型 1-霉菌，2-白细胞，3-上皮细胞，4-球菌，5-杆菌，6-滴虫，7-清洁度，8-ph值，9-过氧化氢的值，10-白细胞酯酶，11-多胺，12-唾液酸酶
	int viewNum;  // 视野编号
	int picNum;   // 图像序号
	int CellNum;  // 各种细胞类型的数量或值
	int Left;
	int Top;
	int Width;
	int Height;
	AlgData()
	{
		Left = 0;
		Top = 0;
		Width = 0;
		Height = 0;
	}
};

struct ErrorInfo 
{
	int RID;
	int BV;
	QDateTime startTime;
	int MD;
	ErrorInfo()
	{
		BV = 0;
		MD = 0;
	}
};

struct MaterialNum
{
	int ColorNum;
	int GlassNum;
	MaterialNum()
	{
		ColorNum = 0;
		GlassNum = 0;
	}
};

class sqlOperation
{
public:
	sqlOperation();
	~sqlOperation();
	//表1
	bool InsertUserData(UserPri data);//插入记录数据
	bool GetUserDatabyName(UserPri& data);//根据名字查询信息
	bool GetUserData(UserPri &data);//查询记录数据
	bool DeleteUserData(UserPri data);//删除记录数据
	bool UpdateUserData(UserPri data);//更新记录数据
	bool GetProductNameList(list<UserPri> &lstProduct);
	//表2
	bool InsertRecordData(RecordData &data);//插入记录数据
	bool GetRecordData(RecordData &data);//根据RID查询记录数据
	bool GetRecordDataFromTDCode(RecordData &data);//根据条形码查询记录数据
	bool GetRecordDataFromCode(RecordData &data);//根据RID和日期查询记录数据
	bool sqlOperation::GetRecordDataFromTime(list<RecordData> &lstRecordDate,RecordData &data, vector<bool*> m_vState, int ifok);
	bool GetRecordDateList(list<RecordData> &lstRecordDate);//将record所有数据提取出来以便于根据日期进行筛选
	bool DeleteRecordData(RecordData data);//删除记录数据
	bool UpdateRecordData(RecordData data);//更新记录数据
	

	//表3
	bool InsertAlgData(AlgData data);//插入算法结果数据
 	bool GetAlgData(AlgData &data);//查询算法结果数据
	bool DeleteAlgDataInfo(AlgData data);//删除一条信息
 	bool DeleteAlgData(AlgData data);//删除算法结果数据
 	bool UpdateAlgData(AlgData data);//更新算法结果数据
	bool UpdateAlgDataRect(AlgData data);
	bool UpdateCellNum(AlgData data);
	bool GetAlgDataRect(AlgData &data);
	QSqlDatabase GetSqlDB() {return m_MySql->GetsqlDB();};
	QSqliteUtil*    m_MySql;

	//表4
	bool InsertErrorData(ErrorInfo data);
	bool UpdateErrorData(ErrorInfo data);
	bool GetErrorData(ErrorInfo &data);
	bool GetErrorDataList(list<ErrorInfo> &ErrorData);
	bool DeleteErrorData(ErrorInfo data);

	//表5
	bool UpdateMaterialDataColor(MaterialNum data);
	bool UpdateMaterialDataGlass(MaterialNum data);
	bool GetMaterialData(MaterialNum &data);
protected:

private:
	
};
#endif