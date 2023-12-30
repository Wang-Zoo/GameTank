#include"game.h"
#include"tool/output.h"
#include"manager/tankmanger.h"
#include"config/config.h"

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
	mapWidth = 100;
	mapHeight = 100;
	g_op.SetClientWH(mapWidth, mapHeight);
	g_op.SetClientPos(0, 0);
	//          0 1 2
	g_op.SetTs("  ¡¬¡ñ");

	{
		PIC pic;
		char buf[TANK_WIDTH * TANK_HEIGHT] = {
			1,1,1,
			1,2,1,
			1,0,1
		};
		pic.SetPic(buf, 3, 3);
		g_op.AddPic("tank",pic);
	}
	gTankManager.add();
}

void GAME::run()
{
	while (true)
	{
		g_op.Begin();
		gTankManager.run();
		g_op.End();
	}
}

void GAME::end()
{
}
