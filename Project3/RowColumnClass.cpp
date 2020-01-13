#include <iostream>
#include "RowColumnClass.h"
#include "constants.h"
using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: Set and get the values of rows and columns 
         Represent rows and columns
*/

//default ctor sets the row and column values to 0
RowColumnClass::RowColumnClass()
{
    row = DEFAULT_ROW_COLUMN;
    col = DEFAULT_ROW_COLUMN;
}

//value ctor sets the row and column values to the corresponding input values
RowColumnClass::RowColumnClass(int inRow, int inCol)
{
    row = inRow;
    col = inCol;
}

//sets the row and column value to the corresponding input values
void RowColumnClass::setRowCol(int inRow, int inCol)
{
    row = inRow;
    col = inCol;
}

//sets the row value to the input value
void RowColumnClass::setRow(int inRow)
{
    row = inRow;
}

//sets the column value to the input value
void RowColumnClass::setCol(int inCol)
{
    col = inCol;
}

 //returns the row attribute
int RowColumnClass::getRow()
{
    return row;
}

//returns the column attribute 
int RowColumnClass::getCol()
{
    return col;
}

//adds the row and column index values in the input parameter
//to the row and column index of the object
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
    row += inRowCol.row;
    col += inRowCol.col;
}

//prints the object's attributes(row and column) to the console
void RowColumnClass::printRowCol()
{
    cout << "[" << row << "," << col << "]";
}
