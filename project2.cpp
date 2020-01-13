#include <iostream>

using namespace std;

//Programmer: Juyoung Jung
//Date: October-09-2018
/*
Purpose: In this Project, I created three classes to make up an image.
ColorClass describes colors composed of three basic colors: red, green,
and blue. ColorImageClass describes images composed of colors in
each pixel. The pixel color values are often stored as a two
dimensional array. RowColumnClass represents rows and columns
of each pixel.
*/

const int COLOR_MAXIMUM = 1000;
const int COLOR_MINIMUM = 0;
const int DEFAULT_ROW_COLUMN = -99999;
const int IMAGE_ROW = 10;
const int IMAGE_COL = 18;

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
        //the default ctor set the color's initial RGB values to the
        //color full white.
        ColorClass();
        //the value ctor clips specified input color values
        ColorClass(int inRed, int inGreen, int inBlue);
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
        //print the component color values to the console.
        void printComponentValues();
};



class RowColumnClass
{
    private:
        int row, col;

    public:
        //default ctor sets the row and column values to -99999
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

class ColorImageClass
{
    private:
        ColorClass pixels[IMAGE_ROW][IMAGE_COL];

    public:
        //default ctor sets all pixels in the image to full black
        ColorImageClass();
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
        corresponding pixels in each image in the imagesToAdd 
        input parameter
        */
        bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);
        /*
        sets the pixel at the location specified by the "inRowCol"
        parameter to the color specified via the "inColo" parameter.
        if valid location returns true, otherwise returns false.
        */
        bool setColorAtLocation(
            RowColumnClass &inRowCol, 
            ColorClass &inColor
            ); 
        /*
        "outColor" is assigned to the color of the image pixel 
        at the location. If valid location returns true, otherwise false.
        */
        bool getColorAtLocation(
            RowColumnClass &inRowCol, 
            ColorClass &outColor
            );
        //prints the contents of the image to the screen.
        //each pixel printed using the format described for ColorClass
        void printImage();
};



#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];

    //Test some basic ColorClass operations...
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.setToBlack();
    cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;

    //Test some basic RowColumnClass operations...
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;

    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;

    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;

    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;

    //Test some basic ColorImageClass operations...
    testColor.setToRed();
    testImage.initializeTo(testColor);

    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;

    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;

    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);

    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);

    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);

    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages);
  
    //Check some certain values
    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2)
    {
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
  
    for (int rowInd = 0; rowInd < 8; rowInd += 2)
    {
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
  
    cout << "Printing entire test image:" << endl;
    testImage.printImage();
    
    return 0;
}
#endif

ColorClass::ColorClass()
{
    red = COLOR_MAXIMUM; 
    green = COLOR_MAXIMUM;
    blue = COLOR_MAXIMUM;
}

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

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
    clipColor(inRed);
    clipColor(inGreen);
    clipColor(inBlue);
    red = inRed;
    green = inGreen;
    blue = inBlue;
}


void ColorClass::setToBlack()
{
    red = COLOR_MINIMUM;
    green = COLOR_MINIMUM;
    blue = COLOR_MINIMUM;
}

void ColorClass::setToRed()
{
    red = COLOR_MAXIMUM;
    green = COLOR_MINIMUM;
    blue = COLOR_MINIMUM;
}

void ColorClass::setToGreen()
{
    red = COLOR_MINIMUM;
    green = COLOR_MAXIMUM;
    blue = COLOR_MINIMUM;
}

void ColorClass::setToBlue()
{
    red = COLOR_MINIMUM;
    green = COLOR_MINIMUM;
    blue = COLOR_MAXIMUM;
}

void ColorClass::setToWhite()
{
    red = COLOR_MAXIMUM;
    green = COLOR_MAXIMUM;
    blue = COLOR_MAXIMUM;
}


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

void ColorClass::printComponentValues()
{
    cout << "R: " << red << " G: " << green << " B: " << blue;
}

RowColumnClass::RowColumnClass()
{
    row = DEFAULT_ROW_COLUMN;
    col = DEFAULT_ROW_COLUMN;
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
    row = inRow;
    col = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
    row = inRow;
    col = inCol;
}

void RowColumnClass::setRow(int inRow)
{
    row = inRow;
}

void RowColumnClass::setCol(int inCol)
{
    col = inCol;
}

int RowColumnClass::getRow()
{
    return row;
}

int RowColumnClass::getCol()
{
    return col;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
    row += inRowCol.row;
    col += inRowCol.col;
}

void RowColumnClass::printRowCol()
{
    cout << "[" << row << "," << col << "]";
}

ColorImageClass::ColorImageClass()
{
    for (int i = 0; i < IMAGE_ROW; i++)
    {
        for (int j = 0; j < IMAGE_COL; j++)
        {
            pixels[i][j].setToBlack();
        }
    }
    
}

void ColorImageClass::initializeTo(ColorClass &inColor)
{
    for (int i = 0; i < IMAGE_ROW; i++)
    {
        for(int j = 0; j < IMAGE_COL; j++)
        {
            pixels[i][j].setTo(inColor);
        }
    }
    
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
    bool addImageToClipped = false;
    bool addImageToClippedTemp;
    for (int i = 0; i < IMAGE_ROW; i++)
    {
        for(int j = 0; j < IMAGE_COL; j++)
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

bool ColorImageClass::addImages(
     int numImgsToAdd, 
     ColorImageClass imagesToAdd []
     ) 
{
    ColorClass allBlack;
    allBlack.setToBlack();
    //below initialize the baseimage with color values black(zero values)
    //to add up values from imagestoAdd
    ColorImageClass baseImage;
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

bool ColorImageClass::setColorAtLocation(
    RowColumnClass &inRowCol, 
    ColorClass &inColor
    )
{
    bool isValid = true;
    int row = inRowCol.getRow();
    int col = inRowCol.getCol();
    if (row < IMAGE_ROW &&
        row >= 0 && 
        col < IMAGE_COL &&
        col >= 0
        )
    {
        pixels[row][col].setTo(inColor); 
    }
    else
    {
        isValid = false;
    }
    return isValid;
}

bool ColorImageClass::getColorAtLocation(
    RowColumnClass &inRowCol,
    ColorClass &outColor
    )
{
    bool isValid = true;
    int row = inRowCol.getRow();
    int col = inRowCol.getCol();
    if (row < IMAGE_ROW &&
        row >= 0 && 
        col < IMAGE_COL &&
        col >= 0
        )
    {
        outColor.setTo(pixels[row][col]);
    }
    else
    {
        isValid = false;
    }
    return isValid;

}

void ColorImageClass::printImage()
{
    for (int i = 0; i < IMAGE_ROW; i++)
    {
        for (int j = 0; j < IMAGE_COL-1; j++)
        {
            pixels[i][j].printComponentValues();
            cout << "--" ;
        }
        pixels[i][IMAGE_COL-1].printComponentValues();
        cout << endl;
    }
}
