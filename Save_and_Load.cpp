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
	 
	 strcpy(filename, input);
	 strcat(filename, ".dat");
	
	 if(fp = fopen(filename, "w") != NULL){ //open file with input name
		//write data to file
	 } else {
		return 0; // if fp == NULL -> return 0 for false / unsuccessful save
	 }
	 
	 //close file
	 return 1; // return 1 for true / successful save
 }
 
 /* <Placeholder text-will add documentation used in previously submitted docs>
 */
 bool manualLoad(){
	 FILE* fp;
	 
	 printf("Choose which file to load: ");
	 //call load menu display function(?)
	 //file selection
	 
	 
	 //open file that user selected
	 //file loading (setting variable values)
	 //close file
	 
	 // if the file loaded properly return 1 for true
	 // else return 0 for false
 }
 
 /* <Time & resource permitting this function will be developed>
 bool autoSave(){
 
 }
 */