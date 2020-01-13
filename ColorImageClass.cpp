#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "constants.h"
#include "RectangleClass.h"
#include "AnnotatePattern.h"
using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The ColorImageClass read in and write out image files,
while handling errors and provide users options to modify images.
This class modifies images by changing pixel values composed of 
red, green, and blue in each row and column.
*/

//default constructor to avoid memory leak
ColorImageClass::ColorImageClass()
{
    pixels = 0;
}

//desturctor to avoid memory leak by using delete operator
ColorImageClass::~ColorImageClass()
{
    if (pixels == 0)
    {
        return;
    }
    for (int i = 0; i < row; ++i)
    {
        delete [] pixels[i];
    }
    delete [] pixels;
}

//check if location is valid
bool ColorImageClass::checkLocation(RowColumnClass &inRowCol)
{
    bool checkLocation = true;

    if (inRowCol.getRow() >= row ||
        inRowCol.getCol() >= column ||
        inRowCol.getRow() < MINIMUM_ROW ||
        inRowCol.getCol() < MINIMUM_COLUMN)
    {
        checkLocation = false;
    }
    return checkLocation;
}

//initializes all image pixels to the color provided via input
void ColorImageClass::initializeTo(ColorClass &inColor)
{    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            pixels[i][j].setTo(inColor);
        }
    }
}

/*
performs a pixel-wise addition, such that each pixel in the image
has the pixel in the corresponding location in the right hand side
input image added to it. returns true when clipping needed
otherwise returns false
*/
bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
    bool addImageToClipped = false;
    bool addImageToClippedTemp;
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            addImageToClippedTemp 
            = pixels[i][j].addColor(rhsImg.pixels[i][j]);
            if (addImageToClippedTemp == true)
            {
                addImageToClipped = true;
            }
        }
    }
    return addImageToClipped;
}

/*
causes the image's pixel values to be set to the sum of the
corresponding peixels in each image in the imagesToAdd
input parameter
*/
bool ColorImageClass::addImages(
    int numImgsToAdd,
    ColorImageClass imagesToAdd[])
{
    ColorClass allBlack;
    allBlack.setToBlack();
    //below initialize the baseimage with color values black(zero values)
    //to add up values from imagestoAdd
    ColorImageClass baseImage;
    baseImage.initializeTo(allBlack);

    bool addImagesClipped = false;
    bool addImagesClippedTemp;
    for (int i = 0; i < numImgsToAdd; i++)
    {
        addImagesClippedTemp = baseImage.addImageTo(imagesToAdd[i]);

        if (addImagesClippedTemp == true)
        {
            addImagesClipped = true;
        }
    }
    //below initialize the image we try to modify to 
    //zero to add color values of baseimage
    initializeTo(allBlack);
    addImageTo(baseImage);
    return addImagesClipped;
}

/*
sets the pixel at the location specified by the "inRowCol"
parameter to the color specified via the "inColo" parameter.
if valid location returns true, otherwise returns false.
*/
bool ColorImageClass::setColorAtLocation(
    RowColumnClass &inRowCol, 
    ColorClass &inColor)
{
    if (checkLocation(inRowCol))
    {
        pixels[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
        return true;
    }
    else
    {
        return false;
    }
}

/*
"outColor" is assigned to the color of the image pixel 
at the location. If valid location returns true, otherwise false.
*/
bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
    ColorClass &outColor)
{
    if(checkLocation(inRowCol))
    {
        outColor.setTo(pixels[inRowCol.getRow()][inRowCol.getCol()]);
        return true;
    }
    else
    {
        return false;
    }
}


