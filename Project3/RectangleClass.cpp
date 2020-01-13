#include <iostream>

#include "RectangleClass.h"
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "RowColumnClass.h"
#include "printColorMenu.h"
#include "constants.h"

using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: Initialize the rectangle with the information users select 
such as color, filled option, and location. Set the location of a 
rectangle with upper right corner and lower left corner.
*/

//provide users 3 method options to draw a rectangle with error handling
//let users to input information about corners, center, or number of rows
//and columns of a rectangle
bool RectangleClass::makeRectangle()
{
    cout << 
    "1. Specify upper left and lower right corners of rectangle" 
    << endl;
    cout << 
    "2. Specify upper left corner and dimensions of rectangle" 
    << endl;
    cout << 
    "3. Specify extent from center of rectangle" 
    << endl;
    cout << 
    "Enter int for rectangle specification method: ";

    //RESUBMISSION - Declare local variable if valid menu choice is 
    //selected
    bool validRectMenuChoice = false;
    //RESUBMISSION - Declare local variable specifying method.
    int rectSpecificationMethod;

    while (!validRectMenuChoice)
    {
        
        cin >> rectSpecificationMethod;
        cout << endl;
        if (cin.fail() || (rectSpecificationMethod != SPECIFY_BY_CORNERS && 
            rectSpecificationMethod != SPECIFY_BY_DIMENSIONS && 
            rectSpecificationMethod != SPECIFY_BY_CENTER))
        {
            cin.clear();
            cin.ignore(CIN_IGNORE, '\n');
            cout << 
            "Error: The menu choice must be an integer from 1 to 3! " 
            << endl;
            cout << endl;
            cout << 
            "1. Specify upper left and lower right corners of rectangle" 
            << endl;
            cout << 
            "2. Specify upper left corner and dimensions of rectangle" 
            << endl;
            cout << 
            "3. Specify extent from center of rectangle" 
            << endl;
            cout << 
            "Enter int for rectangle specification method: ";
        }
        else
        {
            validRectMenuChoice = true;
        }
    }
    //RESUBMISSION - Declare local variables to input the location
    // of rectangles
    int upperLeftRow;
    int upperLeftColumn;
    int lowerRightRow;
    int lowerRightColumn;
    int numberOfRows;
    int numberOfColumns;
    int centerRow;
    int centerColumn;
    int halfNumberOfRows;
    int halfNumberOfColumns;

    if (rectSpecificationMethod == SPECIFY_BY_CORNERS)
    {
        cout << "Enter upper left corner row and then column: ";
        cin >> upperLeftRow;
        cin >> upperLeftColumn;
        cout << "Enter lower right corner row and then column: ";
        cin >> lowerRightRow;
        cin >> lowerRightColumn;
        //RESUBMISSION -  SETTING ROWS AND COLUMNS INSIDE SPECIFYING 
        //THE LOCATION OF RECTANGLE BY ENTERING INFORMATION.
        upperLeft.setRowCol(upperLeftRow, upperLeftColumn);
        lowerRight.setRowCol(lowerRightRow, lowerRightColumn);
    }
    else if (rectSpecificationMethod == SPECIFY_BY_DIMENSIONS)
    {
        cout << "Enter upper left corner row and then column: ";
        cin >> upperLeftRow;
        cin >> upperLeftColumn;
        cout << "Enter int for number of rows: ";
        cin >> numberOfRows;
        cout << "Enter int for number of columns: ";
        cin >> numberOfColumns;
        //RESUBMISSION -  SETTING ROWS AND COLUMNS INSIDE SPECIFYING 
        //THE LOCATION OF RECTANGLE BY ENTERING INFORMATION.
        upperLeft.setRowCol(upperLeftRow, upperLeftColumn);
        lowerRight.setRowCol(
            upperLeftRow + numberOfRows -1,
            upperLeftColumn + numberOfColumns -1);                          
    }
    else if (rectSpecificationMethod == SPECIFY_BY_CENTER)
    {
        cout << "Enter rectangle center row and then column: ";
        cin >> centerRow;
        cin >> centerColumn;
        cout << "Enter int for half number of rows: ";
        cin >> halfNumberOfRows;
        cout << "Enter int for half number of columns: ";
        cin >> halfNumberOfColumns;
        //RESUBMISSION -  SETTING ROWS AND COLUMNS INSIDE SPECIFYING 
        //THE LOCATION OF RECTANGLE BY ENTERING INFORMATION.
        upperLeft.setRowCol(
            centerRow - halfNumberOfRows,
            centerColumn - halfNumberOfColumns);
        lowerRight.setRowCol(
            centerRow + halfNumberOfRows,
            centerColumn + halfNumberOfColumns);

    }
    return (true);
}


