#include "tool.h"
#include <cstdlib>

int RANDOM(int min, int max)
{
	if (min > max) {
		min = max ^ min;
		max = max ^ min;
		min = max ^ min;
	}
	int randomNumber = min + std::rand() % (max - min + 1);
	return randomNumber;
}
