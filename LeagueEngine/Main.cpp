//test

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define LEAGUE_SIZE //atoi(argv[1])				//10 gladiators per league always

typedef struct Background
{
	string city; 
	string trait;
}background;


class Gladiator
{
	string name;
	Background background;

	int* HP;
	float* attack;
	float strength;
	float defence;

	int league;
	int rank;
	int wins;
	int losses;

public:
	Gladiator()
	{

		this->name = "";
		this->background.city = "";
		this->background.trait = "";

		this->HP = 0;
		this->attack = 0;
		this->strength = 0;
		this->defence = 0;

		this->league = 0;
		this->rank = 0;
		this->wins = 0;
		this->losses = 0;
	}

	void updateGladiator();

};

class League
{
	int tier;
	int modifer;
	Gladiator array[10];

public:
	League()
	{
		this->tier = 0;
		this->modifer = 0;
		this->array[10] = {};
	}

	League(int tier, int modifier, Gladiator array[])
	{
		this->tier = tier;
		this->modifer = modifier;
		for(int i=0; i < 10; i++)
			this->array[i] = array[i];
	}

	void setLeagueTier(int x)
	{
		this->tier = tier;
	}

	void standingsUpdate();
};

Gladiator generatePlayer(int input)
{
	//1=HP focused
	//2=attack focused
	//3=strength focused
	//4=defence focused


	if (input == 1)
	{

	}
}


int main(int argc, char* argv[])
{


}