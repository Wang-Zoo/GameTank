#pragma once
#include "object/box.h"
#include "vector"

struct BOX_MANAGER {
private:
	std::vector<BOX> vector;
	unsigned long long lastTime = 0l;
public:
	void init();
	void add();
	void run();
	void clear();
	int collision(OBJECT object,int dir);
};