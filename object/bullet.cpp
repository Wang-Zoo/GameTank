#include"bullet.h"
#include"tool/output.h"
#include"config/config.h"

void BULLET::init(int x, int y, int dir,bool isEnemy)
{
	this->dir = dir;
	this->object.setX(x);
	this->object.setY(y);
	this->object.setSize(1, 1);
	this->isEnemy = isEnemy;
}

void BULLET::run()
{
	g_op.DrawPic(isEnemy?ENEMY_BULLET_TYPE:OUR_BULLET_TYPE, this->object.getX(),this->object.getY());
}

void BULLET::move()
{
	int x = this->object.getX();
	int y = this->object.getY();
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

int BULLET::getDir()
{
	return dir;
}

bool BULLET::isEnemyBullet()
{
	return isEnemy;
}

OBJECT BULLET::getObject()
{
	return object;
}
