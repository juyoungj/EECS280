#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "AnnotatePattern.h"
#include <fstream>
using namespace std;

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The ColorImageClass read in and write out image files,
while handling errors and provide users options to modify images.
This class modifies images by changing pixel values composed of 
red, green, and blue in each row and column.
*/

//ColorImageClass represetns an image
class ColorImageClass
{
    private:
        ColorClass **pixels;

        //RESUBMISSION - Unnecessary variable
        // bool checkFunction;
        int column;
        int row;
        int maxColor;
        string header;

    public:
        
        
        //default constructor to avoid memory leak by assigining zero
        //to the arr(double pointer)
        ColorImageClass();

        //desturctor to avoid memory leak by using delete operator
        ~ColorImageClass();


        //check if location is valid
        bool checkLocation(RowColumnClass &inRowCol);

        //initializes all image pixels to the color provided via input
        void initializeTo(ColorClass &inColor);

        /*
        performs a pixel-wise addition, such that each pixel in the image
        has the pixel in the corresponding location in the right hand side
        input image added to it. returns true when clipping needed
        otherwise returns false
        */
        bool addImageTo(ColorImageClass &rhsImg);

        /*
        causes the image's pixel values to be set to the sum of the
        corresponding peixels in each image in the imagesToAdd
        input parameter
        */
        bool addImages(int numImgsToAdd,ColorImageClass imagesToAdd []);

        /*
        sets the pixel at the location specified by the "inRowCol"
        parameter to the color specified via the "inColo" parameter.
        if valid location returns true, otherwise returns false.
        */
        bool setColorAtLocation(
            RowColumnClass &inRowCol,
            ColorClass &inColor);
    
        /*
        "outColor" is assigned to the color of the image pixel 
        at the location. If valid location returns true, otherwise false.
        */
        bool getColorAtLocation(
            RowColumnClass &inRowCol,
            ColorClass &outColor);

        //reading in an image file while handling errors
        bool readImageFile(const string & prompt);

        //writing out a new image file while handling errors
        bool writeImageFile();

        //function to draw rectangles with color and filled option with
        //information provided by RowColumnClass and RectangleClass
        bool drawRectangle(RectangleClass &rectangle);
        
        //RESUBMISSION CODE UPDATE - new member function
        //New member function that annotates pattern in the image by changing
        //pixel values
        bool annotatePattern(AnnotatePattern &pattern);

        //RESUBMISSION - inserting an image
        //function inserting an image with transparency checking
        bool insertImage();

};
#endif