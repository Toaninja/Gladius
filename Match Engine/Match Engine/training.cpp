#include "training.h"


/*
if win
training x 1.0
if loss
training x 0.7

if 1...
if 2...
if 3...


*/

//1==attack, 2==strength, 3==defence

void training(Gladiator winner, Gladiator loser) {

	switch (winner.focus) {
	case 1: *winner.attack = *winner.attack + roll() * 0.5;
	case 2: *winner.strength = *winner.strength + roll() * 0.5;
	case 3: *winner.defence = *winner.defence + roll() * 0.5;
	default: 
	}

	switch (loser.focus) {
	case 1: *loser.attack = *loser.attack + roll() * 0.35;
	case 2: *loser.strength = *loser.strength + roll() * 0.35;
	case 3: *loser.defence = *loser.defence + roll() * 0.35;
	default:
	}
}