//provide users 5 different color options with error handling
bool RectangleClass::rectColors()
{
    rectColor = printColorMenu(COLOR_REC_PROMPT);

    return (true);
}

//provide users 2 options whether to fill a rectangle with error handling
bool RectangleClass::rectFill()
{
    cout << "1. No" << endl;
    cout << "2. Yes" << endl;
    
    cout << "Enter int for rectangle fill option: ";

    bool validRectFillChoice = false;

    while (!validRectFillChoice)
    {
        cin >> fillOption;
        cout << endl;
        if (cin.fail() || (fillOption != NO && 
            fillOption != YES))
        {
            cin.clear();
            cin.ignore(CIN_IGNORE, '\n');
            cout << "Error: The menu choice must be an integer from 1 to 2! "
            << endl;
            cout << endl;
            cout << "1. No" << endl;
            cout << "2. Yes" << endl;
            cout << "Enter int for rectangle fill option: ";
        }
        else
        {
            validRectFillChoice = true;
        }
    }

    return (true);
}

//RESUBMISSION - Unnecessary function

// bool RectangleClass::setColor(int rectColor)
// {
//     rectangleColor = rectColor;
//     return true;
// }

//returns color for a rectangle
int RectangleClass::getColor()
{
    return rectColor;
}

//RESUBMISSION - Unnecessary function
// //setting fill option for a rectangle
// bool RectangleClass::setFilled(int fillOption)
// {
//     filled = fillOption;
//     return true;
// }

//returns fill option for a rectangle
int RectangleClass::getFilled()
{
    return fillOption;
}

//RowColumnClass that returns the upper left corner
RowColumnClass RectangleClass::getUpperLeft()
{
    return upperLeft;
}

//RowColumnClass that returns the lower right corner
RowColumnClass RectangleClass::getLowerRight()
{
    return lowerRight;
}



//RESUBMISSION - Unnecessary functions since all are included and already set
//when reading inputs about rectangles

// bool RectangleClass::locatingRectangle()
// {
//     if (rectSpecificationMethod == SPECIFY_BY_CORNERS)
//     {
//         initializeByCorners(
//             upperLeftRow,
//             upperLeftColumn,
//             lowerRightRow,
//             lowerRightColumn,
//             rectColor,
//             fillOption);

//     }
//     else if (rectSpecificationMethod == SPECIFY_BY_DIMENSIONS)
//     {
//         initializeByDim(
//             upperLeftRow,
//             upperLeftColumn,
//             numberOfRows,
//             numberOfColumns,
//             rectColor,
//             fillOption);

//     }
//     else if (rectSpecificationMethod == SPECIFY_BY_CENTER)
//     {
//         initializeByCenter(
//             centerRow,
//             centerColumn,
//             halfNumberOfRows,
//             halfNumberOfColumns,
//             rectColor,
//             fillOption);

//     }
//     return true;
// }


// bool RectangleClass::initializeByCorners(
//     int upperLeftRow,
//     int upperLeftColumn,
//     int lowerRightRow,
//     int lowerRightColumn,
//     int rectColor,
//     int fillOption)
// {
//     upperLeft.setRowCol(upperLeftRow, upperLeftColumn);
//     lowerRight.setRowCol(lowerRightRow, lowerRightColumn);
//     setColor(rectColor);
//     setFilled(fillOption);
//     return true;
// }


// bool RectangleClass::initializeByDim(
//     int upperLeftRow,
//     int upperLeftColumn, 
//     int numberOfRows, 
//     int numberOfColumns, 
//     int rectColor, 
//     int fillOption)
// {
//     upperLeft.setRowCol(upperLeftRow, upperLeftColumn);
//     lowerRight.setRowCol(
//         upperLeftRow + numberOfRows -1,
//         upperLeftColumn + numberOfColumns -1);
//     setColor(rectColor);
//     setFilled(fillOption);
//     return true; 
// }


// bool RectangleClass::initializeByCenter(
//     int centerRow,
//     int centerColumn,
//     int halfNumberOfRows,
//     int halfNumberOfColumns,
//     int rectColor,
//     int fillOption)
// {
//     upperLeft.setRowCol(
//         centerRow - halfNumberOfRows,
//         centerColumn - halfNumberOfColumns);
//     lowerRight.setRowCol(
//         centerRow + halfNumberOfRows,
//         centerColumn + halfNumberOfColumns);
//     setColor(rectColor);
//     setFilled(fillOption);
//     return true;
// }

