#include <vector>

#include"UI.h"
#include "Gladiator.h"
#include "engine.h"
#include "Save_and_Load.h"
#include "League.h"



///////////////////////PSEUDO CODE///////////////

void LoadGame() {cout << UNDERLINE << "\t\tLoad Game" << CLOSEUNDERLINE << endl;}
void NewGame() { cout << UNDERLINE << "\t\tNew Game" << CLOSEUNDERLINE << endl; }

void DisplayLoad() {system("cls"); LoadGame();}
void DisplyNewGame() { system("cls"); NewGame(); }

////////////////////////////////////////////////

void trainingFocus_UI(Gladiator* player)
{
    char focusInput;
    cout << "\t\tEnter your choice: ";
    cin >> focusInput;
    cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    switch (focusInput)
    {
    case '1': player->setFocus(1); break;
    case '2': player->setFocus(2); break;
    case '3': player->setFocus(3); break;

    default:
        cout << endl << "Please select a valid option" << endl;
        displayTraining_UI(player);
    }
}

void displayTraining_UI(Gladiator* player)
{
    cout << "\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TRAINING FOCUS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\tPlease select one of the training focus listed below:" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\t1. Attack" << endl;
    cout << "\t\t2. Strength" << endl;
    cout << "\t\t3. Defence" << endl << endl;
    trainingFocus_UI(player);
}

void DisplayStandings_UI(vector <Gladiator*> vec)
{
    cout << "\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW STANDINGS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\t\tGladiator Name\t\t\tWins\t\tLosses" << endl;
    cout << "\t\t======================================================================" << endl;

    for (int i = 0; i < vec.size(); i++)											//test output for standings 
    {
        cout << "\t\t\t" << vec[i]->getName() << "\t\t\t" << vec[i]->getWins() << "\t\t" << vec[i]->getLosses() << endl << endl;
    }

    cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
}

void newgame_UI(Gladiator* player, vector<Gladiator*>&vec, League general)
{
    string name;
    int focusInput;
    cout << "Plase select your Gladiator's name:";
    cin >> name;
    cout << "\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TRAINING FOCUS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\tPlease select one of the training focus listed below:" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\t1. Attack" << endl;
    cout << "\t\t2. Strength" << endl;
    cout << "\t\t3. Defence" << endl << endl;
    cout << "\t\tEnter your choice: ";
    cin >> focusInput;

    //getname
    //focusinput
    generatePlayer(player, name, focusInput);

    for (int i = 0; i < 9; i++)
    {
        vec.push_back(generateGladiator(i, general));								//assign each gladiator to growing index until 
    }
    vec.push_back(player);															//add player to gladiator array

}

// Function to take user choices and perform
// the appropriate operation
//void titlePageInput(Gladiator* player, vector<Gladiator*>vec, League general, bool menuState)
//{
//    int choice;
//    cout << endl << "Enter your choice : ";
//    scanf_s("%d", &choice);
//
//    switch (choice) 
//    {
//    case 1:
//        newgame_UI(player, vec, general);
//        break;
//
//
//    /*case 2:
//        DisplayTraining_UI(player);
//        break;
//
//    case 3:
//        DisplayStandings_UI();
//        break;*/
//
//    case 2:
//        DisplayLoad();
//        break;
//        
//    case 3:
//        cout << endl << "Exiting... " << endl << endl;
//        cout << "Exiting in 3 seconds..." << endl;
//        Sleep(3000);
//        exit(1);
//
//    default:
//        cout << endl << "The choice you entered was invalid. Please try again :) " << endl;
//        titlePage(menuState);
//    }
//}

// Function to print all the menus
bool titlePage(Gladiator* player, vector<Gladiator*> &vec, League general, bool menuState)
{
    // Set output color to blue
    // background and white foreground
    system("color 5F");
    cout << endl;

    // Create Menu
    cout << "\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2"
        << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
        << "\xB2\xB2\xB2\xB2\xB2 GLADIUS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
        << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
        << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
        << "\xB2\xB2 \xB2";
    cout << endl << " ______________________________"
        << "_________________________________";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t 1. New Game \t\t\t\t|";
   // cout << endl << "|\t\t\t 2. Training focus \t\t\t|";
   // cout << endl << "|\t\t\t 3. View Standings \t\t\t|";
    cout << endl << "|\t\t\t 2. Load Game \t\t\t\t|";
    cout << endl << "|\t\t\t 3. Exit \t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "\xB2_________________________________"
         << "______________________________\xB2" << endl;

    menuState = true;

    int choice;
    cout << endl << "Enter your choice : ";
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        newgame_UI(player, vec, general);
        break;


        /*case 2:
            DisplayTraining_UI(player);
            break;

        case 3:
            DisplayStandings_UI();
            break;*/

    case 2:
        DisplayLoad();
        break;

    case 3:
        cout << endl << "Exiting... " << endl << endl;
        cout << "Exiting in 3 seconds..." << endl;
        Sleep(3000);
        exit(1);

    default:
        cout << endl << "The choice you entered was invalid. Please try again :) " << endl;
        titlePage(player, vec, general, menuState);
    }

    return menuState;
}


// Driver Code
//int main()
//{
//    // Function Call
//    titlePage();
//    return 0;
//}

//choose focus
//fight
//save

bool gameMenu(vector <Gladiator*> &vec, Gladiator *player, League general, bool menuState)
{
    int input;

    cout << "1. Fight" << endl;

    cout << "2. Choose training focus" << endl;
    cout << "3. View standings" << endl;
    cout << "4. Save" << endl;
    cout << "5. Load" << endl;
    cout << "6. Exit to title screen" << endl;
    cout << "7. Exit to desktop" << endl;
    cout << "Please select an option from 1-7: ";

    cin >> input;


    switch (input)
    {

    case 1:                         //fight for that day
        engine(vec);
        sort(vec.begin(), vec.end(), cmp);
        break;

       
    case 2:                         //change training focus for that day
        trainingFocus_UI(player);
        break;

    case 3:                         //view standings
        DisplayStandings_UI(vec);
        break;

    case 4:
        manualSave(vec, general);   //save
        break;

    case 5:
        manualLoad(vec, general);   //load
        break;

    case 6:                         //exit to title screen
        menuState = false;
        vec.clear();
        player->setWins(0);
        player->setLoss(0);
        return menuState;
        

    case 7:
        cout << endl << "Exiting... " << endl << endl;
        cout << "Exiting in 3 seconds..." << endl;
        Sleep(3000);
        exit(1);

    default:
        cout << "Invalid input" << endl;
        gameMenu(vec, player, general, menuState);

    }

    return menuState;
}