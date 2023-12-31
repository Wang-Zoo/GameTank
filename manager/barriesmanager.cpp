#include"barriesmanager.h"
#include"tool/output.h"
#include"config/config.h"

BARRIES_MANAGER gBarriesManager;

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
	add(10,10);
	add(11,10);
	add(12,10);

	add(10, 11);
	add(11, 11);
	add(12, 11);

	add(10, 12);
	add(11, 12);
	add(12, 12);
}

void BARRIES_MANAGER::add(int x,int y)
{
	BARRIES barries;
	barries.init(BARRIES_BRICK, x, y);
	vector.push_back(barries);
}

bool BARRIES_MANAGER::collision(OBJECT other)
{
	std::vector<BARRIES>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		if ((*it).getObject().collision(other)) {
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
