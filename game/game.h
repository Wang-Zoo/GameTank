#pragma once
#include"scene/scene.h"

struct GAME
{
private:
	int mapWidth;
	int mapHeight;
	SCENE_ONE sceneOne;
public:
	int getWidth();
	int getHeight();
	void init();
	void run();
	void end();

};