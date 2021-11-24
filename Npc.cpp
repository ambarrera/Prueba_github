#include "Npc.h"

Npc::Npc(int x, int y, char symbol, char* name):
	Creature(x, y, symbol)
{
	for (int i = 0; name[i] != '\0'; i++) {
		this->name[i] = name[i];
	}
}