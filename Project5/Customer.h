#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

//Programmer: Juyoung Jung
//Date: Dec-05-2018
/*
Purpose: The Customer class keeps track of customers' events happened 
in the restaurant such as arrival time, serving time, number of customers, 
and leave time. 
*/

//Customer class represents customers
class Customer
{
    private:
        //number labels for customers according to the arrival order
        int customerNum;
        //customers' arrive time
        int arrivalTime;
        //customers' serving start time
        int servedStartTime;
        //customers' serving finish time
        int servedFinishedTime;
        //customers' leave time
        int leaveTime;

    public:
        //constructor setting attributes(arrivalTime, servedStartTime, 
        //leaveTime) equal to zero 
        Customer();
        //constructor with setting arrivalTime with input
        Customer(int inputTime);
        //sets arrivalTime with input
        void setArrivalTime(int inputTime);
        //sets serving start time with input
        void setServedStartTime(int inputTime);
        //sets serving finish time with input
        void setServedFinishedTime(int inputTime);
        //sets customers' leave time with input. This function is created for 
        //customers who left due to excessive line length so were not being 
        //served by the server
        void setLeavingTime(int inputTime);
        //labels customers with input number according to the order customers
        //arrived at the restaurant
        void setCustomerNum(int inputNum);
        //returns customer's arrival time
        int getArrivalTime();
        //returns customer's serving start time 
        int getServedStartTime();
        //returns customer's serving finish time
        int getServedFinishedTime();
        //returns customer's leave time
        int getLeaveTime();
        //returns number label of customer
        int getCustomerNum();

};

#endif