#include "Customer.h"

//Programmer: Juyoung Jung
//Date: Dec-05-2018
/*
Purpose: The Customer class keeps track of customers' events happened 
in the restaurant such as arrival time, serving time, number of customers, 
and leave time. 
*/

//default constructor setting attributes(arrivalTime, servedStartTime, 
//leaveTime) equal to zero
Customer::Customer()
{
    arrivalTime = 0;
    servedStartTime = 0;
    leaveTime = 0;
    servedFinishedTime = 0;
}

//default constructor with setting arrivalTime with input
Customer::Customer(int inputTime)
{
    customerNum = 0;
    arrivalTime = inputTime;
    servedStartTime = 0;
    leaveTime = 0;
    servedFinishedTime = 0;
}

//sets arrivalTime with input
void Customer::setArrivalTime(int inputTime)
{
    arrivalTime = inputTime;
}

//sets serving start time with input
void Customer::setServedStartTime(int inputTime)
{
    servedStartTime = inputTime;
}

//sets serving finish time with input
void Customer::setServedFinishedTime(int inputTime)
{
    servedFinishedTime = inputTime;
}

//sets customers' leave time with input. This function is created for 
//customers who left due to excessive line length so were not being 
//served by the server
void Customer::setLeavingTime(int inputTime)
{
    leaveTime = inputTime;
}

//give labels to customers with input number according to the order customers
//arrived at the restaurant
void Customer::setCustomerNum(int inputNum)
{
    customerNum = inputNum;
}

//returns customer's arrival time
int Customer::getArrivalTime()
{
    return arrivalTime;
}

//returns customer's serving start time
int Customer::getServedStartTime()
{
    return servedStartTime;
}

//returns customer's serving finish time
int Customer::getServedFinishedTime()
{
    return servedFinishedTime;
}

//returns customer's leave time
int Customer::getLeaveTime()
{
    return leaveTime;
}

//returns number label of customer
int Customer::getCustomerNum()
{
    return customerNum;
}