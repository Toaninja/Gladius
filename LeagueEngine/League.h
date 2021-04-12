#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include "Gladiator.h"

using namespace std;


class League
{
	int tier;
	int modifier;

public:
	League();

	League(int tier, int modifier);

	void setLeagueTier(int x);
	void setModifier(int y);

	int getLeagueTier();
	int getModifier();

	/*void standingsUpdate()
	{

	}*/
};

