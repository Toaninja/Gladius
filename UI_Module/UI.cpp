#include"UI.h"


///////////////////////PSEUDO CODE///////////////

void trainingFocus(){cout << UNDERLINE << "\t\tSelect the training focus of the day" << CLOSEUNDERLINE << endl;}
void ViewStandings(){cout << UNDERLINE << "\t\tViewing the standings of the players" << CLOSEUNDERLINE << endl;}
void LoadGame() {cout << UNDERLINE << "\t\tLoad Game" << CLOSEUNDERLINE << endl;}
void NewGame() { cout << UNDERLINE << "\t\tNew Game" << CLOSEUNDERLINE << endl; }


void DisplayTraining(){ system("cls"); trainingFocus(); }
void DisplayLeague(){ system("cls"); ViewStandings();}
void DisplayLoad() {system("cls"); LoadGame();}
void DisplyNewGame() { system("cls"); NewGame(); }

////////////////////////////////////////////////


// Function to take user choices and perform
// the appropriate operation
void selectMenu()
{
    int choice;
    cout << endl << "Enter your choice : ";
    scanf("%d", &choice);

    switch (choice) 
    {
    case 1:
        DisplyNewGame();
        break;


    case 2:
        DisplayTraining();
        break;

    case 3:
        DisplayLeague();
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