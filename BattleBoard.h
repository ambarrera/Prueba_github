#pragma once
#include "BattlePlayer.h"
#include "BattleEnemy.h"

class BattleBoard
{
public:
	BattleBoard(int boardRows, int BoardColumns);
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
};
