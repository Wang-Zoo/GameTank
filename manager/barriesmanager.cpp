#include"barriesmanager.h"
#include"tool/output.h"
#include"config/config.h"


void BARRIES_MANAGER::buildBrick(int x, int y, int height)
{
	for (int i = 0; i < height; i++)
	{
		addBrick(x, y+i);
		addBrick(x+1, y+i);
		addBrick(x+2, y+i);
	}
}

void BARRIES_MANAGER::buildIron(int x, int y, int height)
{
	for (int i = 0; i < height; i++)
	{
		addIron(x, y + i);
		addIron(x + 1, y + i);
		addIron(x + 2, y + i);
	}
}

void BARRIES_MANAGER::buildTree(int x, int y, int height)
{
	for (int i = 0; i < height; i++)
	{
		addTree(x, y + i);
		addTree(x + 1, y + i);
		addTree(x + 2, y + i);
	}
}

void BARRIES_MANAGER::init()
{
	{
		PIC pic;
		char buf[BRICK_UNIT_WIDTH * BRICK_UNIT_HEIGHT] = {
			4,
		};
		pic.SetPic(buf, BRICK_UNIT_WIDTH, BRICK_UNIT_HEIGHT);
		g_op.AddPic(BARRIES_BRICK, pic);
	}
	{
		PIC pic;
		char buf[BRICK_UNIT_WIDTH * BRICK_UNIT_HEIGHT] = {
			6,
		};
		pic.SetPic(buf, BRICK_UNIT_WIDTH, BRICK_UNIT_HEIGHT);
		g_op.AddPic(BARRIES_IRON, pic);
	}
	{
		PIC pic;
		char buf[BRICK_UNIT_WIDTH * BRICK_UNIT_HEIGHT] = {
			7,
		};
		pic.SetPic(buf, BRICK_UNIT_WIDTH, BRICK_UNIT_HEIGHT);
		g_op.AddPic(BARRIES_TREE, pic);
	}
}

void BARRIES_MANAGER::addBrick(int x,int y)
{
	BARRIES barries;
	barries.init(BARRIES_BRICK, x, y);
	vector.push_back(barries);
}

void BARRIES_MANAGER::addIron(int x, int y)
{
	BARRIES barries;
	barries.init(BARRIES_IRON, x, y);
	vector.push_back(barries);
}

void BARRIES_MANAGER::addTree(int x, int y)
{
	BARRIES barries;
	barries.init(BARRIES_TREE, x, y);
	vector.push_back(barries);
}

void BARRIES_MANAGER::destoryBrick(int x, int y, int dir)
{
	const int LENGTH = 3;
	int target[LENGTH][2] = {};
	if (dir == TANK_DIR_UP) {
		target[0][0] = x - BRICK_UNIT_WIDTH;
		target[0][1] = y;
		target[1][0] = x;
		target[1][1] = y;
		target[2][0] = x + BRICK_UNIT_WIDTH;
		target[2][1] = y;
	}
	else if(dir == TANK_DIR_DOWN) {
		target[0][0] = x - BRICK_UNIT_WIDTH;
		target[0][1] = y;
		target[1][0] = x;
		target[1][1] = y;
		target[2][0] = x + BRICK_UNIT_WIDTH;
		target[2][1] = y;
	}
	else if (dir == TANK_DIR_LEFT) {
		target[0][0] = x;
		target[0][1] = y - BRICK_UNIT_HEIGHT;
		target[1][0] = x;
		target[1][1] = y;
		target[2][0] = x;
		target[2][1] = y + BRICK_UNIT_HEIGHT;
	}
	else if (dir == TANK_DIR_RIGHT) {
		target[0][0] = x;
		target[0][1] = y - BRICK_UNIT_HEIGHT;
		target[1][0] = x;
		target[1][1] = y;
		target[2][0] = x;
		target[2][1] = y + BRICK_UNIT_HEIGHT;
	}

	std::vector<BARRIES>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		OBJECT targetObject = (*it).getObject();
		int targetX = targetObject.getX();
		int targetY = targetObject.getY();
		
		bool isFind = false;
		for (int i = 0; i < LENGTH; i++)
		{
			if (target[i][0] == targetX && target[i][1] == targetY) {
				isFind = true;
				break;
			}
		}
		if (isFind) {
			(*it).dead();
		}
		it++;
	}
}

bool BARRIES_MANAGER::collision(OBJECT *other,int dir, bool isBullet)
{
	std::vector<BARRIES>::iterator it = this->vector.begin();
	for (; it != this->vector.end();)
	{
		OBJECT targetObject = (*it).getObject();
		if ((*it).isAlive()&&!(*it).canPass()&& targetObject.collision(other, dir, !isBullet)) {

			if (isBullet) {
				destoryBrick(other->getX(), other->getY(),dir);
			}

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
		if ((*it).isAlive()) {
			(*it).run();
			it++;
		}
		else {
			it = vector.erase(it);
		}
	}
}

void BARRIES_MANAGER::clear()
{
	vector.clear();
}
