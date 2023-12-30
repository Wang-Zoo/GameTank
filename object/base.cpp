#include "base.h"

int OBJECT::getX()
{
	return this->x;
}

int OBJECT::getY()
{
	return this->y;
}

int OBJECT::getWidth()
{
	return this->width;
}

int OBJECT::getHeight()
{
	return this->height;
}

void OBJECT::setX(int x)
{
	this->x = x;
}

void OBJECT::setY(int y)
{
	this->y = y;
}

void OBJECT::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}
