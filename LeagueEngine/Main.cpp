//Notes:
//detect if player has played against a gladiator in the league? 
//	Use flag? 
//2D array can be player with W/L against each gladiator 
//Add failure checks for memory allocation
//copy constructor and assignment operator for player to be put in array?
//flag member for gladiator, when =2, that gladiator has fought the player twice 
// 
//Enhancements:
//round robin to random W/L for random gladiators
//
//Bugs/challenges:
//Can't use command line arg as define feature 

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

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
	int focus;				//1==attack, 2==strength, 3==defence
	int matchMarker;

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
		this->focus = 0;
		this->matchMarker = 0;
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
	void setHP(int HP)
	{
		*this->HP = HP;
	}
	void setAttack(float attack)
	{
		*this->attack = attack;
	}
	void setStrength(float strength)
	{
		*this->strength = strength;
	}
	void setDefence(float defence)
	{
		*this->defence = defence;
	}
	void setWins(int wins)
	{
		this->wins = wins;
	}
	void setLoss(int losses)
	{
		this->losses = losses;
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

	//friend void generatePlayer(Gladiator player, string name, int focusInput);
	void setFocus(int focusInput)
	{
		this->focus = focusInput;
	}


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
	int getWins()
	{
		return this->wins;
	}
	int getLosses()
	{
		return this->losses;
	}
	int getFocus()
	{
		return this->focus;
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
	//Gladiator array[10];

public:
	League()
	{
		this->tier = 0;
		this->modifer = 0;
		//this->array[10] = {};
	}

	League(int tier, int modifier, Gladiator array[])
	{
		this->tier = tier;
		this->modifer = modifier;
		/*for(int i=0; i < 10; i++)
			this->array[i] = array[i];*/
	}

	void setLeagueTier(int x)
	{
		this->tier = x;
	}
	void setModifier(int y)
	{
		this->modifer = y;
	}

	int getLeagueTier()
	{
		return this->tier;
	}
	int getModifier()
	{
		return this->modifer;
	}

	void standingsUpdate()
	{

	}
};


//typedef struct Match
//{
//	Gladiator matches;
//};



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

	else if(focusInput == 3)
	{
		defence = defence * CREATE_FOCUS;
	}

	else
	{
		//error 
		return;
	}

	player->setAttributes(HP, attack, strength, defence);

}

//void generateGladiator(Gladiator array[], int i)
//{
//
//	string name = "Gladiator" + to_string(i+1);
//	array[i].setName(name);
//
//	//if league tier = 5
//	int HP = (rand() % (10 - 7 + 1)) + 7;				//7-10 HP
//	float attack = ((rand() % (5 - 1 + 1)) + 1);		//1-5 combat stats
//	float strength = (rand() % (5 - 1 + 1)) + 1;
//	float defence = (rand() % (5 - 1 + 1)) + 1;
//
//	array[i].setAttributes(HP, attack, strength, defence);
//
//}

Gladiator* generateGladiator(int i, League object)
{
	Gladiator *temp = new Gladiator;

	string name = "Gladiator" + to_string(i + 1);
	temp->setName(name);

	//if league tier = 5
	int HP = (rand() % (10 - 7 + 1)) + 7;				//7-10 HP
	float attack = ((rand() % (5 - 1 + 1)) + 1);		//1-5 combat stats
	float strength = (rand() % (5 - 1 + 1)) + 1;
	float defence = (rand() % (5 - 1 + 1)) + 1;

	temp->setAttributes(HP, attack, strength, defence);

	return temp;

}

void trainingFocus(Gladiator *player, int focusInput)
{
	if (focusInput == 1)
		player->setFocus(focusInput);

	else if(focusInput == 2)
		player->setFocus(focusInput);

	else if(focusInput == 3)
		player->setFocus(focusInput);

	else
	{
		//invalid
		return;
	}
}



bool cmp(Gladiator* one, Gladiator* two)
{
	return one->getWins() > two->getWins();
}

//int main(int argc, char* argv[])
int main(void)
{
	srand(time(NULL));

	League league1;
	League league2;
	League league3;
	League league4;
	League league5;
	League general;

	Gladiator* player = new Gladiator;
	string name = "testname";
	int focusInput = 1; 

	generatePlayer(player, name, focusInput);
	cout << player->getAttack() << endl;



	//Gladiator* array = new Gladiator[10];
	//Gladiator array[10];
	vector <Gladiator*> vec;
	for (int i = 0; i < 9; i++)
	{
		vec.push_back(generateGladiator(i));
	}

	//Test random gladiators
	cout << vec[1]->getName() << endl;
	//cout << [8].getName() << endl;
	cout << vec[1]->getAttack() << endl;
	//cout << array[8].getAttack() << endl;*/

	vec.push_back(player);
	cout << vec[9]->getName() << endl;

	//League league5(5, 0, array);
	vec[9]->setWins(5);
	vec[5]->setWins(2);

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i]->getName() << " " << vec[i]->getWins() << " " << vec[i]->getLosses() << endl;
	}

	if (vec[0]->getName() == player->getName() || vec[1]->getName() == player->getName())
	{

	}
	vec.clear();
	cout << "check" << player->getName() << endl;

	return 0;
}