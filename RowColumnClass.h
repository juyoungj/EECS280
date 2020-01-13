#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: Set and get the values of rows and columns.
         Represent rows and columns
*/

class RowColumnClass
{
    private:
        int row, col;

    public:
        //default ctor sets the row and column values to 0
        RowColumnClass();
        //value ctor sets the row and column values to the corresponding
        //input values
        RowColumnClass(int inRow, int inCol);
        //sets the row and column value to the corresponding input values
        void setRowCol(int inRow, int inCol);
        //sets the row value to the input value
        void setRow(int inRow);
        //sets the column value to the input value
        void setCol(int inCol);
        //returns the row attribute
        int getRow();
        //returns the column attribute 
        int getCol();
        //adds the row and column index values in the input parameter
        //to the row and column index of the object
        void addRowColTo(RowColumnClass &inRowCol);
        //prints the object's attributes(row and column) to the console
        void printRowCol();
};
#endif