//reading in an image file while handling errors
bool ColorImageClass::readImageFile(const string & prompt)
{
    ifstream inFile;
    string inFname;
    cout << prompt;
    cin >> inFname;
    inFile.open(inFname.c_str());
    
    //RESUBMISSION - ERROR HANDLING
    if (inFile.fail())
    {
        cout << "Unable to open input file!" << endl;
        return false;
    }
    
    // bool readSuccess = false;
    // while(!readSuccess)
    // {
    //     if (inFile.fail())
    //     {
    //         cout << "Error unable to open file! " << inFname << endl;
    //         cout << "Enter string for PPM image file name to load: ";
    //         cin >> inFname;
    //         inFile.open(inFname.c_str());
    //     }

    //     else
    //     {
    //         readSuccess = true;
    //     }

    // }

    //RESUBMISSION - change the bool variable to more descriptive name
    bool isImage = false;                                          

    // check if the header is in the right format
    while (!isImage)
    {
        inFile >> header;
        if (inFile.eof())
        {
            cout << "EOF before reading header" << endl;
            return false;
        }
        //RESUBMISSION - in case resulting in the fail state
        else if (inFile.fail())
        {
            inFile.clear();
            inFile.ignore(INFILE_IGNORE, '\n');
            return false;
        }
        else if (header != "P3")
        {
            cout << "PPM header should be P3!" << endl;
            return false;
        }
        else
        {
            isImage = true;
        }
    }

    isImage = false;

    // check if the column value from inFile is in range
    while (!isImage)
    {
        inFile >> column;
        if (inFile.eof())
        {
            cout << " EOF before reading column " << endl;
            return false;
        }
        //RESUBMISSION - in case resulting in the fail state
        else if (inFile.fail())
        {
            inFile.clear();
            inFile.ignore(INFILE_IGNORE, '\n');
            return false;
        }
        else if (column <= MINIMUM_COLUMN)
        { 
            cout << " error regarding width " << endl;
            return false;
        }
        else
        {
            isImage = true;
        }
    }

    isImage = false;

    // check if the row value from inFile is in range
    while (!isImage)
    {
        inFile >> row;
        if (inFile.eof())
        {
            cout << " EOF before reading row " << endl;
            return false;
        }
        else if (inFile.fail())
        {
            inFile.clear();
            inFile.ignore(INFILE_IGNORE, '\n');
            return false;
        }
        else if (row <= MINIMUM_ROW)
        { 
            cout << " error regarding height " << endl;
            return false;
        }
        else
        {
            isImage = true;
        }
    }

    isImage = false;

    // check if the row value from inFile is in range
    while (!isImage)
    {
        inFile >> maxColor;
        if (inFile.eof())
        {
            cout << "EOF before reading maxColor" << endl;
            return false; 
        }
        else if (inFile.fail())
        {
            inFile.clear();
            inFile.ignore(INFILE_IGNORE, '\n');
            return false;
        }
        else if (maxColor < COLOR_MINIMUM)
        { 
            cout << "max color error " << endl;
            return false;
        }
        else if (maxColor > COLOR_MAXIMUM)
        { 
            cout << "max color error " << endl;
            return false;
        }
        else{
            isImage = true;
        }
    }

    // dynamic allocation of array
    pixels = new ColorClass * [row]; //create R # of rows
    for (int i = 0; i < row; ++i)
    {
        //for each row, create array with C columns
        pixels[i] = new ColorClass[column];
    }

    //RESUBMISSION - using color class member function to read in pixel
    //values and set colors to each pixel - FIXING DESIGN ERROR
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            pixels[i][j].readFromFile(inFile);
        }
    }
    inFile.close();
    return true;
}

//writing out a new image file while handling errors
bool ColorImageClass::writeImageFile()
{
    ofstream outFile;
    string outFname;
    cout << "Enter string for PPM file name to output: ";
    cin >> outFname;
    outFile.open(outFname.c_str());
    
    if (outFile.fail())
    {
        cout << " error statement " << endl;
        return false;
    }

    outFile << header << endl;
    outFile << column << " " << row << endl;
    outFile << maxColor << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            pixels[i][j].printComponentValues(outFile);
        }
        outFile << endl;
    }
    outFile.close();
    return true;
}




