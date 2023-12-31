#include"tank.h"
#include"tool/output.h"
#include"manager/barriesmanager.h"

void TANK::init()
{
	object.setX(0);
	object.setY(0);
	object.setSize(TANK_WIDTH, TANK_HEIGHT);
	dir = TANK_DIR_UP;
}

void TANK::setDir(int dir)
{
	this->dir = dir;
	int x = this->object.getX();
	int y = this->object.getY();
	const int width = this->object.getWidth();
	const int height = this->object.getHeight();
	if (dir == TANK_DIR_UP) {
		y--;
		if (y < 0) {
			y = 0;
		}
	}
	else if (dir == TANK_DIR_DOWN) {
		y++;
		if (y+height > MAP_HEIGHT) {
			y = MAP_HEIGHT - height;
		}
	}
	else if (dir == TANK_DIR_LEFT) {
		x--;
		if (x < 0) {
			x = 0;
		}
	}
	else if (dir == TANK_DIR_RIGHT) {
		x++;
		if (x + width > MAP_WIDTH) {
			x = MAP_WIDTH - width ;
		}
	}
	OBJECT tempObject;
	tempObject.setX(x);
	tempObject.setY(y);
	tempObject.setSize(this->object.getWidth(), this->object.getHeight());
	if (!gBarriesManager.collision(tempObject)) {
		this->object.setX(x);
		this->object.setY(y);
	}
}

void TANK::run()
{
	g_op.DrawPic(picKey[dir], object.getX(), object.getY());
}

OBJECT* TANK::getObject()
{
	return &this->object;
}

void OUR_SIDE_TANK::init()
{
	this->tank.init();
}

void OUR_SIDE_TANK::run()
{
	if (GetAsyncKeyState('W') & 0x8000) {
		this->tank.setDir(TANK_DIR_UP);
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		this->tank.setDir(TANK_DIR_DOWN);
	}
	else if (GetAsyncKeyState('A') & 0x8000) {
		this->tank.setDir(TANK_DIR_LEFT);
	}
	else if (GetAsyncKeyState('D') & 0x8000) {
		this->tank.setDir(TANK_DIR_RIGHT);
	}
	this->tank.run();
}

OBJECT* OUR_SIDE_TANK::getObject()
{
	return this->tank.getObject();
}
