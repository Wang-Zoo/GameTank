#include "tankmanger.h"

TANK_MANAGER gTankManager;

void TANK_MANAGER::add()
{
	TANK tank;
	tank.setPicKey("tank");
	this->verctor.push_back(tank);
}

void TANK_MANAGER::run()
{
	std::vector<TANK>::iterator it = this->verctor.begin();
	for (;it!=this->verctor.end();)
	{
		(*it).run();
		it++;
	}
}

void TANK_MANAGER::clear()
{
	this->verctor.clear();
}
