#include"UI.h"


///////////////////////PSEUDO CODE///////////////

void LoadGame() {cout << UNDERLINE << "\t\tLoad Game" << CLOSEUNDERLINE << endl;}
void NewGame() { cout << UNDERLINE << "\t\tNew Game" << CLOSEUNDERLINE << endl; }

void DisplayLoad() {system("cls"); LoadGame();}
void DisplyNewGame() { system("cls"); NewGame(); }

////////////////////////////////////////////////

void trainingFocus(Gladiator* player)
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
        displayTraining(player);
    }
}

void displayTraining(Gladiator* player)
{
    cout << "\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TRAINING FOCUS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\tPlease select one of the training focus listed below:" << endl;
    cout << "\t\t======================================================================" << endl;
    cout << "\t\t1. Attack" << endl;
    cout << "\t\t2. Strength" << endl;
    cout << "\t\t3. Defence" << endl << endl;
    trainingFocus(player);

}

void DisplayStandings(vector <Gladiator*> vec)
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

// Function to take user choices and perform
// the appropriate operation
void selectMenu()
{
    int choice;
    cout << endl << "Enter your choice : ";
    scanf_s("%d", &choice);

    switch (choice) 
    {
    case 1:
        DisplyNewGame();
        break;


    case 2:
        DisplayTraining(player);
        break;

    case 3:
        DisplayStandings();
        break;

    case 4:
        DisplayLoad();
        break;
        
    case 5:
        cout << endl << "Exiting... " << endl << endl;
        cout << "Exiting in 3 seconds..." << endl;
        Sleep(3000);
        exit(1);

    default:
        cout << endl << "The choice you entered was invalid. Please try again :) " << endl;
        printMenu();
    }
}

void newgame()
{
    Gladiator* player = new gladiator;
    //getname
    //focusinput
    generatePlayer(player, name, focusinput);

}
// Function to print all the menus
void printMenu()
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
    cout << endl << "|\t\t\t 2. Training focus \t\t\t|";
    cout << endl << "|\t\t\t 3. View Standings \t\t\t|";
    cout << endl << "|\t\t\t 4. Load Game \t\t\t\t|";
    cout << endl << "|\t\t\t 5. Exit \t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "|\t\t\t\t\t\t\t\t|";
    cout << endl << "\xB2_________________________________"
         << "______________________________\xB2" << endl;

    // Function call for select options
    selectMenu();
}


// Driver Code
int main()
{
    // Function Call
    printMenu();
    return 0;
}