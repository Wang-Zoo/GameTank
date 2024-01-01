#pragma once

#include<vector>
#include"object/tank.h"

struct TANK_MANAGER
{
private:
	std::vector<TANK> enemyVector;
	std::vector<OUR_SIDE_TANK> ourSideVector;
	BARRIES_MANAGER* bm = 0;
	bool collisionBarries(TANK *tank,int dir);
	bool collisionBarries(OBJECT *tank,int dir);
	bool collisionTank(OBJECT *object,int dir);
	int  aiMove(TANK* tank);
public:
	void init(BARRIES_MANAGER* bm);
	void add(bool enemy, int x, int y);
	void run();
	void clear();

};
