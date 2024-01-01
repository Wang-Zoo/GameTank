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
