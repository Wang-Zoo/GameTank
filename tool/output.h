#pragma once
#include <map>
#include <vector>
#include"Windows.h"

struct PIC
{
private:
	char* pic = 0;
	int w;
	int h;
public:
	const char* GetPic();
	bool SetPic(char* buf, int w, int h);
	int GetW();
	int GetH();
};

struct OutputUnitInfo
{
private:
	const char* ts;
	const char* tsc;
	int length = 0;
public:
	void init(const char* ts, const char* tsc, int length);
	const char* getTs();
	const char* getTsc();
	int getLength();
};

struct Output
{
private:
	std::map<const char*, PIC> PicMap;
	std::vector<OutputUnitInfo> tsvector;
	int cw = 0;
	int ch = 0;
	int cs = 0;
	int cx;		//坐标  虚拟的  用于卷轴计算
	int cy;
	int colorfulSize = 0;
	char* ClientStr = 0;	//显示区域
	char* ColorStr = 0;	//显示区域
	void addInfo(const char* ts, const char* tsc,int length);
public:
	void Begin();
	void DrawPic(const char* key, int x, int y);
	void End();

	void SetClientWH(int w, int h);
	bool AddPic(const char* key, PIC pic);
	void Clear();
	void SetClientPos(int x, int y);
	int GetW();
	int GetH();
	int GetCX();
	int GetCY();
};

extern Output g_op;

