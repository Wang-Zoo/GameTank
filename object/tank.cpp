#include"tank.h"
#include"config/config.h"
#include"tool/output.h"

void TANK::init()
{
	object.setX(0);
	object.setY(0);
	object.setSize(TANK_WIDTH, TANK_HEIGHT);
}

void TANK::setPicKey(const char* key)
{
	this->picKey = key;
}

void TANK::run()
{
	g_op.DrawPic(picKey, object.getX(), object.getY());
}
