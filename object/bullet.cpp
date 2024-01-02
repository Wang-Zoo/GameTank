#include"bullet.h"
#include"tool/output.h"
#include"config/config.h"

void BULLET::init(int x, int y, int dir)
{
	this->dir = dir;
	this->object.setX(x);
	this->object.setY(y);
	this->object.setSize(1, 1);
	this->picKey = BULLET_TYPE;
}

void BULLET::run()
{
	int x =  this->object.getX();
	int y =  this->object.getY();
	if (dir == TANK_DIR_UP) {
		y--;
	}
	else if (dir == TANK_DIR_DOWN) {
		y++;
	}
	else if (dir == TANK_DIR_LEFT) {
		x--;
	}
	else if (dir == TANK_DIR_RIGHT) {
		x++;
	}
	this->object.setX(x);
	this->object.setY(y);

	g_op.DrawPic(picKey, this->object.getX(),this->object.getY());
}

bool BULLET::isOverMap()
{
	int x = object.getX();
	int y = object.getX();
	int width = object.getWidth();
	int height = object.getHeight();
	
	if (x <= 0 || y <= 0 || x >= MAP_WIDTH - width || y >= MAP_HEIGHT - height) {
		return true;
	}
	return false;
}

OBJECT BULLET::getObject()
{
	return object;
}
