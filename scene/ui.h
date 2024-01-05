#pragma once
struct UI 
{
public:
	void init();
	int run();
	void end();
};
struct UI_START {
private:
	int ay = 0;
public:
	void init();
	int run();
	void end();
};
struct UI_STAGE_ONE {
private:
	unsigned long long lastTime = 0l;
public:
	void init();
	int run();
	void end();
};
struct UI_STAGE_TWO {
public:
	void init();
	int run();
	void end();
};
struct UI_STAGE_AGAIN {
public:
	void init();
	int run();
	void end();
};
struct UI_END {
public:
	void init();
	int run();
	void end();
};