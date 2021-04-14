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
bool manualSave(vector <Gladiator*> array, League general){
	FILE* fp;
	char filename[5][SAVE_NAME_LENGTH] = { "manual_save_1.dat", "manual_save_2.dat", "manual_save_3.dat", "manual_save_4.dat", "manual_save_5.dat" };
	int returnValue = 0, numOfGladiators = 10, menuChoice;
	 
	printf("Enter the number of the save slot to save to\n");
	printf("Slot 1\n");
	printf("Slot 2\n");
	printf("Slot 3\n");
	printf("Slot 4\n");
	printf("Slot 5\n");

	printf("Enter your choice: ");
	scanf("%d", &menuChoice);
	menuChoice--;

	if (menuChoice > 4 || menuChoice < 0) {
		printf("Error: No such save slot %d", menuChoice);
	}
	
	
	if((fp = fopen(filename[menuChoice], "w")) != NULL){ //open file with input name
		// Before all gladiators are saved, save the league info (tier and modifier) at the start of the file.
		// Saved on the first line
		fprintf(fp, "%d %d\n", getLeagueTier(), getModifier()); // League -> int tier, int modifier
		
		for (int i = 0; i < numOfGladiators; i++) { //will print to the named file one line at a time until it has printed a line for every gladiator/etc
			// saving a single gladiator each loop, incrementing which one with int i
			//string name ints: hp, attack, strength, defence floats: league, wins, losses, focus, matchmarker
			fprintf(fp, "%s %f %f %f %f %d %d %d %d %d\n", vec[i]->getName(), vec[i]->getHP(), vec[i]->getAttack(), vec[i]->getStrength(), vec[i]->getDefence(), vec[i]->getLeague(), vec[i]->getWins(), vec[i]->getLosses(), vec[i]->getFocus(), vec[i]->getMatchMarker()); 
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
		return returnValue; // if fp == NULL -> return 0 for false / unsuccessful save
	}
	 
	fclose(fp); //close file
	returnValue; // bitwise value change from 0 to 1
	return returnValue; // return 1 for true / successful save
}
 
 
//This function will load the game from asave slot indicated by the user
//It has no inputs, but sets the Gladiator array as well as the league- 
//information with the data stored in the .dat file
bool manualLoad() {
	FILE* fp;
	char filename[5][SAVE_NAME_LENGTH] = {"manual_save_1.dat", "manual_save_2.dat", "manual_save_3.dat", "manual_save_4.dat", "manual_save_5.dat"};
	int returnValue = 0, menuChoice, i = 0;
	int lTier, lMod, gLeague, gWins, gLosses, gFocus, gMatchmarker;
	char loadName[MAX_GLAD_NAME_LENGTH];
	string name;
	float hp, attack, strength, defence;
	

	printf("Enter the number of the save slot to load\n");
	printf("Slot 1\n");
	printf("Slot 2\n");
	printf("Slot 3\n");
	printf("Slot 4\n");
	printf("Slot 5\n");

	printf("Enter your choice: ");
	scanf("%d", &menuChoice);
	menuChoice--;

	if (menuChoice > 4 || menuChoice < 0) {
		printf("Error: No such save slot %d", menuChoice);
	}
	
	if((fp = fopen(filename[menuChoice], "r+")) != NULL){ //open file that user selected
		//Loading first line, the league info
		fscanf(fp, "%d %d", &lTier, &lMod); // League -> int tier, int modifier

		setLeagueTier(lTier);
		setLeagueModifier(lMod);

		//after loading the league info, load the gladiator info. One gladiator per line.
		//string name floats: hp, attack, strength, defence ints: league, wins, losses, focus, matchmarker
		while (fscanf(fp, "%s %f %f %f %f %d %d %d %d %d", loadName, hp, attack, strength, defence, &gLeague, &gWins, &gLosses, &gFocus, &gMatchmarker) != EOF) { //While the end of file has not been reached, read the following info in the given format
			//store the data
			name = loadName;
			vec[i]->setName(name); 
			vec[i]->setHP(hp); 
			vec[i]->setAttack(attack); 
			vec[i]->setStrength(strength); 
			vec[i]->setDefence(defence); 
			vec[i]->setLeague(gLeague); 
			vec[i]->setWins(gWins); 
			vec[i]->setLosses(gLosses); 
			vec[i]->setFocus(gFocus); 
			vec[i]->setMatchMarker(gMatchmarker);

			i++;
		}


		/*SAMPLE LOAD		 
		while (fscanf(fp, "%d %d %s %s", &storeID, &storeBool, FlightList[flightID].Plane[i].firstName, FlightList[flightID].Plane[i].lastName) != EOF) {
			FlightList[flightID].Plane[i].seatID = storeID;
			FlightList[flightID].Plane[i].seatAssign = storeBool;

			i++;
		}
		*/
	} else {
		return returnValue; // if fp == NULL -> return 0 for false / unsuccessful load
	}
	 
	fclose(fp);//close file
	returnValue; // bitwise value change
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