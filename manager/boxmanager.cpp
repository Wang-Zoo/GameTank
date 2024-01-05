#include "boxmanager.h"
#include "Windows.h"
#include "tool/output.h"
#include "config/config.h"
void BOX_MANAGER::init()
{
	{
		PIC pic;
		char buf[BOX_WIDTH * BOX_HEIGHT] = {
			9,9,9,
			9,9,9,
			9,9,9
		};
		pic.SetPic(buf, BOX_WIDTH, BOX_WIDTH);
		g_op.AddPic(BOX_ALL_DESTORY, pic);
	}
	lastTime = GetTickCount64();
}

void BOX_MANAGER::add()
{
	unsigned long long curTime = GetTickCount64();
	if((curTime - lastTime )/1000 > 10){
		lastTime = curTime;
		BOX box;
		box.init(1, 10);
		this->vector.push_back(box);
	}
}

void BOX_MANAGER::run()
{
	std::vector<BOX>::iterator it = this->vector.begin();
	for (;it!=vector.end();)
	{
		BOX& temp = *it;
		temp.run();
		it++;
	}
}

void BOX_MANAGER::clear()
{
	vector.clear();
}

int BOX_MANAGER::collision(OBJECT object,int dir)
{
	std::vector<BOX>::iterator it = vector.begin();
	for (;it!=vector.end();)
	{
		if ((*it).getObject().collision(&object, dir, false)) {
			vector.erase(it);
			return BOX_ALL_DESTORY_TYPE;
		}
		it++;
	}
	return BOX_NONE;
}
