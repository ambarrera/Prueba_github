#include "Creature.h"

Creature::Creature(int x, int y, char symbol):
	Object(x, y, symbol, true)
{
	isInteracting = 0;
}

void Creature::move(Direction direction) {
	switch (direction) {
	case Direction::LEFT:
		x--;
		break;
	case Direction::RIGHT:
		x++;
		break;
	case Direction::UP:
		y--;
		break;
	case Direction::DOWN:
		y++;
		break;
	default:
		break;
	}
}