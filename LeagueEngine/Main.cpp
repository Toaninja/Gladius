//Notes:
//detect if player has played against a gladiator in the league? 
//	Use flag? 
//2D array can be player with W/L against each gladiator 
//Add failure checks for memory allocation
//
//Enhancements:
//round robin to random W/L for random gladiators
//
//Bugs/challenges:
//Can't use command line arg as define feature 

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define LEAGUE_SIZE //atoi(argv[1])				//10 gladiators per league always
#define CREATE_FOCUS 1.5						//initial multiplier for when player creates their gladiator

//typedef struct Background
//{
//	string city; 
//	string trait;
//}background;


class Gladiator
{
	string name;
	//Background background;

	/*int* HP = new int;
	float* attack = new float;
	float* strength = new float;
	float* defence = new float;*/

	int* HP;
	float* attack;
	float* strength;
	float* defence;

	int league;
	int rank;
	int wins;
	int losses;

public:
	Gladiator()
	{

		this->name = "Unknown";
		//this->background.city = "Unknown";
		//this->background.trait = "Unknown";

		/*this->HP = new int;
		this->attack = new float;
		this->strength = new float;
		this->defence = new float;*/

		HP = new int;
		attack = new float;
		strength = new float;
		defence = new float;

		this->league = 0;
		this->rank = 0;
		this->wins = 0;
		this->losses = 0;
	}

	/*Gladiator(string name, int HP, float attack, float strength, float defence)
	{
		this->name = name;

		this->HP = new int;
		this->attack = new float;
		this->strength = new float;
		this->defence = new float;

		*this->HP = HP;
		*this->attack = attack;
		*this->strength = strength;
		*this->defence = defence;
	}*/

	void setName(string nameInput)
	{
		this->name = nameInput;
	}
	
	void setAttributes(int HP, float attack, float strength, float defence)
	{
		/*this->HP = new int;
		this->attack = new float;
		this->strength = new float;
		this->defence = new float;*/
		
		*this->HP = HP;
		*this->attack = attack;
		*this->strength = strength;
		*this->defence = defence;
	}

	friend void generatePlayer(Gladiator player, string name, int focusInput);


	//get functions used for testing
	string getName()
	{
		return this->name;
	}
	int getHP()
	{
		return *this->HP;
	}
	float getAttack()
	{
		//this->attack = new float;
		return *this->attack;
	}
	float getStrength()
	{
		return *this->strength;
	}
	float getDefence()
	{
		return *this->defence;
	}

	void updateGladiator()
	{

	}

	~Gladiator()
	{
		//delete HP, attack, strength, defence;
		delete HP;
		delete attack;
		delete strength;
		delete defence;
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

	void standingsUpdate()
	{

	}
};

void generatePlayer(Gladiator *player, string name, int focusInput)
{
	//1=attack focused
	//2=strength focused
	//3=defence focused
	//adjust starting numbers and modifiers

	player->setName(name);

	int HP = (rand() % (10 - 7 + 1)) + 7;				//7-10 HP
	float attack = ((rand() % (5 - 1 + 1)) + 1);		//1-5 combat stats
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

	player->setAttributes(HP, attack, strength, defence);

}

//int main(int argc, char* argv[])
int main(void)
{
	srand(time(NULL));

	Gladiator* player = new Gladiator;
	string name = "testname";
	int focusInput = 1; 

	generatePlayer(player, name, focusInput);
	cout << player->getAttack() << endl;


	return 0;
}