#pragma once

#include<vector>
#include"object/tank.h"

struct TANK_MANAGER
{
private:
	std::vector<TANK> enemyVector;
	std::vector<OUR_SIDE_TANK> ourSideVector;


public:
	void init();
	void add(bool enemy);
	void run();
	void clear();

};

extern TANK_MANAGER gTankManager;