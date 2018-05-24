#include "choosepicture.h"
#include "cv.h"  
#include "highgui.h" 
#include <io.h>
#include <fstream>  
#include <sstream>  
#include <cstdlib>
#include <iostream>
#include <QTextCodec>
#include <QFileDialog>


using namespace cv;

choosePicture::choosePicture(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	numAllSample = 0;
	countSample = 0;
	numCurrentSample = 0;
	signalCopy = 0;
	signalFind = 0;
	signalSave = 0;
	m_flag = 0;
	g_hThreadParamter = CreateSemaphore(NULL,0,1,NULL);
	p_hThreadParamter = CreateSemaphore(NULL,0,1,NULL);
	onCheckClickIni();
	connectSetIni();
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
	flag="\\";
	FolderPath = "D:\\FBphoto";
	CreateDefineFile(FolderPath);
	FolderPathLog = FolderPath + "\\Log";
	CreateDefineFile(FolderPathLog);
	FileSavePath = FolderPath + "\\Photo";
	CreateDefineFile(FileSavePath);
	FileCsvPath = FileSavePath + "\\data.csv";
	FolderPathLogFile = FolderPathLog + "\\log.txt";
	ReadFileExist(FolderPathLogFile);
	this->image = new QImage();
	sceneview = NULL;
	imgScaled = NULL;
}

choosePicture::~choosePicture()
{
	delete image;
}

void choosePicture::connectSetIni()
{
	connect(this, SIGNAL(AppendText(QString)), this, SLOT(SlotAppendText(QString)));
	connect(this, SIGNAL(AppendCountPicText(int, int, int)), this, SLOT(SlotAppendCountPicText(int, int, int)));
	connect(this, SIGNAL(AppendCountPicText(int, int)), this, SLOT(SlotAppendCountPicText(int, int)));
	connect(this, SIGNAL(graphics(QString)), this, SLOT(Slotgraphics(QString)));
	//connect(this, SIGNAL(FilePath()), this, SLOT(SlotFilePath()));
	connect(this, SIGNAL(AppendprogressBar(int,int)), this, SLOT(SoltprogressBar(int,int)));
	

	connect(ui.AllCell_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetAllCellCheckBox()));
	connect(ui.RedCell_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetCellCheckBox()));
	connect(ui.Mold_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetCellCheckBox()));
	connect(ui.WhiteCell_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetCellCheckBox()));

	connect(ui.AllColor_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetAllColorCheckBox()));
	connect(ui.Black_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetColorCheckBox()));
	connect(ui.Red_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetColorCheckBox()));
	connect(ui.Yellow_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetColorCheckBox()));
	connect(ui.Brown_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetColorCheckBox()));

	connect(ui.AllFob_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetAllFobCheckBox()));
	connect(ui.Yang_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetFobCheckBox()));
	connect(ui.Yin_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetFobCheckBox()));
	connect(ui.RouYang_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetFobCheckBox()));

	connect(ui.AllTraits_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetAllTraitsCheckBox()));
	connect(ui.Soft_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetTraitsCheckBox()));
	connect(ui.Rash_checkBox, SIGNAL(clicked()), this, SLOT(SlotgetTraitsCheckBox()));
}

void choosePicture::onCheckClickIni()//初始化
{
	ui.RedCell_checkBox->setChecked(true);
	ui.Black_checkBox->setChecked(true);
	ui.Rash_checkBox->setChecked(true);
	ui.Yang_checkBox->setChecked(true);
	ui.Log_checkBox->setChecked(true);
	ui.Config_checkBox->setChecked(true);
}

