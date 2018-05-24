#ifndef CHOOSEPICTURE_H
#define CHOOSEPICTURE_H

#include <QtWidgets/QMainWindow>
#include "ui_choosepicture.h"
#include <QDateTime>
#include<direct.h>
#include <stdio.h>
#include <process.h>
#include "sqlAfs.h"

class choosePicture : public QMainWindow
{
	Q_OBJECT

public:
	choosePicture(QWidget *parent = 0);
	~choosePicture();
	/*void GetCheckBoxChoose();*/
	vector<vector<int>> checkCollect;
	vector<int> iniConfig;
	vector<int> colorCheck;
	vector<int> cellCheck;
	//vector<int> shapeCheck;
	vector<int> fobCheck;

signals:
	void AppendText(const QString &text);

signals:
	void AppendCountPicText(int numCurrent, int numAll, int UIDNum);
	void AppendCountPicText(int numCurrent, int numAll);
	void graphics(QString strNames);
	//void FilePath();
	void AppendprogressBar(int,int);

private:
	Ui::choosePictureClass ui;
	QString GetCurTime();
	void CreateDefineFile(string filename);
	int ReadFileExist(string filename);
	int WriteFileExist(string filename, QString str);
	void connectSetIni();
	void onCheckClickIni();
	void DetectionItems();
	void GetCheckBoxChoose();
	list<RecordData> m_dataCell;
	list<RecordData> m_dataColor;
	list<RecordData> m_dataFob;
	static unsigned _stdcall FindButton(void *laParamter);
	static unsigned _stdcall SavePic(void *laParamter);
	void getFilesBmp(string path, vector<string>& files);
	void getFilesJpg(string path, vector<string>& files);
	int GetSubFolders(string& folder, vector<string>& subFolders);
	vector<string> copyTmpJpgPicturePath;
	vector<string> copyTmpBmpPicturePath;
	vector<string> copyCellPicturePath;
	vector<string> copyFobPicturePath;
	vector<string> copyFobYangPicturePath;
	vector<string> copyColorPicturePath;
	vector<string> copyPicturePath;
	vector<string>::iterator copyIterator;
	int numAllSample;
	int numCurrentSample;
	int countSample;
	int m_flag;
	int signalFind;
	int signalCopy;
	int signalSave;
	sqlAfs m_mySql;
	string FolderPath;
	string FolderPathLog;
	string FolderPathLogFile;
	string FileSavePath;
	string FileDataSavePath;
	string FileDataTmpSavePath;
	string FilePhotoSavePath;
	string FileCellPhotoSavePath;
	string FileColorPhotoSavePath;
	string FileFOBPhotoSavePath;
	string FileFOBYangPhotoSavePath;
	string FileCsvPath;
	string flag;
	HANDLE hThread_Find;
	HANDLE hThread_Copy;
	HANDLE g_hThreadParamter;
	HANDLE p_hThreadParamter;
	QImage *image;
	QImage *imgScaled;
	QGraphicsScene *sceneview;
	RecordData FirstData;
	QString FilePicPath;
	QString tmpWriteData;
	QString file_path;
	SYSTEMTIME currentTime;

private slots:
	void SlotAppendCountPicText(int numCurrent, int numAll, int UIDNum);
	void SlotAppendCountPicText(int numCurrent, int numAll);
	void SlotAppendText(const QString &text);
	void SlotgetAllCellCheckBox();
	void SlotgetCellCheckBox();
	void SlotgetAllColorCheckBox();
	void SlotgetColorCheckBox();
	void SlotgetAllFobCheckBox();
	void SlotgetFobCheckBox();
	void SlotgetAllTraitsCheckBox();
	void SlotgetTraitsCheckBox();
	void on_Find_Button_clicked();
	void on_leftTurn_clicked();
	void on_RightTurn_clicked();
	void on_LeftUid_clicked();
	void on_RightUid_clicked();
	void on_Save_Pic_clicked();
	void Slotgraphics(QString strNames);
	//void SlotFilePath();
	void SoltprogressBar(int numCurrentSample,int numAllSample);
};

#endif // CHOOSEPICTURE_H
