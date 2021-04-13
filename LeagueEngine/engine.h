#pragma once

#include <iostream>
#include <random>

#include "Gladiator.h"
#include "stories.h"
using namespace std;


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

			if (hit > g2Health) {
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

Gladiator g1; //Find a way to always put our gladiator here

Gladiator* selection(vector <Gladiator*> vec) {
	for (int i = 0; i < 9; i++)
	{
		if (vec[i]->getMatchMarker() < 2)
		{
			vec[i]->setMatchMarker();
			return vec[i];
		}
	}
}



void engine(vector <Gladiator*> vec) {

	Gladiator *g1 = vec[9];

	//memcpy(g1, vec[9], sizeof(Gladiator));

	Gladiator *g2 = selection(vec);

	Gladiator winner;

	int g1Health = g1->getHP();
	int g2Health = g2->getHP();

	winner = combatLoop(*g1, *g2);

	g1->setHP(g1Health);


	if (winner.getName() == g1->getName() && winner.getFocus() == g1->getFocus()) {

		
		int wins = g1->getWins();
		int loss = g2->getLosses();

		g1->setWins(wins++);
		g2->setLoss(loss++);
		g2->setMatchMarker();			
	}
	else {

		int wins = g2->getWins();
		int loss = g1->getLosses();

		g2->setWins(wins++);
		g1->setMatchMarker();
		g1->setLoss(loss++);
		
	}

	training(*g2, *g1);

};