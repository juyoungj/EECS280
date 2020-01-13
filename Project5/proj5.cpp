#include <iostream>
#include <fstream>
using namespace std;

#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "random.h"
#include "constants.h"
#include "EventClass.h"
#include "Customer.h"
#include "SimulationClass.h"


//Programmer: Juyoung Jung
//Date: Dec-10-2018
/*
Purpose: This main function read in inputs for distributions and necessary 
settings for this simulation such as open hours for a restaurant, customers'
chance of wait, and excessive line of lenght considered, etc. The main purpose
of this function is to handle the events in the event list by calling the
handle event function and prints out statistics by calling the record 
statistics function.
*/

//RESUBMISSION - Changed the entire design of simulation!!!!!!

int main(int argc, char* argv[])
{
    if (argc < 2){
        cout << "Please add Input file: inputs.txt" << endl;
        return 1;
    }

    string inputFileName = argv[1];
    

    SimulationClass simulation;
    simulation.scheduleEvent(ARRIVED, ZEROTIME);
    simulation.runSimulation(inputFileName);

    simulation.recordStatistics();



    return 0;
}

