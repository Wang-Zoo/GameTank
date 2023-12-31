#include"barries.h"
#include"tool/output.h"

void BARRIES::init(const char* type,int x,int y)
{
	this->picKey = type;
	this->object.setX(x);
	this->object.setY(y);
	this->object.setSize(1,1);
}

void BARRIES::run()
{
	g_op.DrawPic(picKey, this->object.getX(), this->object.getY());
}

OBJECT BARRIES::getObject()
{
	return object;
}
