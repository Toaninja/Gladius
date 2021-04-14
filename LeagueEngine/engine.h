#pragma once

#include <iostream>
#include <random>
#include "training.h"
#include "Gladiator.h"
#include "stories.h"
using namespace std;


float roll(float x = 101, float y = 100);


int sign();


//Attack is a percentage, strength is damage value, defence is blocking, HP is max health
Gladiator *combatLoop(Gladiator* g1, Gladiator* g2);



Gladiator* selection(vector <Gladiator*> &vec);



void engine(vector <Gladiator*> &vec);