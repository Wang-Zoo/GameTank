#pragma once
#include"scene/scene.h"
#include"scene/ui.h"


struct GAME
{
private:
	UI_START  uiStart;
	UI_STAGE_ONE  uiStageOne;
	UI_STAGE_TWO  uiStageTwo;
	UI_END  uiGameEnd;

	SCENE_ONE sceneOne;
	SCENE_TWO sceneTwo;

	int index = 0;

public:
	void init();
	int run();
	void end();

};