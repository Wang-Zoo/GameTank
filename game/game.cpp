#include"game.h"
#include"config/config.h"
#include"tool/output.h"
#include"manager/tankmanger.h"
#include"manager/barriesmanager.h"

int GAME::getWidth()
{
	return mapWidth;
}

int GAME::getHeight()
{
	return mapHeight;
}

void GAME::init()
{
	mapWidth = MAP_WIDTH;
	mapHeight = MAP_HEIGHT;
	g_op.SetClientWH(mapWidth, mapHeight);
	g_op.SetClientPos(0, 0);
	sceneTwo.init();
}

void GAME::run()
{
	while (true)
	{
		g_op.Begin();
		sceneTwo.baseScene.run();
		g_op.End();
	}
}

void GAME::end()
{
	sceneTwo.baseScene.end();
}
