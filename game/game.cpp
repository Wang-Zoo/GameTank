#include"game.h"
#include"config/config.h"
#include"tool/output.h"
#include"manager/tankmanger.h"
#include"manager/barriesmanager.h"

void GAME::init()
{

	switch (index)
	{
	case 0:
		uiStart.init();
		break;
	case 1:
		uiStageOne.init();
		break;
	case 2:
		sceneOne.init();
		break;
	case 3:
		uiStageTwo.init();
		break;
	case 4:
		sceneTwo.init();
		break;
	case 5:
		uiGameEnd.init();
		break;
	}

}

int GAME::run()
{
	int action = ACTION_NONE;
	while (action == ACTION_NONE)
	{
		g_op.Begin();
		switch (index)
		{
		case 0:
			action =uiStart.run();
			break;
		case 1:
			action = uiStageOne.run();
			break;
		case 2:
			action = sceneOne.baseScene.run();
			break;
		case 3:
			action = uiStageTwo.run();
			break;
		case 4:
			action = sceneTwo.baseScene.run();
			break;
		case 5:
			action = uiGameEnd.run();
			break;
		default:
			return ACTION_NEXT;
		}
		g_op.End();
	}
	index++;
	return ACTION_NONE;
}

void GAME::end()
{
	switch (index)
	{
	case 0:
		uiStart.end();
		break;
	case 1:
		uiStageOne.end();
		break;
	case 2:
		sceneOne.baseScene.end();
		break;
	case 3:
		uiStageTwo.end();
		break;
	case 4:
		sceneTwo.baseScene.end();
		break;
	case 5:
		uiGameEnd.end();
		break;
	}
}
