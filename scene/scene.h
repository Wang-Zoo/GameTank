#pragma once
#include"manager/barriesmanager.h"
#include"manager/tankmanger.h"
#include"manager/bulletmanager.h"

struct SCENE
{
	BARRIES_MANAGER bm;
	TANK_MANAGER tm;
	BULLET_MANAGER bum;
	void run();
	void init();
	void end();
};

struct SCENE_ONE
{
	SCENE baseScene;
	void init();
};

struct SCENE_TWO
{
	SCENE baseScene;
	void init();
};