#include <fstream>
#include <iostream>
#include <cstdio>

#include "Level.h"



Level::Level()
{
}

void Level::load(string fileName, Player &player)
{

	//Loads Level
	ifstream file;
	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line))
	{
		_levelData.push_back(line);
	}

	file.close();

	//Process Level Characters
	char tile;
	for (int i = 0; i < _levelData.size(); i++)
	{

		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];

			//Player

			switch (tile)
			{
			case '@': //Player
				player.SetPosition(j, i);
				break;

			//Enemies 

			case 'S': //Snake
				_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
				_enemies.back().SetPosition(j, i);
				break;
			case 'g': //Goblin
				_enemies.push_back(Enemy("Goblin", tile, 2, 5, 3, 15, 20));
				_enemies.back().SetPosition(j, i);
				break;
			case 'O': //Ogre
				_enemies.push_back(Enemy("Ogre", tile, 5, 10, 7, 30, 40));
				_enemies.back().SetPosition(j, i);
				break;
			case 'D': //Dragon
				_enemies.push_back(Enemy("Dragon", tile, 10, 20, 15, 75, 100));
				_enemies.back().SetPosition(j, i);
				break;
			}

		}
	}
}

//Prints the level to the screen
void Level::print()
{
	cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s \n", _levelData[i].c_str());
	}
	printf("\n");
}

//Handles the inputs for player movement
void Level::MovePlayer(char input, Player &player)
{
	int playerX;
	int playerY;

	player.GetPosition(playerX, playerY);

	switch (input)
	{
	case 'w': //Up
	case 'W':
		HandlePlayerMove(player, playerX, playerY - 1);
		break;

	case 'a': //Left
	case 'A':
		HandlePlayerMove(player, playerX - 1, playerY);
		break;

	case 's': //Down
	case 'S':
		HandlePlayerMove(player, playerX, playerY + 1);
		break;

	case 'd': //Right
	case 'D':
		HandlePlayerMove(player, playerX + 1, playerY);
		break;

	default:
		printf("INVALID INPUT\n");
		system("PAUSE");
		break;
	}
}

char Level::GetTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::SetTile(int x, int y, char Tile)
{
	_levelData[y][x] = Tile;
}

//Handles the players postition before and after movement input
void Level::HandlePlayerMove(Player &player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player.GetPosition(playerX, playerY);


	char MoveTile = GetTile(targetX, targetY);

	switch (MoveTile)
	{
	case '.':
		player.SetPosition(targetX, targetY);
		SetTile(playerX, playerY, '.');
		SetTile(targetX, targetY, '@');
		break;

	case '#':
		break;

	default:
		FightEnemy(player, targetX, targetY);
		break;

	}
}

//Sets all the logic for enemy encounters
void Level::FightEnemy(Player &player, int targetX, int targetY)
{

	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;
	string enemyName;

	player.GetPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++)
	{

		_enemies[i].GetPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();

		if (targetX == enemyX && targetY == enemyY)
		{

			//Fight
			attackRoll = player.Attack();
			printf("\nYou Attacked %s With A Roll Of %d\n", enemyName.c_str(), attackRoll);
			attackResult = _enemies[i].takeDamage(attackRoll);


			if (attackResult != 0)
			{
				SetTile(targetX, targetY, '.');
				print();
				printf("You Defeated The Enemy!\n");
				system("PAUSE");
				player.addExperience(attackResult);


				return;
			}
			//Enemy Turn
			attackRoll = _enemies[i].attack();
			printf("%S Attacked You With A Roll Of %d\n", enemyName.c_str(), attackRoll);
			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0)
			{
				SetTile(playerX, playerY, 'X');
				print();
				printf("You Died!\n");
				system("PAUSE");

				exit(0);

			}
			system("PAUSE");
			return;
		}
    }
}