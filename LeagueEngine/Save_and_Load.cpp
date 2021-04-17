/* File: Save_and_Load.cpp
 * Author: Eric Fischer
 * Date: 
 * Description: Holds function definitions for the Save_and_Load module
 */
 
#include "Save_and_Load.h"
#include "Gladiator.h"
#include "League.h"
 
using namespace std;

//This function will save the game to a save slot indicated by the user
//It takes the Gladiator array, as well as the league information and stores them-
//in a .dat file
bool manualSave(vector <Gladiator*> vec, League general){
	FILE* fp;
	char filename[5][SAVE_NAME_LENGTH] = { "manual_save_1.dat", "manual_save_2.dat", "manual_save_3.dat", "manual_save_4.dat", "manual_save_5.dat" };
	char name[MAX_GLAD_NAME_LENGTH] = "";
	int numOfGladiators = 10, menuChoice;
	unsigned char returnValue = 0x1;
	string tempName;
	 
	cout << "Enter the number of the save slot to save to" << endl;
	cout << "Slot 1" << endl;
	cout << "Slot 2" << endl;
	cout << "Slot 3" << endl;
	cout << "Slot 4" << endl;
	cout << "Slot 5" << endl;

	cout << "Enter your choice: " << endl;
	cin >> menuChoice;
	menuChoice--;

	if (menuChoice > 4 || menuChoice < 0) {
		printf("Error: No such save slot %d", menuChoice);
	}
	
	
	if((fp = fopen(filename[menuChoice], "w")) != NULL){ //open file with input name
		// Before all gladiators are saved, save the league info (tier and modifier) at the start of the file.
		// Saved on the first line
		fprintf(fp, "%d %d\n", general.getLeagueTier(), general.getModifier()); // League -> int tier, int modifier
		
		for (int i = 0; i < numOfGladiators; i++) { //will print to the named file one line at a time until it has printed a line for every gladiator/etc
			// saving a single gladiator each loop, incrementing which one with int i
			//string name ints: hp, attack, strength, defence floats: league, wins, losses, focus, matchmarker
			tempName = vec[i]->getName();
			for (int j = 0; j < (tempName.length()); j++) {
				name[j] = tempName[j];
			}
			fprintf(fp, "%s %f %f %f %f %d %d %d %d %d\n", name, vec[i]->getHP(), vec[i]->getAttack(), vec[i]->getStrength(), vec[i]->getDefence(), vec[i]->getLeague(), vec[i]->getWins(), vec[i]->getLosses(), vec[i]->getFocus(), vec[i]->getMatchMarker()); 
			tempName = "";
		}
		

		/* SAMPLE SAVE
		// SAVE FUNCTION //.seatID .seatAssign .firstname .lastname
				if ((freopen(flightData, "w", fp)) != NULL) {
					for (int j = 0; j < PLANE_SIZE; j++) {
						fprintf(fp, "%d %d %s %s\n", List[flightID].Plane[j].seatID, List[flightID].Plane[j].seatAssign, List[flightID].Plane[j].firstName, List[flightID].Plane[j].lastName);
					}
				}
		*/
	} else {
		returnValue >>= 1; // bitwise value change from 1 to 0
		return returnValue; // if fp == NULL -> return 0 for false / unsuccessful save
	}
	 
	fclose(fp); //close file
	return returnValue; // return 1 for true / successful save
}
 
 
//This function will load the game from asave slot indicated by the user
//It has no inputs, but sets the Gladiator array as well as the league- 
//information with the data stored in the .dat file
bool manualLoad(vector <Gladiator*> vec, League general) {
	ifstream fin;
	string filename[5] = {"manual_save_1.dat", "manual_save_2.dat", "manual_save_3.dat", "manual_save_4.dat", "manual_save_5.dat"}, name;
	unsigned char returnValue = 0x1;
	int lTier, lMod, gLeague, gWins, gLosses, gFocus, gMatchmarker, numOfGladiators = 10, menuChoice;
	float hp, attack, strength, defence;
	

	cout << "Enter the number of the save slot to load" << endl;
	cout << "Slot 1" << endl;
	cout << "Slot 2" << endl;
	cout << "Slot 3" << endl;
	cout << "Slot 4" << endl;
	cout << "Slot 5" << endl;

	cout << "Enter your choice: " << endl;
	cin >> menuChoice;
	menuChoice--;

	if (menuChoice > 4 || menuChoice < 0) {
		printf("Error: No such save slot %d", menuChoice);
	}
	
	fin.open(filename[menuChoice]);
	if (fin.is_open()) {
		//Loading first line, the league info
		fin >> lTier >> lMod; // League -> int tier, int modifier
		
		League* general = new League;
		general->setLeagueTier(lTier);
		general->setModifier(lMod);
		
		//after loading the league info, load the gladiator info. One gladiator per line.
		//string: name 
		//floats: hp, attack, strength, defence 
		//ints: league, wins, losses, focus, matchmarker
		for (int i = 0; i < numOfGladiators; i++) {
			fin >> name >> hp >> attack >> strength >> defence >> gLeague >> gWins >> gLosses >> gFocus >> gMatchmarker;

			//store the data
			vec[i]->setName(name);
			vec[i]->setHP(hp);
			vec[i]->setAttack(attack);
			vec[i]->setStrength(strength);
			vec[i]->setDefence(defence);
			//vec[i]->setLeague(gLeague); 
			vec[i]->setWins(gWins);
			vec[i]->setLoss(gLosses);
			vec[i]->setFocus(gFocus);
			for (int j = 0; j < gMatchmarker; j++) {
				vec[i]->setMatchMarker();
			}
		}
	} else {
		//unable to open file
		returnValue >>= 1; // bitwise value change from 1 to 0
		return returnValue; // if fp == NULL -> return 0 for false / unsuccessful load
	}
	 
	fin.close(); //close file
	return returnValue; // if the file loaded properly return 1 for true
}
 
/* 
bool autoSave(vector <Gladiator*> array, League general){
	FILE* fp;
	char* input, filename;
	 
	// find the number of the most recent auto_save_#.dat file
	// if it's number is 1, check to see if the next character is 0
	// if the next char is not 0, then increment the number by 1
	// if the next char is 0, then loop back to 1
	
	if(fp = fopen(filename, "w") != NULL){ //open file with filename
		//write data to file fprintf()
		// Data to write:
			//All gladiators in the Gladiator array
	} else {
		return 0; // if fp == NULL -> return 0 for false / unsuccessful save
	}
	 
	fclose(fp); //close file
	return 1; // return 1 for true / successful save
}
*/