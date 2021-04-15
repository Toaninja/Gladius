#include "engine.h"
#include "training.h"

//1==attack, 2==strength, 3==defence

void training(Gladiator* winner, int win) 
{
	if (win == 1) 
	{
		switch (winner->getFocus()) 
		{
		case 1: winner->setAttack(winner->getAttack() + roll() * 0.4);
		case 2: winner->setStrength(winner->getStrength() + roll() * 0.4);
		case 3: winner->setDefence(winner->getDefence() + roll() * 0.4);
		}

		winner->setAttack(winner->getAttack() + roll() * 0.1);
		winner->setStrength(winner->getStrength() + roll() * 0.1);
		winner->setDefence(winner->getDefence() + roll() * 0.1);
		winner->setHP(winner->getHP() + roll() * 0.4);

	}

	else 
	{
		switch (winner->getFocus()) 
		{
		case 1: winner->setAttack(winner->getAttack() + roll() * 0.1);
		case 2: winner->setStrength(winner->getStrength() + roll() * 0.1);
		case 3: winner->setDefence(winner->getDefence() + roll() * 0.1);
		}

		winner->setAttack(winner->getAttack() + roll() * 0.1);
		winner->setStrength(winner->getStrength() + roll() * 0.1);
		winner->setDefence(winner->getDefence() + roll() * 0.1);
		winner->setHP(winner->getHP() + roll() * 0.4);
	}
}