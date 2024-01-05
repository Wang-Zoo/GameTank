#include "title.h"
#include "tool/output.h"
#include "config/config.h"
void TITLE::update()
{
	int target = 14 + enemy;

	PIC pic;
	char buf[4 * 2] = {
		10,11,12,target,
		13,13,13,13
	};
	pic.SetPic(buf, 4, 2);
	g_op.AddPic(TITLE_TYPE, pic);
}
void TITLE::init()
{
	PIC pic;
	char buf[MAP_WIDTH * 1] = {};
	memset(buf, 13, MAP_WIDTH);
	pic.SetPic(buf, MAP_WIDTH, 1);
	g_op.AddPic(TITLE_BOTTOM_TYPE, pic);
}

void TITLE::run()
{
	update();
	g_op.DrawPic(TITLE_TYPE, 5, 1, false);
	g_op.DrawPic(TITLE_BOTTOM_TYPE, 0, 4, false);
	g_op.popBack(TITLE_TYPE);
}

void TITLE::setEnemyNum(int num)
{
	enemy = num;
}
