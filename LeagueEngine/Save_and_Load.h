 /* File: Save_and_Load.h
 * Author: Eric Fischer
 * Date: 
 * Description: This file will hold Save_and_Load.cpp function definitions, include statements, and any potential global variables
 */
#pragma warning(disable:4996)


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#include <stdlib.h> 
//#include <stdio.h> 
//#include <string.h> 


#include "Gladiator.h"
#include "League.h"

/*DEPRECATED: This part of the code has been deprecated due to the inability to dynamically 
			  display file names ending with a given file extension via the "filesystem" header
			  this file would likely be required for the autoSave functionality to work properly.
	#include <Windows.h> // works to find the file date using GetFileTime() on windows machines */

#define SAVE_NAME_LENGTH 18
#define MAX_GLAD_NAME_LENGTH 16

bool manualSave(vector <Gladiator*> array, League general);
bool manualLoad(vector <Gladiator*> array, League general);
 
// bool autoSave(vector <Gladiator*> array, League general);