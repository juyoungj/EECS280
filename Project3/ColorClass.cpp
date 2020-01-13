#include <iostream>
#include <fstream>
#include "ColorClass.h"
#include "constants.h"
#include "RectangleClass.h"
#include "printColorMenu.h"

using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The ColorClass header file that contains information
about color values and have functions to set color values
*/


/*
clipColor() changes the private values(red, green, blue) of
ColorClass object after comparing to maximum and minimum allowed
color values so that a requested color value less than the 
allowed minimum is clipped to the minimum, while color values
higher than the allowed maximum are clipped to the maximum.
When clipped it returns true. When not clipped it returns false.
*/ 
bool ColorClass::clipColor(int &inColor)
{
    bool clipped;
    if (inColor < COLOR_MINIMUM)
    {
        inColor = COLOR_MINIMUM;
        clipped = true;
    }
    else if (inColor > COLOR_MAXIMUM)
    {
        inColor = COLOR_MAXIMUM;
        clipped = true;
    }
    else
    {
        clipped = false;
    }
    return clipped;
}

//set the color's component values to full Black
void ColorClass::setToBlack()
{
    red = COLOR_MINIMUM;
    green = COLOR_MINIMUM;
    blue = COLOR_MINIMUM;
}

//set the color's component values to full Red
void ColorClass::setToRed()
{
    red = COLOR_MAXIMUM;
    green = COLOR_MINIMUM;
    blue = COLOR_MINIMUM;
}

//set the color's component values to full Green
void ColorClass::setToGreen()
{
    red = COLOR_MINIMUM;
    green = COLOR_MAXIMUM;
    blue = COLOR_MINIMUM;
}

//set the color's component values to full Blue
void ColorClass::setToBlue()
{
    red = COLOR_MINIMUM;
    green = COLOR_MINIMUM;
    blue = COLOR_MAXIMUM;
}

//set the color's component values to full White
void ColorClass::setToWhite()
{
    red = COLOR_MAXIMUM;
    green = COLOR_MAXIMUM;
    blue = COLOR_MAXIMUM;
}

/*
setTo() sets the color object's RGB values to the provided values
if clipping is necessary assigned values will be clipped and
returns true, otherwise returns false
*/
bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
    red = inRed;
    green = inGreen;
    blue = inBlue;

    bool isRedClipped = clipColor(red);
    bool isGreenClipped = clipColor(green);
    bool isBlueClipped = clipColor(blue);

    return isRedClipped || isGreenClipped || isBlueClipped;
}

//this setTo() function sets the color's component color values to
//the same as those in the "inColor" input parameter
bool ColorClass::setTo(ColorClass &inColor)
{
    
    red = inColor.red; 
    green = inColor.green;
    blue = inColor.blue;
    bool isRedClipped = clipColor(red);
    bool isGreenClipped = clipColor(green);
    bool isBlueClipped = clipColor(blue);

    return isRedClipped || isGreenClipped || isBlueClipped;
}

/*
addColor() causes each RGB value to have the corresponding vluae
from the input parameter color added to it. If any clipping was
necessary it returns true, otherwise returns false
*/
bool ColorClass::addColor(ColorClass &rhs)
{
    red += rhs.red;
    green += rhs.green;
    blue += rhs.blue;
    bool isRedClipped = clipColor(red);
    bool isGreenClipped = clipColor(green);
    bool isBlueClipped = clipColor(blue);

    return isRedClipped || isGreenClipped || isBlueClipped;
}

/*
subtractColor() causes each RGB value to have the corresponding
value from the input parameter subtracted from it. If any clipping
was necessary it returns true, otherwise returns false
*/
bool ColorClass::subtractColor(ColorClass &rhs)
{
    red -= rhs.red;
    green -= rhs.green;
    blue -= rhs.blue;
    bool isRedClipped = clipColor(red);
    bool isGreenClipped = clipColor(green);
    bool isBlueClipped = clipColor(blue);

    return isRedClipped || isGreenClipped || isBlueClipped;
}

/*
this function multiplies each RGB value by the adjustment factor 
provided.If clipping was necessary it returns true, 
otherwise returns false.
*/
bool ColorClass::adjustBrightness(double adjFactor)
{
    red *= adjFactor;
    green *= adjFactor;
    blue *= adjFactor;

    red = int(red);
    green = int(green);
    blue = int(blue);

    bool isRedClipped = clipColor(red);
    bool isGreenClipped = clipColor(green);
    bool isBlueClipped = clipColor(blue);

    return isRedClipped || isGreenClipped || isBlueClipped;
}

//print the component color values.
void ColorClass::printComponentValues(std::ostream &outputFile)
{
    outputFile << red << " " << green << " " << blue << " ";
}



//RESUBMISSION - new member function that sets color with users'
//choice of integer value of color
bool ColorClass::setColor(int color)
{
   
    if (color == RED)
    {
        setToRed();
    }
    else if (color == GREEN)
    {
        setToGreen();
    }
    else if (color == BLUE)
    {
        setToBlue();
    }
    else if (color == BLACK)
    {
        setToBlack();
    }
    else if (color == WHITE)
    {
        setToWhite();
    }

    return true;
}

//RESUBMISSION - new member function that read in the pixel values of
//image file and set colors to each pixel
void ColorClass::readFromFile(ifstream &inFile)
{
    int red = INITIAL_COLOR_VALUES;
    int green = INITIAL_COLOR_VALUES;
    int blue = INITIAL_COLOR_VALUES;
    inFile >> red;
    inFile >> green;
    inFile >> blue;
    // check the pixel values
    if (inFile.fail())
    {
        cout << "Error invalid pixel values" << endl;      
    }
    // set the array into colors.
    else if (setTo(red, green, blue))
    {
        cout << "Error invalid RGB values" << endl;                    
    }


}

//RESUBMISSION - new member function to check the transparency
bool ColorClass::transparencyColorCheck()
{
    //RESUBMISSION - replace with global function to call color menu
    int transparencyColor;
    transparencyColor = printColorMenu(COLOR_TRANSPARENCY_PROMPT);
    setColor(transparencyColor);
    return true;
}

//RESUBMISSION - new member function to check if color values are same
bool ColorClass::colorEqual(ColorClass &rhs)
{
    if (rhs.red == red && rhs.blue == blue && rhs.green == green)
    {
        return false;
    }
    else
    {
        return true;
    }
}
