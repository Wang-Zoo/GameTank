#pragma once

#include<vector>
#include"object/tank.h"
#include"manager/barriesmanager.h"
#include"manager/bulletmanager.h"
#include"manager/boxmanager.h"
#include"scene/title.h"
struct TANK_MANAGER
{
private:
	std::vector<TANK> enemyVector;
	std::vector<OUR_SIDE_TANK> ourSideVector;
	BARRIES_MANAGER* bm = 0;
	BULLET_MANAGER* bulletm = 0;	
	BOX_MANAGER* boxm = 0;	
	TITLE *title;
	bool collisionBarries(TANK *tank,int dir,bool isEnemy);
	bool collisionBarries(OBJECT *tank,int dir,bool isEnemy);
	bool collisionTank(OBJECT *object,int dir);
	int  aiMove(TANK* tank);
	void addBullet(OBJECT object,int dir,bool canAttack,bool isEnemy);
public:
	void init(BARRIES_MANAGER* bm,BULLET_MANAGER* bum,BOX_MANAGER* boxm, TITLE* title);
	void add(bool enemy, int x = 0, int y = 0);
	int run();
	void clear();

};
