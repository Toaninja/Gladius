#pragma once

#include <iostream>
#include <random>
#include "stories.h"
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

float roll(int x = 101, int y = 100) {

	srand(time(NULL));
	float val = (rand() % x)/y;
	return val;
};

int sign() {

	int pos = 1;
	int neg = -1;

	srand(time(NULL));
	int val = rand() % 2;
	if (val == 0)
	{
		return neg;
	}
	else
	{
		return pos;
	}

};

//Attack is a percentage, strength is damage value, defence is blocking, HP is max health

Gladiator combatLoop(Gladiator g1, Gladiator g2) {

	float g1Health = *g1.HP;
	float g2Health = *g2.HP;

	if (g1Health > 0 || g2Health > 0)
	{
		if (*g1.attack * roll(101, 1) > 0.5) {

			float hit = *g1.strength + sign() * roll(*g1.strength/2);

			float block = *g2.defence * roll(*g2.defence);

			if (hit < block) {
				block = hit;
			}
			if (hit > g2Health)
			{
				hit = g2Health;
			}

			g2Health - hit + block;

			fstories(g1.name, g2Health, hit, block);

			if (g2Health <= 0) {
				return g1;
			}

		};

		combatLoop(g2, g1);

	}

};


void engine(Gladiator g1, Gladiator g2) {

	Gladiator winner, loser;

	winner = combatLoop(g1, g2);

	if (winner.name == g1.name && winner.focus == g1.focus) {
		loser = g2;
		
		g1.wins++;
		g2.losses++;
		g2.matchMarker;			//bitwise operator here
	}
	else {
		loser = g1;
	}



};