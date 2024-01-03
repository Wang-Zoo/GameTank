#include "bulletmanager.h"
#include"tool/output.h"
#include"config/config.h"


void BULLET_MANAGER::init(BARRIES_MANAGER* bm)
{
	this->bm = bm;
	{
		PIC pic;
		char buf[1 * 1] = {
			5,
		};
		pic.SetPic(buf, 1, 1);
		g_op.AddPic(BULLET_TYPE, pic);
	}
}

void BULLET_MANAGER::add(int x,int y,int dir)
{
	BULLET bullet;
	if (dir == TANK_DIR_UP) {
		y--;
		x++;
	}
	else if (dir == TANK_DIR_DOWN) {
		y+=TANK_HEIGHT;
		x++;
	}
	else if (dir == TANK_DIR_LEFT) {
		x--;
		y++;
	}
	else if (dir == TANK_DIR_RIGHT) {
		x+=TANK_WIDTH;
		y++;
	}
	bullet.init(x, y,dir);
	this->vector.push_back(bullet);
}

void BULLET_MANAGER::run()
{
	std::vector<BULLET>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		BULLET temp = *it;
		OBJECT tempObject = temp.getObject();
		if (temp.isOverMap()||bm->collision(&tempObject, temp.getDir())) {
			it = vector.erase(it);
		}
		else {
			(*it).run();
			it++;
		}
	}
}

void BULLET_MANAGER::clear()
{
	this->vector.clear();
}

bool BULLET_MANAGER::collision(OBJECT* other, int dir)
{
	std::vector<BULLET>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		OBJECT targetObject = (*it).getObject();
		if (targetObject.collision(other, dir,false)) {
			it = vector.erase(it);
		}
		else {
			it++;
		}
	}
	return false;

}
