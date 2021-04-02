#pragma once

#include <iostream>
#include <random>
using namespace std;

class Gladiator
{
	string name;

	int* HP;
	float* attack;
	float* strength;
	float* defence;

	int league;
	int wins;
	int losses;
	int focus;				//1==attack, 2==strength, 3==defence
	int matchMarker;

public:
	Gladiator();

	void setName(string nameInput);
	void setHP(int HP);
	void setAttack(float attack);
	void setStrength(float strength);
	void setDefence(float defence);
	void setWins(int wins);
	void setLoss(int losses);
	void setFocus(int focusInput);
	void setAttributes(int HP, float attack, float strength, float defence);

	void promote();
	void demote();


	friend void engine(Gladiator g1, Gladiator g2);
	friend Gladiator combatLoop(Gladiator g1, Gladiator g2);
};

float roll(int x = 101) {

	srand(time(NULL));
	float val = (rand() % x)/100;
	return val;
};

int sign() {

	srand(time(NULL));
	int val = rand() % 2;
	if (val == 0 || val == 1)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}


Gladiator combatLoop(Gladiator g1, Gladiator g2) {

	if (g1.HP > 0 || g2.HP > 0)
	{
	


	}

}


void engine(Gladiator g1, Gladiator g2) {

	Gladiator winner, loser;

	



}