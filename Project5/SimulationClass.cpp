#include "SimulationClass.h"
#include "constants.h"
#include <fstream>
#include "EventClass.h"
#include "Customer.h"
#include "FIFOQueueClass.h"
#include "random.h"
#include "SortedListClass.h"



using namespace std;


//Programmer: Juyoung Jung
//Date: Dec-10-2018
/*
Purpose: This SimulationClass is the class that runs the actual simulation
and stores informatin about events and customers included in the simulation.
It also reads in text file to have input values for distributions and
necessary settings for the simulation.
*/

//constructor initializes some attributes to zero
SimulationClass::SimulationClass()
{
    eventType = ARRIVED;
    customerNum = ZEROLABEL;
    longestLine = NOLINE; 
    customerNoWait = 0;
    waitedCustomer = 0;
}

//This function schedules event that will happen in the future
//with the input value of time and event type either arrived or served.
void SimulationClass::scheduleEvent(int eventType, int currentTime)
{
    if (eventType == ARRIVED)
    {
        EventClass customerArrival = EventClass(ARRIVED, currentTime);
        eventList.insertValue(customerArrival);
    }
    if (eventType == SERVED)
    {
        EventClass customerServed = EventClass(SERVED, currentTime);
        eventList.insertValue(customerServed);
    }
}


//This function runs simulation while removing event from the
//event list.
void SimulationClass::runSimulation(string inputFileName)
{
    if (!readTxtInput(inputFileName))
    {
        return;
    }
    setSeed(seedNumber);
    int currentTime;
    int servedStartTime;

    while(eventList.removeFront(currentEvent))
    {
        currentTime = currentEvent.getEventTimeScheduled();
        handleEvent(servedStartTime);
    }
    if (currentTime < openHours)
    {
        closingTime = openHours;
    }
    else
    {
        closingTime = currentTime;
    }
    cout << "The restaurant closed at " << closingTime << endl;
    cout << endl;
}

//handles event in the eventList by removingthe event from the 
//eventlist. This function accumulates information about
//events happening in the restaurant with customers.
void SimulationClass::handleEvent(int &servedStartTime)
{
    int eventType = currentEvent.getEventType();
    int currentTime = currentEvent.getEventTimeScheduled();


    if (eventType == ARRIVED)
    {
        //when customer arrives label increases by 1
        customerNum += 1;
        Customer nextCustomer(currentTime);
        nextCustomer.setCustomerNum(customerNum);
        cout << "Customer " << nextCustomer.getCustomerNum() 
        << " arrived at " << currentTime  << endl;
        if (waitingLine.getNumElems() != NOLINE)
        {
            //customer who is being served in included in the length of line
            cout << waitingLine.getNumElems() 
            << " customer(s) including currently being served waiting in line." 
            << endl;
            //the percentage of customers that don't like excessive line.
            int willingnessToWait = getUniform(WAITMIN, WAITMAX);
            //customers who is patient enough to wait long line.
            if (willingnessToWait > chanceNotToWait && 
                waitingLine.getNumElems() - 1 > excessiveLineLength)
            {
                waitingLine.enqueue(nextCustomer);
                waitedCustomer += 1;
                cout << "the customer is patient enough to wait even " 
                << "though line is excessively long" << endl;
            }
            //customers who don't like to wait long line
            else if (willingnessToWait <= chanceNotToWait && 
                waitingLine.getNumElems() - 1 > excessiveLineLength)
            {
                nextCustomer.setLeavingTime(currentTime);
                customerInfo.enqueue(nextCustomer);
                customerNoWait += 1;
                cout << "the customer " << nextCustomer.getCustomerNum() 
                << " is not patient. Due to excessive waiting line, "
                << "the customer decided to leave." << endl;
            }
            //when the line is short
            else
            {
                waitingLine.enqueue(nextCustomer);
                cout << "line is short so the customer " 
                << nextCustomer.getCustomerNum() << " decided to wait." 
                << endl;
                waitedCustomer += 1;
            }
        }
        //when no one is in the line waiting
        else if (waitingLine.getNumElems() == NOLINE)
        {
            cout << "no one is waiting in line, customer " 
            << nextCustomer.getCustomerNum() 
            << " will be served immediately at " << currentTime << endl;

            servedStartTime = currentTime;
            nextCustomer.setServedStartTime(servedStartTime);
            waitingLine.enqueue(nextCustomer);
            
            int servingTime = getNormal(meanServingTime, stdServingTime);
            
            
            while (servingTime <= 0)
            {
                servingTime = getNormal(meanServingTime, stdServingTime);
            }
            
            //schedule served type of event of the person who just arrived
            //because there is no one waiting
            scheduleEvent(SERVED, servedStartTime + servingTime);
            cout << nextCustomer.getCustomerNum() 
            <<" will be done served at " 
            << servedStartTime + servingTime << endl;

        }
        //customers arrival being scheduled until the closing time
        if (currentTime < openHours)  
        {
            int arrivalTime = getUniform(minArrivalTime, maxArrivalTime);
            int nextArrivalTime = currentTime + arrivalTime;
            if (nextArrivalTime < openHours)
            {
                scheduleEvent(ARRIVED, nextArrivalTime);
            }
            
        }
        cout << "there are now " << waitingLine.getNumElems() 
        << " customer(s) waiting in line including "
        << "the one currently being served" << endl;
    }
    //Served event is handled
    else if (eventType == SERVED)
    {
        cout << waitingLine.getNumElems() 
        << " customer(s) were waiting in line " 
        << "including one being served." << endl;
        //keeping track of longest line
        if (waitingLine.getNumElems() > longestLine)
        {
            longestLine = waitingLine.getNumElems();
        }
        
        Customer servedCustomer;
        waitingLine.dequeue(servedCustomer);
        servedCustomer.setServedStartTime(servedStartTime);

        cout << "server finished serving customer " 
        << servedCustomer.getCustomerNum() 
        << " ,the customer is ready to leave at " << currentTime << endl;
       
        servedCustomer.setServedFinishedTime(currentTime);
        servedCustomer.setLeavingTime(currentTime);
        customerInfo.enqueue(servedCustomer);

        

        if (waitingLine.getNumElems() == NOLINE)
        {
            cout << "no customer is waiting in line to be served." << endl;
        }
        else
        {
            
            int servingTime = getNormal(meanServingTime, stdServingTime);
            while (servingTime <= 0)
            {
                servingTime = getNormal(meanServingTime, stdServingTime);
            }
            //next customer in line served event scheduled 
            scheduleEvent(SERVED, currentTime + servingTime);
            servedStartTime = currentTime;

        }
        cout << "Now, " << waitingLine.getNumElems() 
        << " customer(s) are waiting in line inlcuding currently "
        << "being served one" << endl;
        
    }
    cout << endl;
}

