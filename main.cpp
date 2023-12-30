#include<iostream>
#include "game/game.h"

int main() {
	GAME game;
	game.init();
	game.run();
	game.end();
	return 0;
}