# Wraith

#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level, int attack, int defense, int health, int exp);

	int attack();

	int takeDamage(int attack);

	//Setters
	void SetPosition(int x, int y);

	//Getters
	void GetPosition(int &x, int &y);

	string getName() { return _name; }
	
private:
	
	string _name;
	char _tile;

	int _level;
	int _attack;
	int _defense;
	int _health;
	int _exprianceValue;

	//Location
	int _x;
	int _y;

};
