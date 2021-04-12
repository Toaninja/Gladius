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



League::League()
{
	this->tier = 0;
	this->modifier = 0;
}

League::League(int tier, int modifier)
{
	this->tier = tier;
	this->modifier = modifier;

}

void League::setLeagueTier(int x)
{
	this->tier = x;
}
void League::setModifier(int y)
{
	this->modifier = y;
}

int League::getLeagueTier()
{
	return this->tier;
}
int League::getModifier()
{
	return this->modifier;
}

/*void standingsUpdate()
{

}*/

	