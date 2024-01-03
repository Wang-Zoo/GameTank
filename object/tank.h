#pragma once
#include"base.h"
#include"config/config.h"

struct TANK {
private:
	OBJECT object;
	const char* picKey[4] = {TANK_PIC_UP,TANK_PIC_DOWN,TANK_PIC_LEFT,TANK_PIC_RIGHT};
	int dir;
	unsigned long long lastTime = 0l;
	int attackTime = 0;
public:
	void init(int x, int y);
	bool setDir(int dir);
	int  getDir();
	void run();
	OBJECT* getObject();
	bool canAttack();
	void setAttackTime(int time);
};

struct OUR_SIDE_TANK {
private:
	TANK tank;
public:
	void init();
	void run();
	int  getDir();
	void keyboardMove();
	OBJECT* getObject();
	bool canAttack();
	void setAttackTime(int time);
};