#pragma once
#include"base.h"

struct TANK {
private:
	OBJECT object;
	const char* picKey = 0;
public:
	void init();
	void setPicKey(const char* key);
	void run();
};