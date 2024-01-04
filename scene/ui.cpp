#include "ui.h"
#include "tool/output.h"
#include "config/config.h"

void UI::init()
{
}

int UI::run()
{
	return ACTION_NONE;
}

void UI::end()
{
}

void UI_START::init()
{
	g_op.SetClientWH(UI_WIDTH, UI_HEIGHT);
	g_op.SetClientPos(0, 0);

	g_op.addInfo("  ", "", 0);
	g_op.addInfo("■", "\033[34m", 5);
	g_op.addInfo("开", "\033[32m", 5);
	g_op.addInfo("始", "\033[32m", 5);
	g_op.addInfo("关", "\033[31m", 5);
	g_op.addInfo("闭", "\033[31m", 5);
	g_op.addInfo("→", "\033[31m", 5);

	{
		//0
		char buf[]
		{
			0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,0,0,0,
			0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,0,0,
			0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,
			0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,0,0,0,
			0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,1,0,1,1,0,1,0,0,0,
		};
		PIC til;
		til.SetPic(buf, 30, 5);
		g_op.AddPic("tank", til);
	}
	{
		//1  start game
		char buf[] = { 2,3 };
		PIC til;
		til.SetPic(buf, 2, 1);
		g_op.AddPic("start", til);
	}
	{
		//2  exit
		char buf[] = { 4,5 };
		PIC til;
		til.SetPic(buf, 2, 1);
		g_op.AddPic("exit", til);
	}
	{
		//3 →
		char buf[] = { 6 };
		PIC til;
		til.SetPic(buf, 1, 1);
		g_op.AddPic("jt", til);
	}
	ay = 17;
}

int UI_START::run()
{
	g_op.DrawPic("tank", 0, 10);
	g_op.DrawPic("start", 15, 17);
	g_op.DrawPic("exit", 15, 19);
	g_op.DrawPic("jt", 13, ay);

	if (GetAsyncKeyState('W') & 1 || GetAsyncKeyState('S') & 1)
	{
		if (ay == 17)
			ay = 19;
		else
			ay = 17;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		return ay = 19 ? ACTION_EXIT : ACTION_NEXT;
	}
	return ACTION_NONE;
}

void UI_START::end()
{
	g_op.Clear();
}

void UI_STAGE_ONE::init()
{
	g_op.SetClientWH(UI_WIDTH, UI_HEIGHT);
	g_op.SetClientPos(0, 0);
	g_op.addInfo("  ", "", 0);
	g_op.addInfo("关", "\033[32m", 5);
	g_op.addInfo("卡", "\033[32m", 5);
	g_op.addInfo("一", "\033[32m", 5);
	{
		//stage one
		char buf[] = { 1,2,3 };
		PIC til;
		til.SetPic(buf, 3, 1);
		g_op.AddPic("stage", til);
	}
}

int UI_STAGE_ONE::run()
{
	g_op.DrawPic("stage", 15, 17);
	if (GetAsyncKeyState(VK_RETURN))
	{
		return ACTION_NEXT;
	}
	return ACTION_NONE;
}

void UI_STAGE_ONE::end()
{
	g_op.Clear();
}

void UI_STAGE_TWO::init()
{
	g_op.SetClientWH(UI_WIDTH, UI_HEIGHT);
	g_op.SetClientPos(0, 0);
	g_op.addInfo("  ", "", 0);
	g_op.addInfo("关", "\033[32m", 5);
	g_op.addInfo("卡", "\033[32m", 5);
	g_op.addInfo("二", "\033[32m", 5);

	{
		//stage two
		char buf[] = { 1,2,3};
		PIC til;
		til.SetPic(buf, 3, 1);
		g_op.AddPic("stage", til);
	}
}

int  UI_STAGE_TWO::run()
{
	g_op.DrawPic("stage", 15, 17);
	if (GetAsyncKeyState(VK_RETURN))
	{
		return ACTION_NEXT;
	}
	return ACTION_NONE;
}

void UI_STAGE_TWO::end()
{
	g_op.Clear();
}

void UI_STAGE_AGAIN::init()
{
}

int UI_STAGE_AGAIN::run()
{
	return ACTION_NONE;
}

void UI_STAGE_AGAIN::end()
{
}

void UI_END::init()
{
	g_op.SetClientWH(UI_WIDTH, UI_HEIGHT);
	g_op.SetClientPos(0, 0);

	g_op.addInfo("  ", "", 0);
	g_op.addInfo("游", "\033[31m", 5);
	g_op.addInfo("戏", "\033[31m", 5);
	g_op.addInfo("结", "\033[31m", 5);
	g_op.addInfo("束", "\033[31m", 5);
	{
		//stage two
		char buf[] = { 1,2,3,4 };
		PIC til;
		til.SetPic(buf, 4, 1);
		g_op.AddPic("stage", til);
	}
}

int UI_END::run()
{
	g_op.DrawPic("stage", 15, 17);
	if (GetAsyncKeyState(VK_RETURN))
	{
		return ACTION_NEXT;
	}
	return ACTION_NONE;
}

void UI_END::end()
{
	g_op.Clear();
}
