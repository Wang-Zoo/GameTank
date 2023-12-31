#pragma once

#include<vector>
#include"object/barries.h"

struct BARRIES_MANAGER
{
private:
	std::vector<BARRIES> vector; 


public:
	void init();
	void add(int x, int y);
	bool collision(OBJECT other);
	void run();
	void clear();
};

extern BARRIES_MANAGER gBarriesManager;