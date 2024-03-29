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
	int cx;		//����  �����  ���ھ������
	int cy;
	char* ClientStr = 0;	//��ʾ����
	const char* ts = 0;		//ͼ�ؼ�¼
public:
	void Begin();
	void DrawPic(const char* key, int x, int y,bool needTitle = true);
	void End();

	void SetTs(const char* ts);
	void SetClientWH(int w, int h);
	bool AddPic(const char* key, PIC pic);
	void Clear();
	void SetClientPos(int x, int y);
	int GetW();
	int GetH();
	int GetCX();
	int GetCY();
	void popBack(const char* key);
};

extern Output g_op;

