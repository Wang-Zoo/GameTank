#include"barriesmanager.h"
#include"tool/output.h"
#include"config/config.h"


void BARRIES_MANAGER::buildBrick(int x, int y, int height)
{
	for (int i = 0; i < height; i++)
	{
		add(x, y+i);
		add(x+1, y+i);
		add(x+2, y+i);
	}
}

void BARRIES_MANAGER::init()
{
	{
		PIC pic;
		char buf[1 * 1] = {
			4,
		};
		pic.SetPic(buf, 1, 1);
		g_op.AddPic(BARRIES_BRICK, pic);
	}
}

void BARRIES_MANAGER::add(int x,int y)
{
	BARRIES barries;
	barries.init(BARRIES_BRICK, x, y);
	vector.push_back(barries);
}

bool BARRIES_MANAGER::collision(OBJECT *other,int dir)
{
	std::vector<BARRIES>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		OBJECT targetObject = (*it).getObject();
		if (targetObject.collision(other,dir)) {
			return true;
		}
		it++;
	}
	return false;
}

void BARRIES_MANAGER::run()
{
	std::vector<BARRIES>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		(*it).run();
		it++;
	}
}

void BARRIES_MANAGER::clear()
{
	vector.clear();
}
