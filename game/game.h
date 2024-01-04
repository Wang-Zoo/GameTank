#pragma once
#include"scene/scene.h"

struct GAME
{
private:
	SCENE_ONE sceneOne;
	SCENE_TWO sceneTwo;
public:
	void init();
	void run();
	void end();

};