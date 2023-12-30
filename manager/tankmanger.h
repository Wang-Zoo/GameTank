#pragma once

#include<vector>
#include"object/tank.h"

struct TANK_MANAGER
{
private:
	std::vector<TANK> verctor;


public:
	void add();
	void run();
	void clear();

};

extern TANK_MANAGER gTankManager;