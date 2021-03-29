//Notes:
//2D array can be player with W/L against each gladiator 
//Add failure checks for memory allocation
//flag member for gladiator, when =2, that gladiator has fought the player twice 
// 
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


	int* HP;
	float* attack;
	float* strength;
	float* defence;

	int league;
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

		HP = new int;
		attack = new float;
		strength = new float;
		defence = new float;

		this->league = 0;
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

	void promote()
	{
		this->league++;
	}
	void demote()
	{
		this->league--;
	}
	
	void setAttributes(int HP, float attack, float strength, float defence)
	{
		*this->HP = HP;
		*this->attack = attack;
		*this->strength = strength;
		*this->defence = defence;
	}

	void setFocus(int focusInput)
	{
		this->focus = focusInput;
	}


	//get functions, some created just for testing
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
	int getLeague()
	{
		return this->league;
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

public:
	League()
	{
		this->tier = 0;
		this->modifer = 0;
	}

	League(int tier, int modifier)
	{
		this->tier = tier;
		this->modifer = modifier;
	
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



void generatePlayer(Gladiator *player, string name, int focusInput)					//generate randomized stats with initial focus for player
{																					//and assign name
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

Gladiator* generateGladiator(int i, League general)									//create random gladiators, called in vector array loop
{
	Gladiator *temp = new Gladiator;												//temp which will be returned and assigned to an index
	int modifier = general.getModifier();

	string name = "Gladiator" + to_string(i + 1);									//gladiator name ie index 3, Gladiator name = "Gladiator4"
	temp->setName(name);

	int HP = ((rand() % (10 - 7 + 1)) + 7) + modifier;			//7-10 HP
	float attack = ((rand() % (5 - 1 + 1)) + 1) + modifier;		//1-5 combat stats
	float strength = (rand() % (5 - 1 + 1)) + 1 + modifier;
	float defence = (rand() % (5 - 1 + 1)) + 1 + modifier;

	temp->setAttributes(HP, attack, strength, defence);

	return temp;
}

void trainingFocus(Gladiator *player, int focusInput)								//player selects training focus
{
	if (focusInput == 1)															//1==attack focus
		player->setFocus(focusInput);

	else if(focusInput == 2)														//2==strength focus
		player->setFocus(focusInput);

	else if(focusInput == 3)														//3==defence focus
		player->setFocus(focusInput);

	else																			//invalid response
	{
		//invalid
		return;
	}
}



bool cmp(Gladiator* one, Gladiator* two)											//used for vector sort to sort standings based on wins 
{
	return one->getWins() > two->getWins();											//comparing 2 gladiators' wins at a time, take biggest
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	League league1(1, 1);															//create 5 league objects
	League league2(2, 2);
	League league3(3, 3);
	League league4(4, 4);
	League league5(5, 5);

	League general = league1;														//general league object or current one running

	Gladiator* player = new Gladiator;												//create player gladiator object
	
	string name = "testname";														//testing name and initial focus input
	int focusInput = 1; 

	generatePlayer(player, name, focusInput);
	cout << player->getAttack() << endl;


	//Gladiator* array = new Gladiator[10];
	//Gladiator array[10];
	vector <Gladiator*> vec;														//create vector array of random gladiators
	for (int i = 0; i < 9; i++)
	{
		vec.push_back(generateGladiator(i, general));								//assign each gladiator to growing index until 
	}																				//index 8 (9 gladiators)

	cout << vec[1]->getName() << endl;										//testing if random gladiators were produced and members populated
	cout << vec[1]->getAttack() << endl;

	vec.push_back(player);															//add player to gladiator array
	cout << vec[9]->getName() << endl;


	//pass vector array of gladiators and player to match engine, get results

	vec[9]->setWins(5);																//testing sort function to see if standings sorted by wins
	vec[5]->setWins(2);

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)											//test output for standings 
	{
		cout << vec[i]->getName() << "Wins: " << vec[i]->getWins() << "Losses: " << vec[i]->getLosses() << endl;
	}

	if (player->getWins() + player->getLosses() == 18)												//if player has played full # of games in season
	{
		
		if (vec[0]->getName() == player->getName() || vec[1]->getName() == player->getName())				//if player is top 2, promote
		{
			player->promote();
			if (player->getLeague() > 5)
			{
				//message for winning game
			}
		}
		else if (vec[8]->getName() == player->getName() || vec[9]->getName() == player->getName())			//if player is bottom 2, demote
		{
			player->demote();
			if (player->getLeague() < 5)
			{
				//message to say can't demote any further
			}
		}
		else
		{
			//no promotion or demotion, continue to next season in same league 
		}
	}


	vec.clear();												//at season's end, or at promotion/demotion, clear gladiator array 
																//set new stats after
	cout << "check" << player->getName() << endl;				//test to ensure player does not get erased

	return 0;
}