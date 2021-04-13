#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include "League.h"

using namespace std;

class Gladiator
{
	string name;
	//Background background;


	float *HP;
	float *attack;
	float *strength;
	float *defence;

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
	void setMatchMarker();
	void setAttributes(int HP, float attack, float strength, float defence);

	void promote();
	void demote();

	//get functions, some created just for testing
	string getName();
	float getHP();
	float getAttack();
	float getStrength();
	float getDefence();
	int getWins();
	int getMatchMarker();
	int getLosses();
	int getFocus();
	int getLeague();

	~Gladiator();

	friend Gladiator combatLoop(Gladiator g1, Gladiator g2);
	friend void training(Gladiator winner, Gladiator loser);
};

void generatePlayer(Gladiator* player, string name, int focusInput);
Gladiator* generateGladiator(int i, League general);
void trainingFocus(Gladiator* player, int focusInput);
bool cmp(Gladiator* one, Gladiator* two);