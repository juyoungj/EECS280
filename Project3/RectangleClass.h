#ifndef _RECTCLASS_
#define _RECTCLASS_

#include "ColorClass.h"
#include "RowColumnClass.h"

//Programmer: Juyoung Jung
//Date: November-14-2018

/*
Purpose: Initialize the rectangle with the information users select 
such as color, filled option, and location.  Set the location of a 
rectangle with upper right corner and lower left corner.
*/
class RectangleClass
{
    private:

        //RESUBMISSION - Unnecessary attributes deleted from
        //private variables and changed them into local variables
        // bool validRectMenuChoice;
        // int rectSpecificationMethod;
        // int upperLeftRow;
        // int upperLeftColumn;
        // int lowerRightRow;
        // int lowerRightColumn;
        // int numberOfRows;
        // int numberOfColumns;
        // int centerRow;
        // int centerColumn;
        // int halfNumberOfRows;
        // int halfNumberOfColumns;

        // bool validRectColorChoice;
        // bool validRectFillChoice;
        int rectColor;
        int fillOption;

        //RESUBMISSION - Unnecessary attribute
        // int rectangleColor;
        //RESUBMISSION - Unnecessary attribute
        // int filled;


        RowColumnClass upperLeft;
        RowColumnClass lowerRight;
        

    public:
        //provide users 3 method options to draw a rectangle 
        //with error handling
        bool makeRectangle();
        //provide users 5 different color options with error handling
        bool rectColors();
        //provide users 2 options whether to fill a rectangle with
        //error handling
        bool rectFill();


        //RESUBMISSION - Unnecessary function
        // bool locatingRectangle();

        //RESUBMISSION - Unnecessary function
        // bool setColor(int rectColor);

        //returns color of rectangle
        int getColor();


        //RESUBMISSION - Unnecessary function
        // bool setFilled(int fillOption);

        //returns fill option for a rectangle
        int getFilled();

        //RESUBMISSION - Unnecessary functions
        // /*
        // initialize the location, color, and fill option 
        // of a rectangle with the information about two corners,
        // and set the upperLeft and lowerRight corners
        // */
        // bool initializeByCorners(
        //     int upperLeftRow,
        //     int upperLeftColumn,
        //     int lowerRightRow,
        //     int lowerRightColumn,
        //     int rectColor,
        //     int fillOption);
        // /*
        // initialize the location, color, and fill option 
        // of a rectangle with the information about upper left corner
        // and number of rows and columns, and 
        // set the upperLeft and lowerRight corners
        // */
        // bool initializeByDim(
        //     int upperLeftRow,
        //     int upperLeftColumn, 
        //     int numberOfRows, 
        //     int numberOfColumns, 
        //     int rectColor, 
        //     int fillOption);
        // /*
        // initialize the location, color, and fill option 
        // of a rectangle with the information about the center and
        // half of the number of rows and columns,
        // and set the upperLeft and lowerRight corners
        // */
        // bool initializeByCenter(
        //     int centerRow,
        //     int centerColumn,
        //     int halfNumberOfRows,
        //     int halfNumberOfColumns,
        //     int rectColor,
        //     int fillOption);

        //RowColumnClass that returns the upper left corner
        RowColumnClass getUpperLeft();
        //RowColumnClass that returns the lower right corner
        RowColumnClass getLowerRight();

};

#endif
