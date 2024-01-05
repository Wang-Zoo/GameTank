#pragma once
#include"object/base.h"
struct BOX
{
private:
	OBJECT object;
public:
	void init(int x, int y);
	void run();
	OBJECT getObject();
};