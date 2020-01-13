#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include "RectangleClass.h"
//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The ColorClass contains information about
color values and have functions to set color values.
*/

class ColorClass
{
    private:
        int red, green, blue;
        /*
        clipColor() changes the private values(red, green, blue) of
        ColorClass object after comparing to maximum and minimum allowed
        color values so that a requested color value less than the 
        allowed minimum is clipped to the minimum, while color values
        higher than the allowed maximum are clipped to the maximum.
        When clipped it returns true. When not clipped it returns false.
        */ 
        bool clipColor(int &inColor);

    public:
        
        //set the color's component values to full Black
        void setToBlack();
        //set the color's component values to full Red
        void setToRed();
        //set the color's component values to full Green
        void setToGreen();
        //set the color's component values to full Blue
        void setToBlue();
        //set the color's component values to full White
        void setToWhite();
        /*
        setTo() sets the color object's RGB values to the provided values
        if clipping is necessary assigned values will be clipped and
        returns true, otherwise returns false
        */
        bool setTo(int inRed, int inGreen, int inBlue);
        //this setTo() function sets the color's component color values to
        //the same as those in the "inColor" input parameter
        bool setTo(ColorClass &inColor);
        

        //RESUBMISSION - new member function that sets color with 
        //users' choice of integer value of color         
        bool setColor(int color);
        
        /*
        addColor() causes each RGB value to have the corresponding vluae
        from the input parameter color added to it. If any clipping was
        necessary it returns true, otherwise returns false
        */
        bool addColor(ColorClass &rhs);
        /*
        subtractColor() causes each RGB value to have the corresponding
        value from the input parameter subtracted from it. If any clipping
        was necessary it returns true, otherwise returns false
        */
        bool subtractColor(ColorClass &rhs);
        /*
        this function multiplies each RGB value by the adjustment factor 
        provided.If clipping was necessary it returns true, 
        otherwise returns false.
        */
        bool adjustBrightness(double adjFactor);
        //print the component color values.
        void printComponentValues(std::ostream &outputFile);
       
        //RESUBMISSION - new member function that read in the pixel values of
        //image file and set colors to each pixel - FIXING DESIGN ERROR
        void readFromFile(std::ifstream &inFile);
        
        //RESUBMISSION - new member function to check the transparency
        bool transparencyColorCheck();

        //RESUBMISSION - new member function to check if color values are same
        bool colorEqual(ColorClass &rhs);

};
#endif