//function to draw rectangles with color and filled option with
//information provided by RowColumnClass and RectangleClass
bool ColorImageClass::drawRectangle(
    RectangleClass &rectangle)
{
    RowColumnClass upperLeftCorner = rectangle.getUpperLeft();
    RowColumnClass lowerRightCorner = rectangle.getLowerRight();

    int upperRow = upperLeftCorner.getRow();
    int upperCol = upperLeftCorner.getCol();
    int lowerRow = lowerRightCorner.getRow();
    int lowerCol = lowerRightCorner.getCol();

    int color = rectangle.getColor();

    int fill = rectangle.getFilled();
    //RESUBMISSION - cropping rectangle that goes out of bounds
    if (fill == YES)
    {
        for (int r = upperRow; r <= lowerRow; r++)
        {
            for(int c = upperCol; c <= lowerCol; c++)
            {
                if (r >= MINIMUM_ROW && r < row && 
                    c >= MINIMUM_COLUMN && c < column)
                {
                    pixels[r][c].setColor(color);
                }
                
            }
        }
    }
    else if (fill == NO)
    {
        for (int c = upperCol; c <= lowerCol; c++)
        {
            if (upperRow >= MINIMUM_ROW && upperRow < row && 
                c >= MINIMUM_COLUMN && c < column)
            {
                pixels[upperRow][c].setColor(color);
            }
            if (lowerRow >= MINIMUM_ROW && lowerRow < row && 
                c >= MINIMUM_COLUMN && c < column)
            {
                pixels[lowerRow][c].setColor(color);
            }
            
        }
        for (int r = upperRow; r <= lowerRow; r++)
        {
            if (upperCol >= MINIMUM_COLUMN && upperCol < column && 
                r >= MINIMUM_ROW && r < row)
            {
                pixels[r][upperCol].setColor(color);
            } 
            if (lowerCol >= MINIMUM_COLUMN && lowerCol < column && 
                r >= MINIMUM_ROW && r < row)
            {
                pixels[r][lowerCol].setColor(color);
            } 
        }

    }
    return true;
}


//RESUBMISSION CODE UPDATE - new member function
//New member function that annotates pattern in the image by changing
//pixel values 
bool ColorImageClass::annotatePattern(
    AnnotatePattern &pattern)
{
    RowColumnClass upperLeftCorner = pattern.getUpperLeft();

    int upperLeftRow = upperLeftCorner.getRow();
    int upperLeftCol = upperLeftCorner.getCol();
    

    int patRow = pattern.getRow();
    int patCol = pattern.getCol();

    int upperRightRow = upperLeftRow + patRow;
    int upperRightCol = upperLeftCol + patCol;

    int color = pattern.getColor();

    for (int r = upperLeftRow; r < upperRightRow && r < row; r++)
    {
        for (int c = upperLeftCol; c < upperRightCol && c < column; c++)
        {
            int isPat = pattern.getOneZero(r - upperLeftRow, c - upperLeftCol);
            if (isPat == YES_PAT)
            {
                if (r >= MINIMUM_ROW && r < row && 
                    c >= MINIMUM_COLUMN && c < column)
                {
                    pixels[r][c].setColor(color);
                }  
            }
            
        }
    }
       
    return true;

}


//RESUBMISSION - inserting an image
//function inserting an image with transparency checking
bool ColorImageClass::insertImage(){
    ifstream insertFile;
    string ifname;
    ColorImageClass inImage;
    bool readSuccess = false;
    while (!readSuccess)
    {
        if (inImage.readImageFile(INSERT_PROMPT))
        {
            readSuccess = true;
        }
    }
    cout << "Enter upper left corner to insert image row and column: ";
    int upLeftRow;
    int upLeftCol;
    cin >> upLeftRow;
    cin >> upLeftCol;
    ColorClass pixel;
    pixel.transparencyColorCheck();
    for (int r = upLeftRow; r < upLeftRow + inImage.row; r++)
    {
        for (int c = upLeftCol; c < upLeftCol + inImage.column; c++)
        {
            if (inImage.pixels[r - upLeftRow][c - upLeftCol].colorEqual(pixel))
            {
                if (r >= MINIMUM_ROW && r < row && 
                    c >= MINIMUM_COLUMN && c < column)
                {
                    pixels[r][c] = 
                        inImage.pixels[r - upLeftRow][c - upLeftCol];
                }     
            }
        }
    }
    return true; 
}
