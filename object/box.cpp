#include "box.h"
#include "config/config.h"
#include "tool/output.h"

void BOX::init(int x,int y)
{
	this->object.setX(x);
	this->object.setY(y);
	this->object.setSize(BOX_WIDTH, BOX_HEIGHT);
}

void BOX::run()
{
	g_op.DrawPic(BOX_ALL_DESTORY, object.getX(), object.getY());
}

OBJECT BOX::getObject()
{
	return object;
}
