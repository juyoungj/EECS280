#include <iostream>
#include "printMenu.h"
#include "ColorImageClass.h"
#include "RectangleClass.h"
#include "ColorClass.h"
#include "AnnotatePattern.h"
#include "constants.h"

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The main function that conducts actual image modification and 
function implementation. This main function implement functions that
print out menuselection, read Images, modify Images, and write out images.
*/

using namespace std;
int main()
{
    ColorImageClass uploadPhoto;
    AnnotatePattern annotatePhoto;
    RectangleClass addRectToPhoto;
    //RESUBMISSION - if readimagefile fails it exits the program
    if (!uploadPhoto.ColorImageClass::readImageFile(PPM_PROMPT))
    {
        return 0;
    }
    int menuSelection = printMenu();
    while (menuSelection != EXIT)
    {
        if (menuSelection == ANNOTATE_RECTANGLE)
        {
            addRectToPhoto.RectangleClass::makeRectangle();
            addRectToPhoto.RectangleClass::rectColors();
            addRectToPhoto.RectangleClass::rectFill();
            //RESUBMISSION - Unnecessary function
            // addRectToPhoto.RectangleClass::locatingRectangle();
      
            uploadPhoto.ColorImageClass::drawRectangle(addRectToPhoto);

            menuSelection = printMenu();
        }
        if (menuSelection == ANNOTATE_PATTERN)
        {
            annotatePhoto.AnnotatePattern::readPattern();
            annotatePhoto.AnnotatePattern::specifyCorner();
            annotatePhoto.AnnotatePattern::colorPattern();
            //RESUBMISSION - Unnecessary functions
            // annotatePhoto.AnnotatePattern::locatePattern();

            uploadPhoto.ColorImageClass::annotatePattern(annotatePhoto);

            menuSelection = printMenu();
        }
        if (menuSelection == INSERT_IMAGE)
        {
            uploadPhoto.ColorImageClass::insertImage();
            menuSelection = printMenu();
        }
        if (menuSelection == WRITE_IMAGE)
        {
            uploadPhoto.ColorImageClass::writeImageFile();
            menuSelection = printMenu();
        }
    }
    if (menuSelection == EXIT)
    {
        cout << "Thank you for using this program" << endl;
    }
    return(0);
}
