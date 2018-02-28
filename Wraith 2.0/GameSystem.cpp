#include <iostream>
#include <conio.h>

#include "GameSystem.h"


//Constructor Sets Up The Game
GameSystem::GameSystem(string LevelFileName)
{
	_player.init(1, 100, 10, 10, 0);

	_level.load(LevelFileName, _player);
	

	system("PAUSE");
}

//Starts the ability to play the game
void GameSystem::PlayGame()
{
	bool IsDone = false;

	while (IsDone != true)
	{
		_level.print();
		PlayerMove();
	}
}

//Enables player movement and sets text to screen
void GameSystem::PlayerMove()
{
	char input;
	printf("To Move Press (W/A/S/D): ");
	input = _getch();

	_level.MovePlayer(input, _player);

}