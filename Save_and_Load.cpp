/* File: Save_and_Load.cpp
 * Author: Eric Fischer
 * Date: 
 * Description: Holds function definitions for the Save_and_Load module
 */
 
#include "Save_and_Load.h"
 
using namespace std;
 

//This function will save the game to a save slot indicated by the user
//It takes the Gladiator array, as well as the league information and stores them-
//in a .dat file
bool manualSave(vector <Gladiator*> array, League general){
	FILE* fp;
	char filename[SAVE_NAME_LENGTH];
	int returnValue = 0, numOfGladiators = 10, menuChoice;
	 
	printf("Enter the number of the save slot to load\n");
	printf("Slot 1\n");
	printf("Slot 2\n");
	printf("Slot 3\n");
	printf("Slot 4\n");
	printf("Slot 5\n");

	printf("Enter your choice: ");
	scanf("%d", &menuChoice);

	switch (menuChoice)
	{
	case 1:
		strcpy(filename, "manual_save_1.dat");
	case 2:
		strcpy(filename, "manual_save_2.dat");
	case 3:
		strcpy(filename, "manual_save_3.dat");
	case 4:
		strcpy(filename, "manual_save_4.dat");
	case 5:
		strcpy(filename, "manual_save_5.dat");
	default:
		printf("Error: no such save slot %d", menuChoice);
	}
	
	
	if(fp = fopen(filename, "w") != NULL){ //open file with input name
		for (int i = 0; i < numOfGladiators; i++) { //will print to the named file one line at a time until it has printed a line for every gladiator/etc
			fprintf(fp, ); // saving a single gladiator each loop, incrementing which one with int i
		}
		// after all gladiators are saved, save the league info (tier and number) at the end of the file on an eleventh line
		fprintf(fp, ); //saving the league info on the last line of the file


		/* SAMPLE SAVE
		// SAVE FUNCTION //.seatID .seatAssign .firstname .lastname
				if ((freopen(flightData, "w", fp)) != NULL) {
					for (int j = 0; j < PLANE_SIZE; j++) {
						fprintf(fp, "%d %d %s %s\n", List[flightID].Plane[j].seatID, List[flightID].Plane[j].seatAssign, List[flightID].Plane[j].firstName, List[flightID].Plane[j].lastName);
					}
				}
		*/

		//write data to file fprintf()
		// Data to write:
		// All gladiators in the Gladiator array
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
	char filename[SAVE_NAME_LENGTH];
	int returnValue = 0, menuChoice;

	printf("Enter the number of the save slot to load\n");
	printf("Slot 1\n");
	printf("Slot 2\n");
	printf("Slot 3\n");
	printf("Slot 4\n");
	printf("Slot 5\n");

	printf("Enter your choice: ");
	scanf("%d", &menuChoice);

	switch (menuChoice)
	{
	case 1:
		strcpy(filename, "manual_save_1.dat");
	case 2:
		strcpy(filename, "manual_save_2.dat");
	case 3:
		strcpy(filename, "manual_save_3.dat");
	case 4:
		strcpy(filename, "manual_save_4.dat");
	case 5:
		strcpy(filename, "manual_save_5.dat");
	default:
		printf("Error: no such save slot %d", menuChoice);
	}
	
	if(fp = fopen(filename, "r+") != NULL){ //open file that user selected
		/*SAMPLE LOAD		 
		while (fscanf(fp, "%d %d %s %s", &storeID, &storeBool, FlightList[flightID].Plane[i].firstName, FlightList[flightID].Plane[i].lastName) != EOF) {
			FlightList[flightID].Plane[i].seatID = storeID;
			FlightList[flightID].Plane[i].seatAssign = storeBool;

			i++;
		}
		*/

		//fscanf();

		//file loading (setting variable values) fscanf()
		// Data to load: 
		// All gladiators in the Gladiator array
	} else {
		return returnValue; // if fp == NULL -> return 0 for false / unsuccessful load
	}
	 
	fclose(fp);//close file
	returnValue; // bitwise value change
	return returnValue; // if the file loaded properly return 1 for true
}
 
/* <Time & resource permitting this function will be developed>
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