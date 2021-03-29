/* File: Save_and_Load.cpp
 * Author: Eric Fischer
 * Date: 
 * Description: Holds function definitions for the Save_and_Load module
 */
 
 #include "Save_and_Load.h"
 
 using namespace std;
 
 /* <Placeholder text-will add documentation used in previously submitted docs>
 */
 bool manualSave(Gladiator array, Match *matches, string array[][]){
	 FILE* fp;
	 char* input, filename;
	 
	 printf("Name your save file: ");
	 fgets(input, 12, stdin); //get input for file name
	 
	 strcpy(filename, input); // this may include a null return character, may need to remove the last character on this string 
	 strcat(filename, ".dat");
	
	 if(fp = fopen(filename, "w") != NULL){ //open file with input name
		//write data to file fprintf()
		// Data to write:
		/*
		All gladiators in the Gladiator array
		struct of matches
		winLoss array
		*/
	 } else {
		return 0; // if fp == NULL -> return 0 for false / unsuccessful save
	 }
	 
	 fclose(fp); //close file
	 return 1; // return 1 for true / successful save
 }
 
 /* <Placeholder text-will add documentation used in previously submitted docs>
 */
 bool manualLoad(){
	 FILE* fp;
	 char* filename;
	 
	 printf("Choose which file to load: ");
	 //call load menu display function(?)
	 //file selection - could do user input simply. Check UI functions
	 
	 if(fp = fopen(filename, "w") != NULL){ //open file that user selected
		//file loading (setting variable values) fscanf()
		// Data to load: 
		/*
		All gladiators in the Gladiator array
		struct of matches
		winLoss array
		*/
	 } else {
		return 0; // if fp == NULL -> return 0 for false / unsuccessful load
	 }
	 
	 fclose(fp);//close file
	 return 1; // if the file loaded properly return 1 for true
 }
 
 /* <Time & resource permitting this function will be developed>
 bool autoSave(){
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
			//struct of matches
			//winLoss array
	 } else {
		return 0; // if fp == NULL -> return 0 for false / unsuccessful save
	 }
	 
	 fclose(fp); //close file
	 return 1; // return 1 for true / successful save
 }
 */