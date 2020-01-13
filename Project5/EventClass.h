#ifndef _EVENTCLASS_H_
#define _EVENTCLASS_H_

//Programmer: Juyoung Jung
//Date: Dec-05-2018
/*
Purpose: The Event class contains information about the type and time of 
events happened in the restaurant. The Event class gets sorted according to
the time scheduled and listed in the eventlist which is FIFO. 
*/

class EventClass
{
    private:
        //the type of the event: Arrived or Served
        int eventType;
        //the time of the event scheduled
        int eventTimeScheduled;
    public:
        //default constructor setting type and time equal to zero
        EventClass();
        //default constructor setting type and time with input value
        EventClass(int inputType, int inputTime);
        //overloading operator helping events to be sorted in time order
        bool operator>(const EventClass &rhs) const;
        //overloading operator helping events to be sorted in time order
        bool operator<(const EventClass &rhs) const;
        //overloading operator helping events to be sorted in time order
        bool operator>=(const EventClass &rhs) const;
        //gets the event time
        int getEventTimeScheduled();
        //gets the event type
        int getEventType(); 
};
#endif