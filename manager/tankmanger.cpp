#include "tankmanger.h"
#include"tool/output.h"
#include"config/config.h"
#include"tool/tool.h"
#include"Windows.h"

bool TANK_MANAGER::collisionBarries(TANK* tank, int dir)
{
	TANK& tempTank = *tank;
	if (!tempTank.setDir(dir)) {
		return true;
	}
	if (collisionBarries(tempTank.getObject(), dir)) {
		return true;
	}
	return false;
}

bool TANK_MANAGER::collisionBarries(OBJECT* tank, int dir)
{
	bulletm->collision(tank,dir);
	if (bm->collision(tank, dir)) {
		return true;
	}
	if (collisionTank(tank, dir)) {
		return true;
	}
	
	return false;
}

bool TANK_MANAGER::collisionTank(OBJECT* object, int dir)
{
	std::vector<TANK>::iterator enemyIt = this->enemyVector.begin();
	for (; enemyIt != this->enemyVector.end();)
	{
		OBJECT& targetObject = (*(*enemyIt).getObject());
		if (targetObject.getX() == (*object).getX() &&
			targetObject.getY() == (*object).getY()) {
			enemyIt++;
			continue;
		}

		if (targetObject.collision(object, dir)) {
			return true;
		}
		enemyIt++;
	}

	std::vector<OUR_SIDE_TANK>::iterator ourSizeIt = this->ourSideVector.begin();
	for (; ourSizeIt != this->ourSideVector.end();)
	{
		OBJECT& targetObject = (*(*ourSizeIt).getObject());
		if (targetObject.getX() == (*object).getX() &&
			targetObject.getY() == (*object).getY()) {
			ourSizeIt++;
			continue;
		}
		if (targetObject.collision(object, dir)) {
			return true;
		}
		ourSizeIt++;
	}
	return false;
}

void TANK_MANAGER::init(BARRIES_MANAGER* bm, BULLET_MANAGER* bum)
{
	this->bm = bm;
	this->bulletm = bum;
	{
		PIC pic;
		char buf[TANK_WIDTH * TANK_HEIGHT] = {
			1,1,1,
			1,2,1,
			1,0,1
		};
		pic.SetPic(buf, 3, 3);
		g_op.AddPic(TANK_PIC_UP, pic);
	}
	{
		PIC pic;
		char buf[TANK_WIDTH * TANK_HEIGHT] = {
			1,0,1,
			1,2,1,
			1,1,1
		};
		pic.SetPic(buf, 3, 3);
		g_op.AddPic(TANK_PIC_DOWN, pic);
	}
	{
		PIC pic;
		char buf[TANK_WIDTH * TANK_HEIGHT] = {
			3,3,3,
			3,2,0,
			3,3,3
		};
		pic.SetPic(buf, 3, 3);
		g_op.AddPic(TANK_PIC_LEFT, pic);
	}
	{
		PIC pic;
		char buf[TANK_WIDTH * TANK_HEIGHT] = {
			3,3,3,
			0,2,3,
			3,3,3
		};
		pic.SetPic(buf, 3, 3);
		g_op.AddPic(TANK_PIC_RIGHT, pic);
	}
	add(false,0,0);
	add(true,3,0);
	add(true,9,0);
	add(true,15,0);
	add(true,18,0);

}

void TANK_MANAGER::add(bool enemy,int x = 0,int y = 0)
{
	if (enemy) {
		TANK tank;
		tank.init(x,y);
		this->enemyVector.push_back(tank);
	}
	else {
		OUR_SIDE_TANK tank;
		tank.init();
		this->ourSideVector.push_back(tank);
	}
}

int TANK_MANAGER::aiMove(TANK* tank)
{
	int tempDir = (*tank).getDir();
	int count = 0;
	while (collisionBarries(tank, tempDir)&&count<5) {
		tempDir = RANDOM(TANK_DIR_UP, TANK_DIR_RIGHT);
		count++;
	}
	return tempDir;
}

void TANK_MANAGER::addBullet(OBJECT object,int dir,bool canAttack)
{
	if (canAttack) {
		object.getX();
		bulletm->add(object.getX(), object.getY(), dir);
	}
}

void TANK_MANAGER::run()
{
	std::vector<TANK>::iterator enemyIt = this->enemyVector.begin();
	for (; enemyIt !=this->enemyVector.end();)
	{
		TANK& tempTank = *enemyIt;
		aiMove(&tempTank);
		addBullet((*tempTank.getObject()), tempTank.getDir(), tempTank.canAttack());
		tempTank.run();
		enemyIt++;
	}

	std::vector<OUR_SIDE_TANK>::iterator ourSizeIt = this->ourSideVector.begin();
	for (; ourSizeIt != this->ourSideVector.end();)
	{
		OUR_SIDE_TANK& tempTank = *ourSizeIt;
		tempTank.keyboardMove();
		if (GetAsyncKeyState('K') & 0x8000)
			addBullet((*tempTank.getObject()), tempTank.getDir(),tempTank.canAttack());
		collisionBarries(tempTank.getObject(), tempTank.getDir());
		tempTank.run();
		ourSizeIt++;
	}
}

void TANK_MANAGER::clear()
{
	this->enemyVector.clear();
	this->ourSideVector.clear();
}
