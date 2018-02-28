#pragma once
#include <String>

#include "Player.h"
#include "Level.h"

using namespace std;

class GameSystem
{
public:
	GameSystem(string LevelFileName);
	
	void PlayGame();
	void PlayerMove();

private:

	Level _level;
	Player _player;
	
};

