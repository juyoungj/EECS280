#ifndef _ANNOTATEPATTERN_H_
#define _ANNOTATEPATTERN_H_

#include "RowColumnClass.h"


//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The AnnotatePattern class read in the pattern in the 
2 dimentional array and contains the information about the pattern 
such as number of rows and columns and color
*/

class AnnotatePattern
{
    private:
        int **pattern;
        int row;
        int column;
        int patternColor;

        RowColumnClass upperLeft;


    public:
        //default constructor
        AnnotatePattern();
        //destructor
        ~AnnotatePattern();
        //function to read in a pattern with error handling
        bool readPattern();
        //locate pattern in the image using information about corner
        bool specifyCorner();
        //give users color options for pattern
        bool colorPattern();
        //return color value of pattern
        int getColor();
        //return number of rows of pattern
        int getRow();
        //return number of columns of pattern
        int getCol();
        //get the values of pattern which is either one or zero
        int getOneZero(int row, int column);

        //return the RowColumnClass attribute which contains information about
        //upper left corner
        RowColumnClass getUpperLeft();
        
};
#endif