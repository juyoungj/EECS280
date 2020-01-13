#include <iostream>
#include "AnnotatePattern.h"
#include "printColorMenu.h"
#include <fstream>
#include <cstdlib>
#include <string>

#include "constants.h"
using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The AnnotatePattern class read in the pattern in the 
2 dimentional array and contains the information about the pattern 
such as number of rows and columns and color
*/


//default constructor to avoid memory leak
AnnotatePattern::AnnotatePattern()
{
    pattern = 0;
}

//desturctor to avoid memory leak by using delete operator
AnnotatePattern::~AnnotatePattern()
{
    if (pattern == 0)
    {
        return;
    }
    for (int i = 0; i < row; ++i)
    {
        delete [] pattern[i];
    }
    delete [] pattern;
}

//function to read in a pattern with error handling
bool AnnotatePattern::readPattern()
{
    ifstream annoteFile;
    string ifname;
    cout << "Enter string for file name containing pattern: ";
    cin >> ifname;
    annoteFile.open(ifname.c_str());
    
    // checks whether it fails to open the annotation file.
    bool readSuccess = false;
    while (!readSuccess)
    {
        if (annoteFile.fail())
        {
            cout << "Error unable to open file! " << ifname << endl;
            cout << "Enter string for file name containing pattern: ";
            cin >> ifname;
            annoteFile.open(ifname.c_str());
        }

        else
        {
            readSuccess = true;
        }
    }

    
    bool isFile = false;

    // check if the column value from annoteFile is in range
    while (!isFile)
    {
        annoteFile >> column;
        if (annoteFile.eof())
        {
            cout << " error message regarding EOF " << endl;
            return false; 
        }
        else if (annoteFile.fail())
        {
            annoteFile.clear();
            annoteFile.ignore(ANNOTEFILE_IGNORE, '\n');
        }
        else if (column <= MINIMUM_COLUMN)
        { 
            cout << " error regarding width " << endl;
            return false; 
        }
        else
        {
            isFile = true;
        }
    }

    isFile = false;

    // check if the row value from annoteFile is in range
    while (!isFile)
    {
        annoteFile >> row;
        if (annoteFile.eof())
        {
            cout << " error message regarding EOF " << endl;
            return false; 
        }
        else if (annoteFile.fail())
        {
            annoteFile.clear();
            annoteFile.ignore(ANNOTEFILE_IGNORE, '\n');
        }
        else if (row <= MINIMUM_ROW)
        { 
            cout << " error regarding height " << endl;
            return false; 
        }
        else
        {
            isFile = true;
        }
    }

    pattern = new int *[row];
    for (int i = 0; i < row; ++i)
    {
        pattern[i] = new int[column];
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            int ifPattern;                          
            annoteFile >> ifPattern;
            
            // check the pixel values
            if (annoteFile.fail())
            {
                cout << "Error invalid pattern at ["
                    << i << "," << j << "]"
                    << endl;
                    return false; 
            }
            else
            {
                pattern[i][j] = ifPattern;
            }
        }
    }

    return true;

}


//locate pattern in the image using information about corner
bool AnnotatePattern::specifyCorner()
{
    cout << 
    "Enter upper left corner of pattern row and column: ";
    
    int upperLeftRow;
    int upperLeftColumn;

    cin >> upperLeftRow;
    cin >> upperLeftColumn;
    upperLeft.setRowCol(upperLeftRow, upperLeftColumn); 
    return (true);
}

//give users color options for pattern
bool AnnotatePattern::colorPattern()
{
    //RESUBMISSION - use global function to call color menu
    patternColor = printColorMenu(COLOR_PAT_PROMPT);
    return (true);
}

//return color value of pattern
int AnnotatePattern::getColor()
{
    return patternColor;
}

//return the RowColumnClass attribute which contains information about 
//upper left corner
RowColumnClass AnnotatePattern::getUpperLeft()
{
    return upperLeft;
}

//return number of rows of pattern
int AnnotatePattern::getRow()
{
    return row;
}

//return number of columns of pattern
int AnnotatePattern::getCol()
{
    return column;
}

//get the values of pattern which is either one or zero
int AnnotatePattern::getOneZero(
    int row, 
    int column)
{
    return pattern[row][column];
}
