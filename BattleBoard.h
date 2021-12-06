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

	BattlePlayer player;
	BattleEnemy enemy;

private:
	int frames;
	int rows;
	int columns;
	int** board;
	BattleNpc npc;
};
