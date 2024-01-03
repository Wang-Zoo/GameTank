#pragma once
#include<vector>
#include"object/bullet.h"
#include"manager/barriesmanager.h"
struct BULLET_MANAGER
{
private:
	std::vector<BULLET> vector;
	BARRIES_MANAGER* bm = 0;

public:
	void init(BARRIES_MANAGER* bm);
	void add(int x,int y,int dir,bool isEnemy);
	void run();
	void clear();
	bool collision(OBJECT* other, int dir, bool isEnemy);

};

