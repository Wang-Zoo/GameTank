#pragma once
#include <map>
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

struct Output
{
private:
	std::map<const char*, PIC> PicMap;
	int cw = 0;
	int ch = 0;
	int cs = 0;
	int cx;		//坐标  虚拟的  用于卷轴计算
	int cy;
	char* ClientStr = 0;	//显示区域
	const char* ts = 0;		//图素记录
	void SetTs(const char* ts);
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

