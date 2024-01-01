#pragma once
#include"manager/barriesmanager.h"
#include"manager/tankmanger.h"

struct SCENE
{
	BARRIES_MANAGER bm;
	TANK_MANAGER tm;
	void run();
	void init();
	void end();
};

struct SCENE_ONE
{
	SCENE baseScene;
	void init();
};