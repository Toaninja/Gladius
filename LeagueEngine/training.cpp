#include "engine.h"
#include "training.h"

//1==attack, 2==strength, 3==defence

//void training(Gladiator *winner, Gladiator *loser) {
//
//	switch (winner->getFocus()) {
//	case 1: winner->getAttack() = winner->getAttack + roll() * 0.5;
//	case 2: winner->getStrength = winner->getStrength + roll() * 0.5;
//	case 3: winner->getDefence = winner->getDefence + roll() * 0.5;
//
//	}
//
//	*winner.attack = *winner.attack + roll() * 0.1;
//	*winner.strength = *winner.strength + roll() * 0.1;
//	*winner.defence = *winner.defence + roll() * 0.1;
//	*winner.HP = *winner.HP + roll() * 0.4;
//
//
//	switch (loser.focus) {
//	case 1: *loser.attack = *loser.attack + roll() * 0.35;
//	case 2: *loser.strength = *loser.strength + roll() * 0.35;
//	case 3: *loser.defence = *loser.defence + roll() * 0.35;
//
//	}
//
//	*loser.attack = *loser.attack + roll() * 0.1;
//	*loser.strength = *loser.strength + roll() * 0.1;
//	*loser.defence = *loser.defence + roll() * 0.1;
//	*loser.HP = *loser.HP + roll() * 0.4;
//}