#include <iostream>

#include "constants.h"

using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The global function that prints out five main 
color options for users.
*/

//print out color options for users with different promopt for
//each different menu option

int printColorMenu(const string& prompt)
{
    int colorMenuChoice;
    

    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    cout << prompt;

    bool validColorMenuChoice = false;

    while (!validColorMenuChoice)
    {
        cin >> colorMenuChoice;
        cout << endl;
        if (cin.fail() || (colorMenuChoice != RED && colorMenuChoice
            != GREEN && colorMenuChoice != BLUE && colorMenuChoice != BLACK &&
            colorMenuChoice != WHITE))
        {
            cin.clear();
            cin.ignore(CIN_IGNORE, '\n');
            cout << 
            "Error: The menu choice must be an integer from 1 to 5! " 
            << endl;
            cout << endl;
            cout << "1. Red" << endl;
            cout << "2. Green" << endl;
            cout << "3. Blue" << endl;
            cout << "4. Black" << endl;
            cout << "5. White" << endl;
            cout << prompt;
        }
        else
        {
            validColorMenuChoice = true;
        }
    }
    return colorMenuChoice; 
}
