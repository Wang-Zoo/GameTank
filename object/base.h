#pragma once
struct OBJECT {
private:
	int x;
	int y;
	int width;
	int height;
public:
	int getX(); 
	int getY();
	int getWidth();
	int getHeight();
	void setX(int x);
	void setY(int y);
	void setSize(int width, int height);
	bool collision(OBJECT *other,int dir);
};