/*************************************************
  Copyright (C),  2014-2020, moemillab.
  File name:      typeDef.h 
  Author:         Yuan Yang 
  Date:           2014.04.25
  Description:    typedef定义变量类型头文件
  Others:         无
*************************************************/

#ifndef _TYPEDEF_H
#define _TYPEDEF_H

#include <string.h>
#include <vector>

using namespace std;

typedef unsigned long						DWORD;   
typedef unsigned char						BYTE;    
typedef unsigned short						WORD;    
typedef float								FLOAT;   
typedef double								DOUBLE;  
typedef int								    BOOL;    
typedef int									INT;     
typedef unsigned int						UINT;    
typedef long long int						INT64;   
typedef unsigned long long int		        UINT64;

#define  MAX_WIDTH 1600
#define  MAX_HEIGHT 1200
//#define  MAX_WIDTH 2048
//#define  MAX_HEIGHT 1536
//#define  MAX_WIDTH 1920
//#define  MAX_HEIGHT 1200

// #define _SAVE_IMG_
#define _modify_zy_
#define EPS_mine double(2.2204*pow(10.0,-16.0))

typedef struct PointInfo
{
	INT x;
	INT y;
}Point;

typedef struct cPointInfo
{
	DOUBLE x;
	DOUBLE y;
}DPoint;

typedef struct BoxInfo
{
	INT col;
	INT row;
	INT width;
	INT height;
}box;

typedef struct EllipseInfo
{
	DOUBLE majoraxislength;
	DOUBLE minoraxislength;
	DOUBLE orientation;
	DOUBLE eccentricity;
}ellipseNEW;


struct SCellBox
{
	INT x;
	INT y;
	INT nwidth;
	INT nheight;
};

struct SCellParam
{
	INT nEyeIndex;
	wstring strPath;
};

struct modelwh
{
	INT width;
	INT height;
};

struct MidewPara
{
	INT ni;
	DOUBLE matchNum;
	DOUBLE measurenum;
};

typedef vector<SCellBox> Vector_BOX;
//输出结构示意

struct SDetectionResult
{
	Vector_BOX ery[30];
	Vector_BOX leu[30];
	Vector_BOX pyo[30];
	Vector_BOX mid[30];
	Vector_BOX fat[30];
	Vector_BOX cry[30];
	Vector_BOX egg1[30];//肝吸虫
	Vector_BOX egg2[30];//鞭虫
	Vector_BOX egg3[30];//血吸虫
	Vector_BOX egg4[30];//绦虫
	Vector_BOX egg5[30];//姜片
	Vector_BOX egg6[30];//肺吸虫
	Vector_BOX egg7[30];//蛔虫
	Vector_BOX egg8[30];//钩虫
};

#endif
