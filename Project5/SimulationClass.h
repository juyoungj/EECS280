#ifndef _SIMULATIONCLASS_H_
#define _SIMULATIONCLASS_H_

#include "SortedListClass.h"
#include "EventClass.h"
#include "FIFOQueueClass.h"
#include "Customer.h"

//Programmer: Juyoung Jung
//Date: Dec-10-2018
/*
Purpose: This SimulationClass is the class that runs the actual simulation
and stores informatin about events and customers included in the simulation.
It also reads in text file to have input values for distributions and
necessary settings for the simulation.
*/

class SimulationClass
{
    private:
        SortedListClass<EventClass> eventList;
        FIFOQueueClass<Customer> customerInfo;
        FIFOQueueClass<Customer> waitingLine; 
        EventClass currentEvent; 
        int longestLine;
        int customerNum;  
        int minArrivalTime;
        int maxArrivalTime; 
        double meanServingTime; 
        double stdServingTime;
        int openHours;
        int chanceNotToWait; 
        int excessiveLineLength;
        int eventType;
        int seedNumber;
        int closingTime;
        int customerNoWait;
        int waitedCustomer;
    public:
        //constructor initializes some attributes to zero
        SimulationClass();
        //This function schedules event that will happen in the future
        //with the input value of time and event type either arrived or served. 
        void scheduleEvent(int eventType, int currentTime);
        //This function runs simulation while removing event from the
        //event list.
        void runSimulation(string inputFileName);
        //handles event in the eventList by removingthe event from the 
        //eventlist. This function accumulates information about
        //events happening in the restaurant with customers.
        void handleEvent(int &servedStartTime);
        //reads in txt file that contains inputs for simulation
        bool readTxtInput(string inputFileName);
        //prints out statistics accumulated in the customerInfo
        void recordStatistics();

        

};
#endif