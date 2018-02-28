#include <random>
#include <ctime>

#include "Enemy.h"



Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int exp)
{

	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_exprianceValue = exp;

}

//Sets The Position Of The Enemy
void Enemy::SetPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//Get The Position Of The Enemy Using Reference Variables
void Enemy::GetPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

int Enemy::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack)
{
	attack -= _defense;
	//Check If Attack Damages
	if (attack > 0)
	{
		_health -= attack;
		//Check If Dead
		if (_health <= 0)
		{
			return _exprianceValue;
		}
	}
	return 0;
}