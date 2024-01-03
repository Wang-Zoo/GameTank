#pragma once
#include"base.h"

struct BULLET
{
private:
	OBJECT object;
	int dir;
	bool alive = true;
	bool isEnemy = true;
public:
	void init(int x,int y,int dir,bool isEnemy);
	void run();
	void move();
	void dead();
	bool isAlive();
	bool isOverMap();
	int getDir();
	bool isEnemyBullet();
	OBJECT getObject();
};