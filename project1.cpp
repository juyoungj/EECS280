#include <iostream>
using namespace std;


//Programmer: Juyoung Jung
//Date: September-19-2018
/*Purpose: In this project, the code will keep track of the record 
for the balance amount by calculating with interest rate. Depending 
on the balance amount, the interest rate varies within 3 levels. 
The result will show the final balance amount and total interest 
accrued after certain number of months. The user can request
for the monthly information of balance amount and interest rate accrued.*/

const double HIGH_INTRATE = 0.004;
const double MED_INTRATE = 0.00225;
const double LOW_INTRATE = 0.0015; 
const double HIGH_RANGE = 15000.00;
const double LOW_RANGE = 1000.00;

bool accrueInterest(
   double &balanceAmt, 
   const int numMonths,  
   const bool doPrintEachMonth);

bool accrueOneMonthsInterest(
   double &balanceAmt,
   const bool doPrintInfo);


int main()
{	
   char response; 
   int numMonths; 
   double balanceAmt; 
   bool eachMonth; //whether or not 

   //Inputs declaration
   cout << "Enter the initial balance of the account: ";
   cin >> balanceAmt;
   cout << "Enter the number of months to accrue interest: ";
   cin >> numMonths;
   cout << "Show month-by-month results - 'y' for yes, any other for no: "; 
   cin >> response;
	
   if (response == 'y')
   {
      eachMonth = true;
   }
   else
   {
      eachMonth = false; 
   }
   
   accrueInterest(balanceAmt, numMonths, eachMonth);
   
   return 0;
}


bool accrueInterest(
   double &balanceAmt, 
   const int numMonths, 
   const bool doPrintEachMonth)
{
   double initialBalance = balanceAmt;

   if (balanceAmt < 0)
   {
      cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >=0,but the value ";
      cout << balanceAmt << " was provided!" << endl;
      cout << "Sorry, an error was detected. Unable to provide results!" << endl;
      return false;
   }
   else if (numMonths <= 0)
   {
      cout << "ERROR in accrueInterest: numMonths must be >0,but the value ";
      cout << numMonths << " was provided!" << endl;
      cout << "Sorry, an error was detected. Unable to provide results!" << endl;
      return false;
   } 
   else 
   {       
      bool functionCheck = true; 
         
      for (int i = 0; i < numMonths && functionCheck == true; ++i)
      {
         functionCheck = accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
      }
      if (functionCheck == false)
      {
         return false;  
      }    
   }
   cout << "Interest accrued for " << numMonths << " months!" << endl;
   cout << "" << endl;
   cout << "Initial balance: " << initialBalance << endl;
   cout << "Total interest accrued: " << balanceAmt - initialBalance << endl;
   cout << "Final balance: " << balanceAmt << endl;
   
   return true;
}



bool accrueOneMonthsInterest(
   double &balanceAmt, 
   const bool doPrintInfo)
{
   double intRate;
   double initialBalance = balanceAmt;

   if (balanceAmt < LOW_RANGE)
   {
      intRate = LOW_INTRATE;
   }
   else if ((LOW_RANGE <= balanceAmt) && (balanceAmt < HIGH_RANGE))
   {
      intRate = MED_INTRATE;
   }
   else
   {
      intRate = HIGH_INTRATE;
   }
   
   balanceAmt = initialBalance * (1 + intRate);

   if (doPrintInfo == true)
   {
      cout << "Accruing interest for 1 month:" << endl;
      cout << " Initial balance: " << initialBalance << endl;
      cout << " Initial rate: " << intRate << endl;
      cout << " Interest accrued: " << balanceAmt - initialBalance << endl;
      cout << " New balance: " << balanceAmt << endl;
   }

   return true;
 
}