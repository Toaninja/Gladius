 /* File: Save_and_Load.h
 * Author: Eric Fischer
 * Date: 
 * Description: This file will hold Save_and_Load.cpp function definitions, include statements, and any potential global variables
 */

#include <stdlib.h> 
#include <vector>
#include <stdio.h> 
#include <string.h> 

/*DEPRECATED: This part of the code has been deprecated due to the inability to dynamically 
			  display file names ending with a given file extension via the "filesystem" header
	#include <Windows.h> // works to find the file date using GetFileTime() on windows machines */

#define SAVE_NAME_LENGTH 18

bool manualSave(vector <Gladiator*> array, League general);
bool manualLoad();
 
// bool autoSave(vector <Gladiator*> array, League general);