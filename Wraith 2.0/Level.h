#pragma once
#include <vector>
#include <string>

#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
public:
	Level();

	void load(string fileName, Player &player);
	
	void print();

	void MovePlayer(char input, Player &player);
	//Getters
	char GetTile(int x, int y);
	//Setters
	void SetTile(int x, int y, char Tile);

private:

	void HandlePlayerMove(Player &player, int targerX, int targetY);

	void FightEnemy(Player &player, int targerX, int targerY);
	
private:
	vector <string> _levelData;
	vector <Enemy> _enemies;
	
};

