#pragma once
#include"base.h"

struct BARRIES
{
private:
	OBJECT object;
	const char* picKey = 0;
	bool alive = true;
public:
	void init(const char* type, int x, int y);
	void run();
	void dead();
	bool isAlive();
	OBJECT getObject();
};     