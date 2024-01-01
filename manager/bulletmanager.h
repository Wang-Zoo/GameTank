#pragma once
#include<vector>
#include"object/bullet.h"

struct BULLET_MANAGER
{
private:
	std::vector<BULLET> vector;
public:
	void init();
	void add(int x,int y,int dir);
	void run();
	void clear();

};

