#ifndef UI
#define UI

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Gladiator.h"


#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

bool titlePage(Gladiator* player, vector<Gladiator*> &vec, League *general, bool menuState);
void trainingFocus_UI(Gladiator* player);
void displayTraining_UI(Gladiator* player);
void DisplayStandings_UI(vector <Gladiator*> vec, League *general);
void DisplayPlayer_UI(vector <Gladiator*> vec);
void newgame_UI(Gladiator* player, vector <Gladiator*> &vec, League *general);
bool gameMenu(vector <Gladiator*> &vec, Gladiator* player, League *general, bool menuState);


#endif // !UI

