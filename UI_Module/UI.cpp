#include"UI.h"


///////////////////////PSEUDO CODE///////////////

void trainingFocus(){cout << UNDERLINE << "\t\tSelect the training focus of the day" << CLOSEUNDERLINE << endl;}
void ViewStandings(){cout << UNDERLINE << "\t\tViewing the standings of the players" << CLOSEUNDERLINE << endl;}
void LoadGame() {cout << UNDERLINE << "\t\tLoad Game" << CLOSEUNDERLINE << endl;}



void DisplayTraining(){ system("cls"); trainingFocus(); }
void DisplayLeague(){ system("cls"); ViewStandings();}
void DisplayLoad() {system("cls"); LoadGame();}

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
        DisplayTraining();
        break;

    case 2:
        DisplayLeague();
        break;

    case 3:
        DisplayLoad();
        break;
        
    case 4:
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
    cout << endl << "|\t\t\t 1. Training focus \t\t\t|";
    cout << endl << "|\t\t\t 2. View Standings \t\t\t|";
    cout << endl << "|\t\t\t 3. Load Game \t\t\t\t|";
    cout << endl << "|\t\t\t 4. Exit \t\t\t\t|";
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