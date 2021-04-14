 /* File: Save_and_Load.h
 * Author: Eric Fischer
 * Date: 
 * Description: This file will hold Save_and_Load.cpp function definitions, include statements, and any potential global variables
 */
#pragma warning(disable:4996)

#include <stdlib.h> 
#include <vector>
#include <stdio.h> 
#include <string.h> 


//includes for league engine stuff?
//#include gladiator.h
//#include league.h

/*DEPRECATED: This part of the code has been deprecated due to the inability to dynamically 
			  display file names ending with a given file extension via the "filesystem" header
			  this file would likely be required for the autoSave functionality to work properly.
	#include <Windows.h> // works to find the file date using GetFileTime() on windows machines */

#define SAVE_NAME_LENGTH 18

bool manualSave(vector <Gladiator*> array, League general);
bool manualLoad();
 
// bool autoSave(vector <Gladiator*> array, League general);