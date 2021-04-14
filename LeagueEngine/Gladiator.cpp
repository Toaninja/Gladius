#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include "Gladiator.h"
#include "League.h"

using namespace std;

#define LEAGUE_SIZE //atoi(argv[1])				//10 gladiators per league always
#define CREATE_FOCUS 1.5						//initial multiplier for when player creates their gladiator



Gladiator::Gladiator()
{

	this->name = "Unknown";
	//this->background.city = "Unknown";
	//this->background.trait = "Unknown";

	HP = new float;
	attack = new float;
	strength = new float;
	defence = new float;

	this->league = 0;
	this->wins = 0;
	this->losses = 0;
	this->focus = 0;
	this->matchMarker = 0;
}

void Gladiator::setName(string nameInput)
{
	this->name = nameInput;
}
void Gladiator::setHP(int HP)
{
	*this->HP = HP;
}
void Gladiator::setAttack(float attack)
{
	*this->attack = attack;
}
void Gladiator::setStrength(float strength)
{
	*this->strength = strength;
}
void Gladiator::setDefence(float defence)
{
	*this->defence = defence;
}
void Gladiator::setWins(int wins)
{
	this->wins = wins;
}
void Gladiator::setLoss(int losses)
{
	this->losses = losses;
}

void Gladiator::promote()
{
	this->league++;
}
void Gladiator::demote()
{
	this->league--;
}

void Gladiator::setAttributes(int HP, float attack, float strength, float defence)
{
	*this->HP = HP;
	*this->attack = attack;
	*this->strength = strength;
	*this->defence = defence;
}

void Gladiator::setFocus(int focusInput)
{
	this->focus = focusInput;
}

void Gladiator::setMatchMarker()
{
	this->matchMarker++;
}


//get functions, some created just for testing
string Gladiator::getName()
{
	return this->name;
}
float Gladiator::getHP()
{
	return *this->HP;
}
float Gladiator::getAttack()
{
	return *this->attack;
}
float Gladiator::getStrength()
{
	return *this->strength;
}
float Gladiator::getDefence()
{
	return *this->defence;
}
int Gladiator::getWins()
{
	return this->wins;
}
int Gladiator::getLosses()
{
	return this->losses;
}
int Gladiator::getFocus()
{
	return this->focus;
}
int Gladiator::getLeague()
{
	return this->league;
}

int Gladiator::getMatchMarker()
{
	return this->matchMarker;
}

Gladiator::~Gladiator()
{
	//delete HP, attack, strength, defence;
	delete HP;
	delete attack;
	delete strength;
	delete defence;
}


void generatePlayer(Gladiator* player, string name, int focusInput)					//generate randomized stats with initial focus for player
{																					//and assign name
	//1=attack focused
	//2=strength focused
	//3=defence focused
	//adjust starting numbers and modifiers

	player->setName(name);

	int HP = (rand() % (10 - 7 + 1)) + 7;				//7-10 HP
	float attack = ((rand() % (5 - 1 + 1)) + 5);		//1-5 combat stats
	float strength = (rand() % (5 - 1 + 1)) + 1;
	float defence = (rand() % (5 - 1 + 1)) + 1;

	if (focusInput == 1)
	{
		attack = attack * CREATE_FOCUS;
	}

	else if (focusInput == 2)
	{
		strength = strength * CREATE_FOCUS;
	}

	else if (focusInput == 3)
	{
		defence = defence * CREATE_FOCUS;
	}

	else
	{
		//error 
		return;
	}

	player->setAttributes(HP, attack, strength, defence);
}


Gladiator* generateGladiator(int i, League general)									//create random gladiators, called in vector array loop
{
	Gladiator* temp = new Gladiator;												//temp which will be returned and assigned to an index
	int modifier = general.getModifier();

	string name = "Gladiator" + to_string(i + 1);									//gladiator name ie index 3, Gladiator name = "Gladiator4"
	temp->setName(name);

	int HP = ((rand() % (10 - 7 + 1)) + 7) + modifier;			//7-10 HP
	float attack = ((rand() % (5 - 1 + 1)) + 1) + modifier;		//1-5 combat stats
	float strength = (rand() % (5 - 1 + 1)) + 1 + modifier;
	float defence = (rand() % (5 - 1 + 1)) + 1 + modifier;

	temp->setAttributes(HP, attack, strength, defence);

	return temp;
}

void trainingFocus(Gladiator* player, int focusInput)								//player selects training focus
{
	if (focusInput == 1)															//1==attack focus
		player->setFocus(focusInput);

	else if (focusInput == 2)														//2==strength focus
		player->setFocus(focusInput);

	else if (focusInput == 3)														//3==defence focus
		player->setFocus(focusInput);

	else																			//invalid response
	{
		//invalid
		return;
	}
}


bool cmp(Gladiator* one, Gladiator* two)											//used for vector sort to sort standings based on wins 
{
	return one->getWins() > two->getWins();											//comparing 2 gladiators' wins at a time, take biggest
}