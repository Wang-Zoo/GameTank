#pragma once
#include"base.h"

struct BULLET
{
private:
	OBJECT object;
	int dir;
	const char* picKey = 0;
	bool alive = true;
public:
	void init(int x,int y,int dir);
	void run();

};