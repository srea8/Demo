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
	QString privilege;//Ȩ�ޣ�manager-����Ա common-��ͨ
	QString   qstrState; //�Ƿ���ְ
	UserPri()
	{
		UID = -1;
		qstrState = QStringLiteral("��");
	}
};

struct RecordData
{
	int RID;      //��¼��ţ��Զ����ɣ��ؼ���
	QString SampleCode;  //ҽ���ֶ�����ı�Ż���ɨ��������
	QDateTime StartDetectTime;   //������ʼ���ʱ��20160417121010
	QDateTime EndDetectTime;     //����������ʱ��
	//string DetectDoctor;     //���ҽ��
	int UID;      //�û�ID
	int  QJD; //����
	BOOL MJ;   //ù�����ޣ�0�����ޣ�1������
	BOOL DC;   //�γ����ޣ�0�����ޣ�1������
	DOUBLE PH;     // PHֵ
	int H202;    //���������ֵ
	int LE;     //��ϸ����ø
	int PA;     //�షø
	int SNA;     //��Һ��ø
	BOOL ok;       //0����û��ȷ�ϣ�1������ȷ��
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
	int RID;      // ��2����ļ�¼ID
	int type;     // ������� 1-ù����2-��ϸ����3-��Ƥϸ����4-�����5-�˾���6-�γ棬7-���ȣ�8-phֵ��9-���������ֵ��10-��ϸ����ø��11-�ష��12-��Һ��ø
	int viewNum;  // ��Ұ���
	int picNum;   // ͼ�����
	int CellNum;  // ����ϸ�����͵�������ֵ
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
	//��1
	bool InsertUserData(UserPri data);//�����¼����
	bool GetUserDatabyName(UserPri& data);//�������ֲ�ѯ��Ϣ
	bool GetUserData(UserPri &data);//��ѯ��¼����
	bool DeleteUserData(UserPri data);//ɾ����¼����
	bool UpdateUserData(UserPri data);//���¼�¼����
	bool GetProductNameList(list<UserPri> &lstProduct);
	//��2
	bool InsertRecordData(RecordData &data);//�����¼����
	bool GetRecordData(RecordData &data);//����RID��ѯ��¼����
	bool GetRecordDataFromTDCode(RecordData &data);//�����������ѯ��¼����
	bool GetRecordDataFromCode(RecordData &data);//����RID�����ڲ�ѯ��¼����
	bool sqlOperation::GetRecordDataFromTime(list<RecordData> &lstRecordDate,RecordData &data, vector<bool*> m_vState, int ifok);
	bool GetRecordDateList(list<RecordData> &lstRecordDate);//��record����������ȡ�����Ա��ڸ������ڽ���ɸѡ
	bool DeleteRecordData(RecordData data);//ɾ����¼����
	bool UpdateRecordData(RecordData data);//���¼�¼����
	

	//��3
	bool InsertAlgData(AlgData data);//�����㷨�������
 	bool GetAlgData(AlgData &data);//��ѯ�㷨�������
	bool DeleteAlgDataInfo(AlgData data);//ɾ��һ����Ϣ
 	bool DeleteAlgData(AlgData data);//ɾ���㷨�������
 	bool UpdateAlgData(AlgData data);//�����㷨�������
	bool UpdateAlgDataRect(AlgData data);
	bool UpdateCellNum(AlgData data);
	bool GetAlgDataRect(AlgData &data);
	QSqlDatabase GetSqlDB() {return m_MySql->GetsqlDB();};
	QSqliteUtil*    m_MySql;

	//��4
	bool InsertErrorData(ErrorInfo data);
	bool UpdateErrorData(ErrorInfo data);
	bool GetErrorData(ErrorInfo &data);
	bool GetErrorDataList(list<ErrorInfo> &ErrorData);
	bool DeleteErrorData(ErrorInfo data);

	//��5
	bool UpdateMaterialDataColor(MaterialNum data);
	bool UpdateMaterialDataGlass(MaterialNum data);
	bool GetMaterialData(MaterialNum &data);
protected:

private:
	
};
#endif