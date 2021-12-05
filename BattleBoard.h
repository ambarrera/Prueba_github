#pragma once
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "BattleNpc.h"

class BattleBoard
{
public:
	BattleBoard(int boardRows, int BoardColumns, int objectType);
	~BattleBoard();
	void update();
	void draw(char** screen);

private:
	int frames;
	int rows;
	int columns;
	int** board;
	BattleEnemy enemy;
	BattlePlayer player;
	BattleNpc npc;
};
