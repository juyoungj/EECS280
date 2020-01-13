#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_


//Global Constants

//Programmer: Juyoung Jung
//Date: November-14-2018
/*
Purpose: The header file that contains all the global constants
*/
using namespace std;

// Maximum Color Component Value
const int COLOR_MAXIMUM = 255;
// Minimum Color Component Value
const int COLOR_MINIMUM = 0;
// Default values for row and column
const int DEFAULT_ROW_COLUMN = 0;
// Minimum number of row an image should avoid
const int MINIMUM_ROW = 0;
// Minimum number of column an image should avoid
const int MINIMUM_COLUMN = 0;
// Initial color values when reading in the image file
const int INITIAL_COLOR_VALUES = 0;
// Corresponding menu integers for each Color
const int RED = 1;
const int GREEN = 2;
const int BLUE = 3;
const int BLACK = 4;
const int WHITE = 5;
// Corresponding menu integers for each fill option
const int NO = 1;
const int YES = 2;
// Corresponding menu integers for the first five menu
const int ANNOTATE_RECTANGLE = 1;
const int ANNOTATE_PATTERN = 2;
const int INSERT_IMAGE = 3;
const int WRITE_IMAGE = 4;
const int EXIT = 5;
// Assumed maximum number of characters to extract(and ignore)
const int CIN_IGNORE = 200;
const int INFILE_IGNORE = 200;
const int ANNOTEFILE_IGNORE = 200;
// Menu options to specify methods for constructing rectangle
const int SPECIFY_BY_CORNERS = 1;
const int SPECIFY_BY_DIMENSIONS = 2;
const int SPECIFY_BY_CENTER = 3;
//RESUBMISSION
//Prompt for the menu
const string PPM_PROMPT = "Enter string for PPM image file name to load: ";
const string INSERT_PROMPT = 
    "Enter string for file name of PPM image to insert: ";
const string COLOR_REC_PROMPT = "Enter int for rectangle color: ";
const string COLOR_PAT_PROMPT = "Enter int for pattern color: ";
const string COLOR_TRANSPARENCY_PROMPT = "Enter int for transparency color: ";
// Corresponding menu integer for the pattern value
const int YES_PAT = 1;
#endif
