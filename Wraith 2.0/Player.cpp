#include <random>
#include <ctime>

#include "Player.h"

using namespace std;

Player::Player()
{
	_x = 0;
	_y = 0;
}

//Sets the players stats
void Player::init(int Level, int Health, int Attack, int Defense, int Experience)
{
	_Level = Level;
	_Health = Health;
	_Attack = Attack;
	_Defense = Defense;
	_Experience = Experience;

}

int Player::Attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _Attack);

	return attackRoll(randomEngine);
}

//Sets The Position Of The Enemy
void Player::SetPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//Handles the players experience points
void Player::addExperience(int experience)
{
	_Experience += experience;

	//Level Up
	while (_Experience > 50)
	{
		printf("Leveled Up!\n");
		_Experience -= 50;
		_Attack += 10;
		_Defense += 5;
		_Health += 10;
		_Level++;
		system("PAUSE");
	}
}

//Get The Position Of The Player Using Reference Variables
void Player::GetPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

int Player::takeDamage(int Attack)
{
	Attack -= _Defense;
	//Check If Attack Damages
	if (Attack > 0)
	{
		_Health -= Attack;
		//Check If Dead
		if (_Health <= 0)
		{
			return 1;
		}
	}
	return 0;
}