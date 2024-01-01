#pragma once

#include<vector>
#include"object/tank.h"
#include"manager/barriesmanager.h"
#include"manager/bulletmanager.h"

struct TANK_MANAGER
{
private:
	std::vector<TANK> enemyVector;
	std::vector<OUR_SIDE_TANK> ourSideVector;
	BARRIES_MANAGER* bm = 0;
	BULLET_MANAGER* bulletm = 0;
	bool collisionBarries(TANK *tank,int dir);
	bool collisionBarries(OBJECT *tank,int dir);
	bool collisionTank(OBJECT *object,int dir);
	int  aiMove(TANK* tank);
	void addBullet(OBJECT object,int dir);
public:
	void init(BARRIES_MANAGER* bm,BULLET_MANAGER* bum);
	void add(bool enemy, int x, int y);
	void run();
	void clear();

};
