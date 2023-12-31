#include "tankmanger.h"
#include"tool/output.h"
#include"config/config.h"

//Ì¹¿Ë¹ÜÀíÆ÷
TANK_MANAGER gTankManager;

void TANK_MANAGER::init()
{
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
	gTankManager.add(false);
}

void TANK_MANAGER::add(bool enemy)
{
	if (enemy) {
		TANK tank;
		tank.init();
		this->enemyVector.push_back(tank);
	}
	else {
		OUR_SIDE_TANK tank;
		tank.init();
		this->ourSideVector.push_back(tank);
	}

}

void TANK_MANAGER::run()
{
	std::vector<TANK>::iterator enemyIt = this->enemyVector.begin();
	for (; enemyIt !=this->enemyVector.end();)
	{
		(*enemyIt).run();
		enemyIt++;
	}

	std::vector<OUR_SIDE_TANK>::iterator ourSizeIt = this->ourSideVector.begin();
	for (; ourSizeIt != this->ourSideVector.end();)
	{
		(*ourSizeIt).run();
		ourSizeIt++;
	}
}

void TANK_MANAGER::clear()
{
	this->enemyVector.clear();
	this->ourSideVector.clear();
}
