#include "engine.h"
#include "training.h"

//1==attack, 2==strength, 3==defence

void training(Gladiator *winner, Gladiator *loser) {

	switch (winner->getFocus()) {
	case 1: winner->setAttack(winner->getAttack() + roll() * 0.5);
	case 2: winner->setStrength(winner->getStrength() + roll() * 0.5);
	case 3: winner->setDefence(winner->getDefence() + roll() * 0.5);

	}

	winner->setAttack(winner->getAttack() + roll() * 0.1);
	winner->setStrength(winner->getStrength() + roll() * 0.1);
	winner->setDefence(winner->getDefence() + roll() * 0.1);
	winner->setHP(winner->getHP() + roll() * 0.4);

	switch (loser->getFocus()) {
	case 1: loser->setAttack(loser->getAttack() + roll() * 0.5);
	case 2: loser->setStrength(loser->getStrength() + roll() * 0.5);
	case 3: loser->setDefence(loser->getDefence() + roll() * 0.5);

	}

	loser->setAttack(loser->getAttack() + roll() * 0.1);
	loser->setStrength(loser->getStrength() + roll() * 0.1);
	loser->setDefence(loser->getDefence() + roll() * 0.1);
	loser->setHP(loser->getHP() + roll() * 0.4);
	}