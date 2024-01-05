#pragma once
struct TITLE
{
private:
	int enemy = 0;
	void update();
public:
	void init();
	void run();
	void setEnemyNum(int num);
};