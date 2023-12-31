#pragma once
#include"base.h"

struct BARRIES
{
private:
	OBJECT object;
	const char* picKey = 0;
public:
	void init(const char* type, int x, int y);
	void run();
	OBJECT getObject();
};     