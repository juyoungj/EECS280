#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

//Global Constants

//Programmer: Juyoung Jung
//Date: Dec-05-2018
/*
Purpose: The header file that contains all the global constants
*/

// Event Type either customer arrived or customer being served
const int ARRIVED = 1;
const int SERVED = 0;

// Random Seed Value. Set arbitrarily as 600.
// const int SEED = 600;

// Min and Max values for the uniform distribution that will draw 
// customers who either willing to wait or not willing to wait
const int WAITMIN = 1;
const int WAITMAX = 100;

// When there is no one waiting in the line
const int NOLINE = 0;

// Minimum Time to be included in conditions which is zero 
const int ZEROTIME = 0;

// Customer label before any customer
const int ZEROLABEL = 0;

#endif