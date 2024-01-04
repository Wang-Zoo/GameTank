#include<iostream>
#include "game/game.h"

int main() {

	GAME game;
	while (true)
	{
		game.init();
		if (game.run() != ACTION_NONE)
			break;
		game.end();
	}
	return 0;
}