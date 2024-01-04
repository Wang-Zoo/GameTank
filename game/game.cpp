#include"game.h"
#include"config/config.h"
#include"tool/output.h"
#include"manager/tankmanger.h"
#include"manager/barriesmanager.h"

void GAME::init()
{	
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
