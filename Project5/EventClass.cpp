#include "EventClass.h"

//Programmer: Juyoung Jung
//Date: Dec-05-2018
/*
Purpose: The Event class contains information about the type and time of 
events happened in the restaurant. The Event class gets sorted according to
the time scheduled and listed in the eventlist which is FIFO. 
*/

//default constructor setting type and time equal to zero
EventClass::EventClass()
{
    eventTimeScheduled = 0;
    eventType = 0;
}

//default constructor setting type and time with input value
EventClass::EventClass(int inputType, int inputTime)
{
    eventType = inputType;
    eventTimeScheduled = inputTime;
}

//overloading operator helping events to be sorted in time order
bool EventClass::operator>(const EventClass &rhs) const
{
    if (eventTimeScheduled > rhs.eventTimeScheduled)
    {
        return true;
    }
    return false;
}

//overloading operator helping events to be sorted in time order
bool EventClass::operator<(const EventClass &rhs) const
{
    if (eventTimeScheduled < rhs.eventTimeScheduled)
    {
        return true;
    }
    return false;
}

//overloading operator helping events to be sorted in time order
bool EventClass::operator>=(const EventClass &rhs) const
{
    if (eventTimeScheduled >= rhs.eventTimeScheduled)
    {
        return true;
    }
    return false;
}

//gets the event time
int EventClass::getEventTimeScheduled()
{
    return eventTimeScheduled;
}

//gets the event type
int EventClass::getEventType()
{
    return eventType;
}