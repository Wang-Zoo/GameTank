#include"barries.h"
#include"tool/output.h"
#include"config/config.h"

void BARRIES::init(const char* type,int x,int y)
{
	this->picKey = type;
	this->object.setX(x);
	this->object.setY(y);
	this->object.setSize(BRICK_UNIT_WIDTH,BRICK_UNIT_HEIGHT);
}

void BARRIES::run()
{
	g_op.DrawPic(picKey, this->object.getX(), this->object.getY());
}

void BARRIES::dead()
{
	if (picKey == BARRIES_BRICK) {
		alive = false;
	}
}

bool BARRIES::isAlive()
{
	return alive;
}

bool BARRIES::canPass()
{
	return picKey == BARRIES_TREE;
}

OBJECT BARRIES::getObject()
{
	return object;
}
