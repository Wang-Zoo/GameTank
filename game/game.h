#pragma once


struct GAME
{
private:
	int mapWidth;
	int mapHeight;
public:
	int getWidth();
	int getHeight();
	void init();
	void run();
	void end();

};