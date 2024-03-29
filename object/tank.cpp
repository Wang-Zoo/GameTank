#include"tank.h"
#include"tool/output.h"
#include"Windows.h"


bool TANK::isDestoryStatus()
{
	return isDestory;
}

void TANK::setDestoryStatus()
{
	isDestory = true;
}

bool TANK::isDisapperStatus()
{
	return isDisapper;
}

bool TANK::isNormal()
{
	return !isDestory&&!isDisapper;
}

void TANK::init(int x,int y)
{
	object.setX(x);
	object.setY(y);
	object.setSize(TANK_WIDTH, TANK_HEIGHT);
	dir = TANK_DIR_LEFT;
	attackTime = ENEMY_ATTACK_TIME_INTERVAL;
}

bool TANK::setDir(int dir)
{
	/*if (this->dir != dir) {
		this->dir = dir;
		return true;
	}*/

	this->dir = dir; 
	int x = this->object.getX();
	int y = this->object.getY();
	const int width = this->object.getWidth();
	const int height = this->object.getHeight();
	if (dir == TANK_DIR_UP) {
		y--;
		if (y < 0) {
			y = 0;
			return false;
		}
	}
	else if (dir == TANK_DIR_DOWN) {
		y++;
		if (y+height > MAP_HEIGHT) {
			y = MAP_HEIGHT - height;
			return false;
		}
	}
	else if (dir == TANK_DIR_LEFT) {
		x--;
		if (x < 0) {
			x = 0;
			return false;
		}
	}
	else if (dir == TANK_DIR_RIGHT) {
		x++;
		if (x + width > MAP_WIDTH) {
			x = MAP_WIDTH - width ;
			return false;
		}
	}
	this->object.setX(x);
	this->object.setY(y);
	return true;
}

int TANK::getDir()
{
	return dir;
}

void TANK::run()
{ 
	if (isDestory) {
		if (destoryTime == 0l) {
			destoryTime = GetTickCount64();
		}
		else {
			unsigned long long curTime = GetTickCount64();
			if (curTime - destoryTime > 200) {
				isDisapper = true;
			}
		}
		g_op.DrawPic(TANK_DESTORY, object.getX(), object.getY());
	}
	else {
		g_op.DrawPic(picKey[dir], object.getX(), object.getY());
	}
}

OBJECT* TANK::getObject()
{
	return &this->object;
}

bool TANK::canAttack()
{
	unsigned long long curTime = GetTickCount64();
	unsigned long long offset = (curTime - lastTime) / 1;
	if (offset > attackTime) {
		lastTime = curTime;
		return true;
	}
	return false;
}

void TANK::setAttackTime(int time)
{
	this->attackTime = time;
}

void OUR_SIDE_TANK::init()
{
	this->tank.init(0,0);
	this->tank.init(0,MAP_HEIGHT-TANK_HEIGHT);
	this->setAttackTime(OUR_ATTACK_TIME_INTERVAL);
}

void OUR_SIDE_TANK::run()
{
	
	this->tank.run();
}

int OUR_SIDE_TANK::getDir()
{
	return tank.getDir();
}

void OUR_SIDE_TANK::keyboardMove()
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
}

OBJECT* OUR_SIDE_TANK::getObject()
{
	return this->tank.getObject();
}

void OUR_SIDE_TANK::setDestoryStatus()
{
	this->tank.setDestoryStatus();
}

bool OUR_SIDE_TANK::isDisapperStatus()
{
	return tank.isDisapperStatus();
}

bool OUR_SIDE_TANK::canAttack()
{
	return this->tank.canAttack();
}

bool OUR_SIDE_TANK::isNormal()
{
	return tank.isNormal();
}

void OUR_SIDE_TANK::setAttackTime(int time)
{
	this->tank.setAttackTime(time);
}
