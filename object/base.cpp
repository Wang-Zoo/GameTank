#include "base.h"
#include "config/config.h"

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

bool OBJECT::collision(OBJECT *other,int dir,bool adjust)
{
	OBJECT& tempObject = (*other);
	bool isLeftFlag = tempObject.x + tempObject.width <= this->x;
	bool isRightFlag = tempObject.x >= this->x + this->width;
	bool isUpFlag = tempObject.y + tempObject.height <= this->y;
	bool isBottomFlag = tempObject.y >=this->y + this->height;
	if (isLeftFlag || isRightFlag || isUpFlag || isBottomFlag) {
		return false;
	}
	else {
		if (adjust) {
			switch (dir)
			{
			case TANK_DIR_DOWN:
				tempObject.setY(this->y - tempObject.height);
				break;
			case TANK_DIR_UP:
				tempObject.setY(this->y + this->height);
				break;
			case TANK_DIR_RIGHT:
				tempObject.setX(this->x - tempObject.getWidth());
				break;
			case TANK_DIR_LEFT:
				tempObject.setX(this->x + this->width);
				break;
			}
		}
		return true;
	}
}
