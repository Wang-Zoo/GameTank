#pragma once

#include<vector>
#include"object/barries.h"

struct BARRIES_MANAGER
{
private:
	std::vector<BARRIES> vector; 
	void add(int x, int y);
public:
	void init();
	bool collision(OBJECT *other,int dir);
	void run();
	void clear();
	void buildBrick(int x, int y, int height);
};
