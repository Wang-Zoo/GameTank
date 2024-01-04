#pragma once
#include"scene/scene.h"

struct GAME
{
private:
	int mapWidth;
	int mapHeight;
	SCENE_ONE sceneOne;
	SCENE_TWO sceneTwo;
public:
	int getWidth();
	int getHeight();
	void init();
	void run();
	void end();

};