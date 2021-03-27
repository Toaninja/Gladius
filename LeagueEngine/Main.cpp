

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define LEAGUE_SIZE //atoi(argv[1])				//10 gladiators per league always
#define CREATE_FOCUS 1.5						//initial multiplier for when player creates their gladiator

typedef struct Background
{
	string city; 
	string trait;
}background;


class Gladiator
{
	string name;
	Background background;

	int* HP = new int;;
	float* attack = new float;
	float* strength = new float;
	float* defence = new float;

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

	void setName(string nameInput)
	{
		this->name = nameInput;
	}
	//getName for testing
	
	void setAttributes(int HP, float attack, float strength, float defence)
	{
		*this->HP = HP;
		*this->attack = attack;
		*this->strength = strength;
		*this->defence = defence;
	}

	void updateGladiator();

	~Gladiator()
	{
		delete HP, attack, strength, defence;
	}

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

Gladiator generatePlayer(Gladiator player, string name, int focusInput)
{
	//1=attack focused
	//2=strength focused
	//3=defence focused

	player.setName(name);

	int HP = (rand() % (10 - 7 + 1)) + 7;
	float attack = ((rand() % (5 - 1 + 1)) + 1);
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

	else
	{
		defence = defence * CREATE_FOCUS;
	}

	player.setAttributes(HP, attack, strength, defence);

}


int main(int argc, char* argv[])
{
	srand(time(NULL));

	Gladiator player;
	//Gladiator* player = new Gladiator;
	string name = "testname";
	int focusInput;


	generatePlayer(player, name, focusInput);




}