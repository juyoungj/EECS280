#include <iostream>
#include "printMenu.h"
#include "constants.h"

using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: This function provides five main options for users to 
modify, insert, write images or exit the program while handling the error.
*/

int printMenu()
{
    int menuChoice;
    bool validMenuChoice;

    cout << "1. Annotate image with rectangle" << endl;
    cout << "2. Annotate image with pattern from file" << endl;
    cout << "3. Insert another image" << endl;
    cout << "4. Write out current image" << endl;
    cout << "5. Exit the program" << endl;

    cout << "Enter int for main menu choice: ";
  
    validMenuChoice = false;

    while (!validMenuChoice)
    {
        cin >> menuChoice;
        cout << endl;
        if (cin.fail() || (menuChoice != ANNOTATE_RECTANGLE && 
            menuChoice != ANNOTATE_PATTERN && 
            menuChoice != INSERT_IMAGE && 
            menuChoice != WRITE_IMAGE && 
            menuChoice != EXIT))
        {
            cin.clear();
            cin.ignore(CIN_IGNORE, '\n');
            cout << "Error: The menu choice must be an integer from 1 to 5! " 
            << endl;
            cout << endl;
            cout << "1. Annotate image with rectangle" << endl;
            cout << "2. Annotate image with pattern from file" << endl;
            cout << "3. Insert another image" << endl;
            cout << "4. Write out current image" << endl;
            cout << "5. Exit the program" << endl;
            cout << endl;
            cout << "Enter int for main menu choice: ";
        }
        else
        {
            validMenuChoice = true;
        }
    }

    return (menuChoice);
}

