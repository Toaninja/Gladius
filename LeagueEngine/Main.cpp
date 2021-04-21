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

#include "engine.h"
#include "Gladiator.h"
#include "League.h"
#include "Save_and_Load.h"
#include "UI.h"

using namespace std;

#define LEAGUE_SIZE //atoi(argv[1])				//10 gladiators per league always
#define CREATE_FOCUS 1.5						//initial multiplier for when player creates their gladiator



int main(int argc, char* argv[])
{
	srand(time(NULL));

	int numOfGames = atoi(argv[1]);				//games in a season = 18


	League league1(1, 1);															//create 5 league objects
	League league2(2, 2);
	League league3(3, 3);
	League league4(4, 4);
	League league5(5, 5);
	
	League leagueArray[5] = { league1, league2, league3, league4, league5 };

	League general = leagueArray[0];														//general league object or current one running

	Gladiator* player = new Gladiator;												//create player gladiator object
	vector <Gladiator*> vec;	
													//create vector array of random gladiators
	bool gameState = true;
	bool menuState = true;


	
	//string name = "testname";														//testing name and initial focus input
	//int focusInput = 1; 

	//generatePlayer(player, name, focusInput);
	//cout << player->getAttack() << endl;
	while (gameState)
	{
		menuState = titlePage(player, vec, &general, menuState);
		for (int j = 0; j < 10; j++)
		{
			if (vec[j]->getFocus() > 0)
			{
				player = vec[j];
			}
		}

		while (menuState)
		{
			//checking if player has played full 18 games, promote, demote or stay in current league
			if ((player->getWins() + player->getLosses()) == numOfGames)												//if player has played full # of games in season
			{

				cout << endl << "\t\tLEAGUE CHANGES" << endl;
				cout << "\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl;

				if (vec[0]->getName() == player->getName() || vec[1]->getName() == player->getName())				//if player is top 2, promote
				{
					//player->promote();
					general = leagueArray[general.getLeagueTier()];
					

					if (general.getLeagueTier() > 5)
					{
						cout << "Congratulation! You made it to the top!" << endl;
						cout << "What now..." << endl;
						exit(1);
					}
					else {
						cout << "You have promoted to the next league. Well done!" << endl; 
					}
				}
				else if (vec[8]->getName() == player->getName() || vec[9]->getName() == player->getName())			//if player is bottom 2, demote
				{
					
					if (general.getLeagueTier() == 1)
					{
						cout << "Cannot demote any further..." << endl; 
					}
					else {
						general = leagueArray[general.getLeagueTier() - 2];
						cout << "You have demoted to a previous league..." << endl;
					}
				}
				else
				{
					cout << "The league begins anew..." << endl;;
				}

				player->setWins(0);
				player->setLoss(0);

				vec.clear();

				//promote
				for (int i = 0; i < 9; i++)
				{
					vec.push_back(generateGladiator(i, &general));								//assign each gladiator to growing index until 
				}
				vec.push_back(player);
			}


			menuState = gameMenu(vec, player, &general, menuState);


			
														//at season's end, or at promotion/demotion, clear gladiator array 
																		//set new stats after
		}
	}

	
																			//index 8 (9 gladiators)

	//cout << vec[1]->getName() << endl;												//testing if random gladiators were produced and members populated
	//cout << vec[1]->getAttack() << endl;

	//vec.push_back(player);															//add player to gladiator array
	//cout << vec[9]->getName() << endl;


	//pass vector array of gladiators and player to match engine, get results

	/*vec[9]->setFocus(1);

	cout << vec[9]->getAttack() << endl;

	engine(vec);

	cout << vec[9]->getAttack() << endl;*/


	

	//sort(vec.begin(), vec.end(), cmp);

	//for (int i = 0; i < vec.size(); i++)											//test output for standings 
	//{
	//	cout << vec[i]->getName() << " Wins: " << vec[i]->getWins() << " Losses: " << vec[i]->getLosses() << endl;
	//}

	//cout << "check" << player->getName() << endl;				//test to ensure player does not get erased

	return 0;
}