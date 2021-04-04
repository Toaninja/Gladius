 /* File: Save_and_Load.h
 * Author: Eric Fischer
 * Date: 
 * Description: This file will hold Save_and_Load.cpp function definitions, include statements, and any potential global variables
 */
 
 #include <stdlib.h> 
 #include <vector>
 #include <stdio.h> 
 #include <string.h> 
 #include <Windows.h> // works to find the file date using GetFileTime() on windows machines 
 
 bool manualSave(vector <Gladiator*> array, League general);
 bool manualLoad();
 
 // bool autoSave(vector <Gladiator*> array, League general);