void choosePicture::SlotgetAllCellCheckBox()
{
	if (ui.AllCell_checkBox->isChecked())//细胞全选
	{
		ui.RedCell_checkBox->setChecked(true);
		ui.Mold_checkBox->setChecked(true);
		ui.WhiteCell_checkBox->setChecked(true);
	}
	else
	{
		ui.RedCell_checkBox->setChecked(false);
		ui.Mold_checkBox->setChecked(false);
		ui.WhiteCell_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetCellCheckBox()
{
	////////////细胞
	if (ui.RedCell_checkBox->isChecked())
	{
		ui.AllCell_checkBox->setChecked(false);
	}
	if (ui.Mold_checkBox->isChecked())
	{
		ui.AllCell_checkBox->setChecked(false);
	}
	if (ui.WhiteCell_checkBox->isChecked())
	{
		ui.AllCell_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetAllColorCheckBox()
{
	if (ui.AllColor_checkBox->isChecked())//颜色全选
	{
		ui.Black_checkBox->setChecked(true);
		ui.Brown_checkBox->setChecked(true);
		ui.Yellow_checkBox->setChecked(true);
		ui.Red_checkBox->setChecked(true);
	}
	else
	{
		ui.Black_checkBox->setChecked(false);
		ui.Brown_checkBox->setChecked(false);
		ui.Yellow_checkBox->setChecked(false);
		ui.Red_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetColorCheckBox()
{
	//////////////颜色
	if (ui.Black_checkBox->isChecked())
	{
		ui.AllColor_checkBox->setChecked(false);
	}
	if (ui.Brown_checkBox->isChecked())
	{
		ui.AllColor_checkBox->setChecked(false);
	}
	if (ui.Yellow_checkBox->isChecked())
	{
		ui.AllColor_checkBox->setChecked(false);
	}
	if (ui.Red_checkBox->isChecked())
	{
		ui.AllColor_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetAllFobCheckBox()
{
	if (ui.AllFob_checkBox->isChecked())//Fob全选
	{
		ui.Yang_checkBox->setChecked(true);
		ui.Yin_checkBox->setChecked(true);
		ui.RouYang_checkBox->setChecked(true);
	}
	else
	{
		ui.Yang_checkBox->setChecked(false);
		ui.Yin_checkBox->setChecked(false);
		ui.RouYang_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetFobCheckBox()
{
	//////////////FOB
	if (ui.Yang_checkBox->isChecked())
	{
		ui.AllFob_checkBox->setChecked(false);
	}
	if (ui.Yin_checkBox->isChecked())
	{
		ui.AllFob_checkBox->setChecked(false);
	}
	if (ui.RouYang_checkBox->isChecked())
	{
		ui.AllFob_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetAllTraitsCheckBox()
{
	if (ui.AllTraits_checkBox->isChecked())//性状全选
	{
		ui.Soft_checkBox->setChecked(true);
		ui.Rash_checkBox->setChecked(true);
	}
	else
	{
		ui.Soft_checkBox->setChecked(false);
		ui.Rash_checkBox->setChecked(false);
	}
}

void choosePicture::SlotgetTraitsCheckBox()
{
	//////////////性状
	if (ui.Soft_checkBox->isChecked())
	{
		ui.AllTraits_checkBox->setChecked(false);
	}
	if (ui.Rash_checkBox->isChecked())
	{
		ui.AllTraits_checkBox->setChecked(false);
	}
}

void choosePicture::SlotAppendText(const QString &text)
{
	ui.Log_TextEdit->appendPlainText(text);
}

void choosePicture::SlotAppendCountPicText(int numCurrent, int numAll, int UIDNum)
{
	ui.Count_Pic->setText(QString::number(numCurrent, 10) + QStringLiteral("/") + QString::number(numAll, 10));
	ui.UID_lineEdit->setText(QString::number(UIDNum,10));
}

void choosePicture::SlotAppendCountPicText(int numCurrent, int numAll)
{
	ui.Count_Pic->setText(QString::number(numCurrent, 10) + QStringLiteral("/") + QString::number(numAll, 10));
	//ui.UID_lineEdit->setText(QString::number(UIDNum,10));
}

void choosePicture::CreateDefineFile(string filename)
{
	if (_access(filename.c_str(), 0) == -1)
	{
		_mkdir(filename.c_str());
	}
}

int choosePicture::ReadFileExist(string filename)
{
	ifstream infile;
	int n = 0;
	char line[1024];
	char* LineString;
	infile.open(filename, ios::out);
	if (!infile.is_open())
	{
		printf("Error loading txt \n");
		return -1;
	}
	else//文件存在
	{
		while (!infile.eof())
		{
			infile.getline(line, sizeof(line));
			n++;
		}
	}
	if (n > 10)
	{
		infile.close();
		infile.open(filename, std::ios::ate);
		// 先倒回文件末尾两个字符  
		infile.seekg(-2, infile.cur);
		// 假定反向读取10行记录  
		int lineCount = 10;
		for (int i = 0; i < lineCount; i++)
		{
			// 查看前一个字符是否为回车符  
			while (infile.peek() != infile.widen('\n'))
			{
				infile.seekg(-1, infile.cur);
			}
			// 走到这里表示跳过一行了，所以继续跳直到够10行  
			infile.seekg(-1, infile.cur);
		}
		infile.seekg(2, infile.cur);
		vector<string> result;
		std::string  line;
		while (getline(infile, line))
		{
			result.push_back(line);
		}
		for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
		{
			AppendText(QString::fromLocal8Bit((*it).c_str()));
		}
		infile.clear();
	}
	else
	{
		infile.close();
		infile.open(filename, std::ios::out);
		while (!infile.eof())
		{
			infile.getline(line, sizeof(line));
			LineString = line;
			QString str = QString::fromLocal8Bit(LineString);
			AppendText(str);
		}
	}
	
	infile.close();
	return 0;
}

int choosePicture::WriteFileExist(string filename , QString str)
{
	ofstream outfile;
	outfile.open(filename, ios::out|ios::app);
	char name[1024] = { NULL };
	char*  ch;
	QByteArray ba = str.toLocal8Bit(); // toLocal8Bit 支持中文
	ch = ba.data();
	strcpy(name, ch);
	if (!outfile.is_open())
	{
		printf("Error loading txt \n");
		return -1;
	}
	outfile << name << endl;
	outfile.close();
	return 0;
}

void choosePicture::GetCheckBoxChoose()
{
	iniConfig.clear();
	colorCheck.clear();
	cellCheck.clear();
	fobCheck.clear();
	//配置文件
	if (ui.Log_checkBox->isChecked())
	{
		iniConfig.push_back(1);
	}
	else
	{
		iniConfig.push_back(0);
	}

	if (ui.Config_checkBox->isChecked())
	{
		iniConfig.push_back(1);
	}
	else
	{
		iniConfig.push_back(0);
	}
	checkCollect.push_back(iniConfig);
	//细胞
	if (ui.RedCell_checkBox->isChecked())
	{
		cellCheck.push_back(1);
	}
	else
	{
		cellCheck.push_back(0);
	}

	if (ui.WhiteCell_checkBox->isChecked())
	{
		cellCheck.push_back(1);
	}
	else
	{
		cellCheck.push_back(0);
	}

	if (ui.Mold_checkBox->isChecked())
	{
		cellCheck.push_back(1);
	}
	else
	{
		cellCheck.push_back(0);
	}
	checkCollect.push_back(cellCheck);
	//颜色
	if (ui.Yellow_checkBox->isChecked())
	{
		colorCheck.push_back(1);
	}
	else
	{
		colorCheck.push_back(0);
	}

	if (ui.Red_checkBox->isChecked())
	{
		colorCheck.push_back(1);
	}
	else
	{
		colorCheck.push_back(0);
	}

	if (ui.Brown_checkBox->isChecked())
	{
		colorCheck.push_back(1);
	}
	else
	{
		colorCheck.push_back(0);
	}

	if (ui.Black_checkBox->isChecked())
	{
		colorCheck.push_back(1);
	}
	else
	{
		colorCheck.push_back(0);
	}
	//checkCollect.push_back(colorCheck);
	//性状
	if (ui.Rash_checkBox->isChecked())
	{
		colorCheck.push_back(1);
	}
	else
	{
		colorCheck.push_back(0);
	}

	if (ui.Soft_checkBox->isChecked())
	{
		colorCheck.push_back(1);
	}
	else
	{
		colorCheck.push_back(0);
	}
	checkCollect.push_back(colorCheck);
	//fob
	if (ui.Yang_checkBox->isChecked())
	{
		fobCheck.push_back(1);
	}
	else
	{
		fobCheck.push_back(0);
	}

	if (ui.RouYang_checkBox->isChecked())
	{
		fobCheck.push_back(1);
	}
	else
	{
		fobCheck.push_back(0);
	}

	if (ui.Yin_checkBox->isChecked())
	{
		fobCheck.push_back(1);
	}
	else
	{
		fobCheck.push_back(0);
	}	
	if (ui.AllcheckBox->isChecked())
	{
		fobCheck.push_back(1);
	}
	else
	{
		fobCheck.push_back(0);
	}
	checkCollect.push_back(fobCheck);
	m_mySql.SetCheckCollect(colorCheck,cellCheck,fobCheck);
}

void choosePicture::on_Find_Button_clicked()
{
	if(signalFind == 0 && (signalCopy==0 || signalSave == 1))
	{
		hThread_Find = (HANDLE)_beginthreadex(NULL,0,FindButton,this,0,NULL);
		signalFind = 1;
	}
}

unsigned _stdcall choosePicture::FindButton(void *laParamter)
{
	choosePicture* findbutton = (choosePicture*)laParamter;
	QString str_Tstart = (findbutton->ui.Start_dateEdit->date()).toString("yyyy-MM-dd");
	QString str_Tend = ((findbutton->ui.End_dateEdit->date()).addDays(1)).toString("yyyy-MM-dd");
	findbutton->GetCheckBoxChoose();
	findbutton->m_flag = 0;
	if (findbutton->ui.End_dateEdit->date().addDays(1) > findbutton->ui.Start_dateEdit->date())
	{
		QDateTime Start_T = QDateTime::fromString(str_Tstart, "yyyy-MM-dd");
		QDateTime End_T = QDateTime::fromString(str_Tend, "yyyy-MM-dd");
		findbutton->m_dataFob.clear();
		findbutton->m_dataCell.clear();
		findbutton->m_dataColor.clear();
		findbutton->copyCellPicturePath.clear();
		findbutton->copyColorPicturePath.clear();
		findbutton->copyFobPicturePath.clear();
		findbutton->copyFobYangPicturePath.clear();
		findbutton->m_mySql.GetRecordDataFromCode(findbutton->m_dataCell, findbutton->m_dataColor, findbutton->m_dataFob, Start_T, End_T);
		if (findbutton->m_dataFob.empty() && findbutton->m_dataCell.empty() && findbutton->m_dataColor.empty())
		{
			findbutton->tmpWriteData = findbutton->GetCurTime() + QStringLiteral("   ") + QStringLiteral("查询失败，没有样本（这段时间间隔）,数据库导出数据为空");
			findbutton->AppendText(findbutton->tmpWriteData);
			findbutton->WriteFileExist(findbutton->FolderPathLogFile, findbutton->tmpWriteData);
		}
		else
		{
			//numAllSample = m_data.size();
			//numCurrentSample = 1;
			//FirstData = *m_data.begin();
			//AppendCountPicText(numCurrentSample, numAllSample, FirstData.UID);
			findbutton->tmpWriteData = findbutton->GetCurTime() + QStringLiteral("   ") + QStringLiteral("查询成功，满足条件样本：细胞 ") + QString::number(findbutton->m_dataCell.size(),10) + QStringLiteral(" 个  FOB ")
				+ QString::number(findbutton->m_dataFob.size(),10) + QStringLiteral(" 个  性状")+ QString::number(findbutton->m_dataColor.size(),10) + QStringLiteral(" 个");
			findbutton->AppendText(findbutton->tmpWriteData);
			findbutton->WriteFileExist(findbutton->FolderPathLogFile, findbutton->tmpWriteData);
			for(auto it = findbutton->m_dataCell.begin(); it!=findbutton->m_dataCell.end();it++)
			{
				findbutton->copyTmpJpgPicturePath.clear();
				findbutton->copyTmpBmpPicturePath.clear();
				findbutton->getFilesBmp((*it).Address.toStdString(),findbutton->copyTmpBmpPicturePath);
				findbutton->getFilesJpg((*it).Address.toStdString(),findbutton->copyTmpJpgPicturePath);
				for(auto tmp = findbutton->copyTmpBmpPicturePath.begin(); tmp != findbutton->copyTmpBmpPicturePath.end();tmp++)
				{
					if((*tmp).rfind("MSCOPE")!=-1)
					{
						findbutton->copyCellPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
				for(auto tmp = findbutton->copyTmpJpgPicturePath.begin(); tmp != findbutton->copyTmpJpgPicturePath.end();tmp++)
				{
					if((*tmp).rfind("MSCOPE")!=-1)
					{
						findbutton->copyCellPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
			}
			for(auto it = findbutton->m_dataFob.begin(); it!=findbutton->m_dataFob.end();it++)
			{
				findbutton->copyTmpJpgPicturePath.clear();
				findbutton->copyTmpBmpPicturePath.clear();
				findbutton->getFilesBmp((*it).Address.toStdString(),findbutton->copyTmpBmpPicturePath);
				findbutton->getFilesJpg((*it).Address.toStdString(),findbutton->copyTmpJpgPicturePath);
				for(auto tmp = findbutton->copyTmpBmpPicturePath.begin(); tmp != findbutton->copyTmpBmpPicturePath.end();tmp++)
				{
					if((*tmp).rfind("FOB")!=-1)
					{
						findbutton->copyFobPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
				for(auto tmp = findbutton->copyTmpJpgPicturePath.begin(); tmp != findbutton->copyTmpJpgPicturePath.end();tmp++)
				{
					if((*tmp).rfind("FOB")!=-1)
					{
						findbutton->copyFobPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
			}
			for(auto it = findbutton->m_dataFob.begin(); it!=findbutton->m_dataFob.end();it++)
			{
				findbutton->copyTmpJpgPicturePath.clear();
				findbutton->copyTmpBmpPicturePath.clear();
				findbutton->getFilesBmp((*it).Address.toStdString(),findbutton->copyTmpBmpPicturePath);
				findbutton->getFilesJpg((*it).Address.toStdString(),findbutton->copyTmpJpgPicturePath);
				for(auto tmp = findbutton->copyTmpBmpPicturePath.begin(); tmp != findbutton->copyTmpBmpPicturePath.end();tmp++)
				{
					if((*tmp).rfind("FOB")!=-1||(*tmp).rfind("SAM")!=-1||(*tmp).rfind("MSCOPE")!=-1)
					{
						findbutton->copyFobYangPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
				for(auto tmp = findbutton->copyTmpJpgPicturePath.begin(); tmp != findbutton->copyTmpJpgPicturePath.end();tmp++)
				{
					if((*tmp).rfind("FOB")!=-1||(*tmp).rfind("SAM")!=-1||(*tmp).rfind("MSCOPE")!=-1)
					{
						findbutton->copyFobYangPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
			}
			for(auto it = findbutton->m_dataColor.begin(); it!= findbutton->m_dataColor.end();it++)
			{
				findbutton->copyTmpJpgPicturePath.clear();
				findbutton->copyTmpBmpPicturePath.clear();
				findbutton->getFilesBmp((*it).Address.toStdString(),findbutton->copyTmpBmpPicturePath);
				findbutton->getFilesJpg((*it).Address.toStdString(),findbutton->copyTmpJpgPicturePath);
				for(auto tmp = findbutton->copyTmpBmpPicturePath.begin(); tmp != findbutton->copyTmpBmpPicturePath.end();tmp++)
				{
					if((*tmp).rfind("SAM")!=-1)
					{
						findbutton->copyColorPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
				for(auto tmp = findbutton->copyTmpJpgPicturePath.begin(); tmp != findbutton->copyTmpJpgPicturePath.end();tmp++)
				{
					if((*tmp).rfind("SAM")!=-1)
					{
						findbutton->copyColorPicturePath.push_back(*tmp);
						findbutton->copyPicturePath.push_back(*tmp);
					}
				}
			}
			findbutton->numAllSample = findbutton->copyCellPicturePath.size()+ findbutton->copyColorPicturePath.size()+findbutton->copyFobPicturePath.size();
			
			if(findbutton->numAllSample!=0)
			{
				if(findbutton->copyCellPicturePath.size())
				{
					findbutton->AppendCountPicText(1, findbutton->numAllSample, (*findbutton->m_dataCell.begin()).UID);
				}
				else if(findbutton->copyColorPicturePath.size())
				{
					findbutton->AppendCountPicText(1, findbutton->numAllSample, (*findbutton->m_dataColor.begin()).UID);
				}
				else if(findbutton->copyFobPicturePath.size())
				{
					findbutton->AppendCountPicText(1, findbutton->numAllSample, (*findbutton->m_dataFob.begin()).UID);
				}
				findbutton->m_flag = 1;
				findbutton->countSample = 1;
				findbutton->graphics(QString::fromStdString(*(findbutton->copyPicturePath.begin())));
				findbutton->copyIterator = findbutton->copyPicturePath.begin();
			}
			//FilePicPath = FirstData.Address;
			//FileDataSavePath = FileSavePath + "\\" + to_string(FirstData.UID);
			////CreateDefineFile(FileDataSavePath);
			//ofstream outCsvFile;
			//outCsvFile.open(FileCsvPath, ios::out); // 打开模式可省略 
			//outCsvFile << "起始日期"<<","<<"截止日期"<<","<<"样本个数"<<endl;
			//outCsvFile << str_Tstart.toStdString() << "," << str_Tend.toStdString() << "," << numAllSample << endl;
			//outCsvFile << "用户ID" << "," << "时间" << "," << "颜色" << "," << "粪便性状" << "," << "红细胞" << "," << "白细胞" << "," << "霉菌" << "," << "FOB1" << "," << "FOB2" << "," << "文件存放地址" << endl;
			//for (auto count = m_data.begin(); count != m_data.end(); count++)
			//{
			//	outCsvFile << (*count).UID << "," << (*count).TInsEnd.toString("yyyy-MM-dd").toStdString() << "," << (*count).Item00.toStdString() << "," << (*count).Item01.toStdString() << "," << (*count).Item02.toStdString() << "," << (*count).Item03.toStdString() << "," << (*count).Item04.toStdString() << "," << (*count).Item10.toStdString() << "," << (*count).Item11.toStdString() << "," << (*count).Address.toStdString() << endl;
			//}
		}
	}
	else
	{
		findbutton->tmpWriteData = findbutton->GetCurTime() + QStringLiteral("   ") + QStringLiteral("日期输入错误(查询起始日期应小于查询截至日期)");
		findbutton->AppendText(findbutton->tmpWriteData);
		findbutton->WriteFileExist(findbutton->FolderPathLogFile, findbutton->tmpWriteData);
	}
	findbutton->signalFind = 0;
	//ReleaseSemaphore(findbutton->g_hThreadParamter,1,NULL);
	return 0;
}

void choosePicture::Slotgraphics(QString strNames)
{
	if (!strNames.isEmpty())
	{
		if (image->load(strNames))
		{
			if (sceneview)
			{
				delete sceneview;
			}
			if (imgScaled)
			{
				delete imgScaled;
			}
			sceneview = new QGraphicsScene;
			imgScaled = new QImage;
			*imgScaled = image->scaled(593, 435);
			sceneview->addPixmap(QPixmap::fromImage(*imgScaled));
			ui.img_GraphicsView->setScene(sceneview);
		}
	}
}

void choosePicture::on_Save_Pic_clicked()
{
	if(signalCopy == 0 && signalFind == 0)
	{
		file_path = QFileDialog::getExistingDirectory(this,"请选择模板保存路径...","./");  
		signalCopy = 1;
		hThread_Copy = (HANDLE)_beginthreadex(NULL,0,SavePic,this,0,NULL);	
	}
}

//void choosePicture::SlotFilePath()
//{
//	ReleaseSemaphore(p_hThreadParamter,1,NULL);
//}

unsigned _stdcall choosePicture::SavePic(void* laParamter)
{
	choosePicture* savebutton = (choosePicture*) laParamter;
	savebutton->numCurrentSample = 0;
	if(savebutton->m_flag == 0)
	{
		savebutton->signalCopy = 0;
		savebutton->tmpWriteData = savebutton->GetCurTime() + QStringLiteral("   ") + QStringLiteral("需要保存的样本为空，请先查询");
		savebutton->AppendText(savebutton->tmpWriteData);
		savebutton->WriteFileExist(savebutton->FolderPathLogFile, savebutton->tmpWriteData);
		return 0;
		savebutton->signalSave = 1;
		savebutton->on_Find_Button_clicked();
		WaitForSingleObject(savebutton->g_hThreadParamter,INFINITE);
		savebutton->signalSave = 0;
		if(savebutton->m_flag == 0)
		{
			savebutton->signalCopy = 0;
			return 0;
		}
	}
	//savebutton->FilePath();
	//WaitForSingleObject(savebutton->p_hThreadParamter,INFINITE);
	if(savebutton->file_path.isEmpty())  
	{  
		savebutton->signalCopy = 0;
		return 0;  
	}
	else
	{  
		savebutton->flag = "\\";
		savebutton->FilePhotoSavePath = string((const char*)savebutton->file_path.toLocal8Bit());
		savebutton->FilePhotoSavePath = savebutton->FilePhotoSavePath+"\\Photo";
		savebutton->CreateDefineFile(savebutton->FilePhotoSavePath);
		savebutton->FileFOBPhotoSavePath = savebutton->FilePhotoSavePath + "\\FOB";
		savebutton->FileCellPhotoSavePath =  savebutton->FilePhotoSavePath + "\\Cell";
		savebutton->FileColorPhotoSavePath = savebutton->FilePhotoSavePath + "\\SAM";
		savebutton->FileFOBYangPhotoSavePath = savebutton->FilePhotoSavePath + "\\All";
		savebutton->CreateDefineFile(savebutton->FileFOBPhotoSavePath);
		savebutton->CreateDefineFile(savebutton->FileCellPhotoSavePath);
		savebutton->CreateDefineFile(savebutton->FileColorPhotoSavePath);
		savebutton->CreateDefineFile(savebutton->FileFOBYangPhotoSavePath);
		savebutton->numAllSample = savebutton->copyCellPicturePath.size()+savebutton->copyColorPicturePath.size()+savebutton->copyFobPicturePath.size();
		for(auto tmp = savebutton->copyCellPicturePath.begin(); tmp != savebutton->copyCellPicturePath.end();tmp++)
		{
			Mat Image;
			Image = cv::imread(*tmp);
			int pos = (*tmp).rfind(savebutton->flag);
			int pos1 = (*tmp).rfind(savebutton->flag,pos-1);
			savebutton->FileDataSavePath.assign((*tmp),pos+1,(*tmp).length()-pos);
			savebutton->FileDataTmpSavePath.assign((*tmp),pos1+1,pos-pos1-1);
			//int pos = (*tmp).rfind(flag,2);
			//int pos1 = (*tmp).rfind(flag);
			//FileDataSavePath.assign(*tmp,pos+1,FileCellPhotoSavePath.length()-pos);
			//FileDataTmpSavePath.assign(*tmp,pos+1,pos-pos1);
			savebutton->FileDataTmpSavePath = savebutton->FileCellPhotoSavePath + "\\" +savebutton->FileDataTmpSavePath;
			savebutton->CreateDefineFile(savebutton->FileDataTmpSavePath);
			savebutton->FileDataTmpSavePath = savebutton->FileDataTmpSavePath + "\\" +savebutton->FileDataSavePath;
			imwrite(savebutton->FileDataTmpSavePath,Image);
			savebutton->FileDataSavePath.empty();
			savebutton->FileDataTmpSavePath.empty();
			++savebutton->numCurrentSample;
			savebutton->AppendprogressBar(savebutton->numCurrentSample,savebutton->numAllSample);
		}
		for(auto tmp = savebutton->copyColorPicturePath.begin(); tmp != savebutton->copyColorPicturePath.end();tmp++)
		{
			Mat Image;
			savebutton->FileDataSavePath.empty();
			savebutton->FileDataTmpSavePath.empty();
			Image = imread(*tmp);
			int pos = (*tmp).rfind(savebutton->flag);
			int pos1 = (*tmp).rfind(savebutton->flag,pos-1);
			savebutton->FileDataSavePath.assign((*tmp),pos+1,(*tmp).length()-pos);
			savebutton->FileDataTmpSavePath.assign((*tmp),pos1+1,pos-pos1-1);
			savebutton->FileDataTmpSavePath = savebutton->FileColorPhotoSavePath + "\\" +savebutton->FileDataTmpSavePath;
			savebutton->CreateDefineFile(savebutton->FileDataTmpSavePath);
			savebutton->FileDataTmpSavePath = savebutton->FileDataTmpSavePath + "\\" +savebutton->FileDataSavePath;
			imwrite(savebutton->FileDataTmpSavePath,Image);
			++savebutton->numCurrentSample;
			savebutton->AppendprogressBar(savebutton->numCurrentSample,savebutton->numAllSample);
		}

		if(savebutton->fobCheck[3] == 1)
		{	
			for(auto tmp = savebutton->copyFobYangPicturePath.begin(); tmp != savebutton->copyFobYangPicturePath.end();tmp++)
			{
				Mat Image;
				savebutton->FileDataSavePath.empty();
				savebutton->FileDataTmpSavePath.empty();
				Image = imread(*tmp);
				int pos = (*tmp).rfind(savebutton->flag);
				int pos1 = (*tmp).rfind(savebutton->flag,pos-1);
				savebutton->FileDataSavePath.assign((*tmp),pos+1,(*tmp).length()-pos);
				savebutton->FileDataTmpSavePath.assign((*tmp),pos1+1,pos-pos1-1);
				savebutton->FileDataTmpSavePath = savebutton->FileFOBYangPhotoSavePath + "\\" +savebutton->FileDataTmpSavePath;
				savebutton->CreateDefineFile(savebutton->FileDataTmpSavePath);
				savebutton->FileDataTmpSavePath = savebutton->FileDataTmpSavePath + "\\" +savebutton->FileDataSavePath;
				imwrite(savebutton->FileDataTmpSavePath,Image);
				++savebutton->numCurrentSample;
				savebutton->AppendprogressBar(savebutton->numCurrentSample,savebutton->numAllSample);
			}
		}
		

		for(auto tmp = savebutton->copyFobPicturePath.begin(); tmp != savebutton->copyFobPicturePath.end();tmp++)
		{
				Mat Image;
				savebutton->FileDataSavePath.empty();
				savebutton->FileDataTmpSavePath.empty();
				Image = imread(*tmp);
				int pos = (*tmp).rfind(savebutton->flag);
				int pos1 = (*tmp).rfind(savebutton->flag,pos-1);
				savebutton->FileDataSavePath.assign((*tmp),pos+1,(*tmp).length()-pos);
				savebutton->FileDataTmpSavePath.assign((*tmp),pos1+1,pos-pos1-1);
				savebutton->FileDataTmpSavePath = savebutton->FileFOBPhotoSavePath + "\\" +savebutton->FileDataTmpSavePath;
				savebutton->CreateDefineFile(savebutton->FileDataTmpSavePath);
				savebutton->FileDataTmpSavePath = savebutton->FileDataTmpSavePath + "\\" +savebutton->FileDataSavePath;
				imwrite(savebutton->FileDataTmpSavePath,Image);
				++savebutton->numCurrentSample;
				savebutton->AppendprogressBar(savebutton->numCurrentSample,savebutton->numAllSample);
		}
	}	
	savebutton->signalCopy = 0;
	return 0;
}

void choosePicture::SoltprogressBar(int numCurrentSample,int numAllSample)
{
	ui.progressBar->setValue((numCurrentSample*100)/numAllSample);
}

void choosePicture::DetectionItems()
{
	
	
	
}

void choosePicture::on_leftTurn_clicked()
{
	if(m_flag == 1)
	{
		if(copyIterator==copyPicturePath.begin())
		{
			copyIterator = copyPicturePath.end()-1;
			countSample = numAllSample;
		}
		else
		{
			countSample--;
			copyIterator--;
		}
		AppendCountPicText(countSample, numAllSample);
		graphics(QString::fromStdString(*(copyIterator)));
	}	
}

void choosePicture::on_RightTurn_clicked()
{
	if(m_flag == 1)
	{
		if(++copyIterator==copyPicturePath.end())
		{
			countSample = 1;
			copyIterator = copyPicturePath.begin();
		}
		else
		{
			countSample++;
		}
		AppendCountPicText(countSample, numAllSample);
		graphics(QString::fromStdString(*(copyIterator)));
	}
}

void choosePicture::on_LeftUid_clicked()
{
	if(m_flag == 1)
	{
		for(int i = 0;i<5;i++)
		{
			if(copyIterator==copyPicturePath.begin())
			{
				countSample = numAllSample;
				copyIterator = copyPicturePath.end()-1;
				break;
			}
			else
			{
				countSample--;
				copyIterator--;
			}
		}
		AppendCountPicText(countSample, numAllSample);
		graphics(QString::fromStdString(*(copyIterator)));
	}
}
void choosePicture::on_RightUid_clicked()
{
	if(m_flag == 1)
	{
		for(int i = 0;i<5;i++)
		{
			if(++copyIterator==copyPicturePath.end())
			{
				countSample = 1;
				copyIterator = copyPicturePath.begin();
				break;
			}
			else
			{
				countSample++;
			}
		}
		AppendCountPicText(countSample, numAllSample);
		graphics(QString::fromStdString(*(copyIterator)));
	}
}

// 获取文件夹下的子文件夹
int choosePicture::GetSubFolders(string& folder, vector<string>& subFolders)
{
	subFolders.clear();
	WIN32_FIND_DATAA fileFindData;
	string nameWC = folder + "//*";
	HANDLE hFind = ::FindFirstFileA(nameWC.c_str(), &fileFindData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "folder path error...." << endl;
		system("pause");
		return 0;
	}

	do
	{
		if (fileFindData.cFileName[0] == '.')
		{
			continue; // filter the '..' and '.' in the path  
		}
		if (fileFindData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		{
			subFolders.push_back(folder + "\\" + fileFindData.cFileName);
		}
	} while (::FindNextFileA(hFind, &fileFindData));
	FindClose(hFind);

	return (int)subFolders.size();
}

void choosePicture::getFilesBmp(string path, vector<string>& files)
{
	//文件句柄
	long long  hFile = 0;
	//文件信息
	struct _finddata64i32_t fileinfo;
	string p;
	if ((hFile = _findfirst64i32(p.assign(path).append("\\*.bmp").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					getFilesBmp(p.assign(path).append("\\").append(fileinfo.name), files);
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext64i32(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void choosePicture::getFilesJpg(string path, vector<string>& files)
{
	//文件句柄
	long long  hFile = 0;
	//文件信息
	struct _finddata64i32_t fileinfo;
	string p;
	if ((hFile = _findfirst64i32(p.assign(path).append("\\*.jpg").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					getFilesJpg(p.assign(path).append("\\").append(fileinfo.name), files);
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext64i32(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

QString choosePicture::GetCurTime()
{
	GetLocalTime(&currentTime);
	QString localtime = QStringLiteral("%1-%2-%3 %4:%5:%6").
		arg(QString::number(currentTime.wYear),
			QString::number(currentTime.wMonth),
			QString::number(currentTime.wDay),
			QString::number(currentTime.wHour),
			QString::number(currentTime.wMinute),
			QString::number(currentTime.wSecond));
	return localtime;
}