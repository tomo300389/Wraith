#pragma once

class Player
{
public:
	Player();
	
	void init(int Level, int Health, int Attack, int Defense, int Experience);

	int Attack();

	int takeDamage(int Attack);

	//Setters
	void SetPosition(int x, int y);

	void addExperience(int experience);

	//Getters
	void GetPosition(int &x, int &y);


private:

	//Properties
	int _Level;
	int _Health;
	int _Attack;
	int _Defense;
	int _Experience;

	//Location
	int _x;
	int _y;

};