//reads in txt file that contains inputs for simulation
bool SimulationClass::readTxtInput(string inputFileName)
{
    string skip;
    ifstream inputFile;
    inputFile.open(inputFileName.c_str());
    //while loop to check if the file was read properly
    bool readSuccess = false;
    while (!readSuccess)
    {
        if (inputFile.fail())
        {
            cout << "Error unable to open file: ";
            cout << inputFileName << endl;
            return false;
        }
        else
        {
            readSuccess = true;
        }
    }
    readSuccess = false;
    //read in values from the text file
    while (!readSuccess)
    {
        inputFile >> skip;
        inputFile >> minArrivalTime;
        if (inputFile.eof())
        {
            cout << "error message regarding EOF" << endl;
            return false;
        }
        
        
        inputFile >> skip;
        inputFile >> maxArrivalTime;
        
        // check if min and max values are correct
        if (minArrivalTime > maxArrivalTime)
        {
            cout << "invalid min max values" << endl;
            return false;
        }
        
        inputFile >> skip;
        inputFile >> meanServingTime;

        inputFile >> skip;
        inputFile >> stdServingTime;

        if (meanServingTime < ZEROTIME
            || stdServingTime < ZEROTIME)
        {
            cout << "invalid mean or std for serving time" << endl;
            return false;
        }

        inputFile >> skip;
        inputFile >> openHours;

        //check if closing time is less than 0
        if (openHours < ZEROTIME)
        {
            cout << "invalid openHours: " << openHours << endl;
            return false;
        }
        
        inputFile >> skip;
        inputFile >> chanceNotToWait;

        if (chanceNotToWait < WAITMIN || chanceNotToWait > WAITMAX)
        {
            cout << "customers' chance of waiting is out of range" << endl;
            return false;
        }

        inputFile >> skip;
        inputFile >> excessiveLineLength;

        if (excessiveLineLength <= NOLINE)
        {
            cout << "less than one person can't be excessiveLineLength" 
            << endl;
        }

        inputFile >> skip;
        inputFile >> seedNumber;

        readSuccess = true;
    }



    return true;
}

//prints out statistics accumulated in the customerInfo
void SimulationClass::recordStatistics()
{
    Customer customerInRecord;
    int totalNumCustomer = customerInfo.getNumElems();
    cout << "Total number customers entered a restaurant: " 
    << totalNumCustomer << endl;
    
    int servingTime;
    int busyServingTimeTotal = 0;
    int waitingTime;
    int waitingTimeTotal = 0;
    
    int longestWaitingTime = 0;
    int customerInRestaurantTime;
    
    

    while (customerInfo.dequeue(customerInRecord))
    {
        servingTime = 
        customerInRecord.getServedFinishedTime() - 
        customerInRecord.getServedStartTime(); 

        busyServingTimeTotal += servingTime;

        customerInRestaurantTime = 
        customerInRecord.getLeaveTime() - customerInRecord.getArrivalTime();
        waitingTime = customerInRecord.getServedStartTime() - 
        customerInRecord.getArrivalTime();

        if (customerInRestaurantTime != ZEROTIME)
        {
            waitingTimeTotal += waitingTime;
        }

        if (waitingTime > longestWaitingTime)
        {
            longestWaitingTime = waitingTime;
        }
    }

    cout << "time server was busy serving customer is " << busyServingTimeTotal 
    << " and totaltime is " << closingTime << endl;

    //percentage of time the server was busy helping customers
    cout << "the percentage of time the server was busy helping customers is "
    << float(busyServingTimeTotal)/closingTime * 100 << "%." << endl;

    //percentage of customers had to wait in line
    cout << "the percentage of customers had to wait in line is "
    << float(waitedCustomer)/totalNumCustomer * 100 << "%." << endl;


    //number of customers that arrived, but left due to excessive line length
    cout << "number of customers that arrived, "
    << "but left due to excessive line length is "
    << customerNoWait << endl;



    //the longest line throughout
    //average time server spent time serving per customer
    int numCustomerServed = totalNumCustomer - customerNoWait;
    cout << "average time server spent time serving per customer is "
    << busyServingTimeTotal/numCustomerServed << endl;
    //average time customers waited in line
    cout << "average time customers waited in line is " 
    << float(waitingTimeTotal)/numCustomerServed << endl;
    //longest waiting time
    cout << "longest waiting time is " << longestWaitingTime << endl;
    cout << "longest line throughout the day is " << longestLine << endl;
}