#pragma once
#include"base.h"
#include"config/config.h"

struct TANK {
private:
	OBJECT object;
	const char* picKey[4] = {TANK_PIC_UP,TANK_PIC_DOWN,TANK_PIC_LEFT,TANK_PIC_RIGHT};
	int dir;
public:
	void init();
	void setDir(int dir);
	void run();
	OBJECT* getObject();
};

struct OUR_SIDE_TANK {
private:
	TANK tank;
public:
	void init();
	void run();
	OBJECT* getObject();
};