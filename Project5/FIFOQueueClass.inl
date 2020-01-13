#include <iostream>
using namespace std;
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"


//Programmer: Juyoung Jung
//Date: December-05-2018
/*
Purpose: This class will be used to store a simple first-in-first-out 
queue data structure. 
*/

//Default Constructor.  Will properly initialize a queue to
//be an empty queue, to which values can be added.
template < class T >
FIFOQueueClass< T >::FIFOQueueClass()
{
    head = tail = NULL;
}

//Destructor. Responsible for making sure any dynamic memory
//associated with an object is freed up when the object is
//being destroyed.
template < class T >
FIFOQueueClass< T >::~FIFOQueueClass()
{
    clear();
}
//Inserts the value provided (newItem) into the queue.
template < class T >
void FIFOQueueClass< T >::enqueue(const T &newItem)
{
    LinkedNodeClass< T > *newNodePtr;
    LinkedNodeClass< T > *temp;

    if (head == NULL)
    {
        newNodePtr = new LinkedNodeClass< T >(NULL, newItem, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
        temp = tail;
        newNodePtr = new LinkedNodeClass< T >(temp, newItem, NULL); 
        tail = newNodePtr;
        newNodePtr->setBeforeAndAfterPointers();
    }
}

//Attempts to take the next item out of the queue. If the
//queue is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//queue is not empty, the function returns true and outItem
//becomes a copy of the next item in the queue, which is
//removed from the data structure.
template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
    LinkedNodeClass< T >* temp = head;
    if (head == NULL)
    {
        // cout << "Queue is Empty!" << endl;
        return false;
    }

    //RESUBMISSION - fix segmentation fault problem by considering
    //the case when removing the last element.
    head = temp->getNext();
    outItem = temp->getValue();
    delete temp;
    if (head != NULL)
    {
        head->setPreviousPointerToNull();
    }
    else
    {
        tail = NULL;
    }
    return true;
}  
//Prints out the contents of the queue. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end.
template < class T >
void FIFOQueueClass< T >::print() const
{
    LinkedNodeClass< T >* temp = head;
    if (head == NULL)
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->getValue() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
}
//Returns the number of nodes contained in the queue.
template < class T >
int FIFOQueueClass< T >::getNumElems() const
{  
    int emptyQueue = 0; //Not a magic number according to Professor Morgan
    int elementCounts = emptyQueue;

    LinkedNodeClass< T > *temp = head;

    if (temp == NULL)
    {
        return emptyQueue;
    }
    else
    {
        while (temp != NULL)
        {
            elementCounts++;
            temp = temp->getNext();
        }
        return elementCounts;
    }
    
}
//Clears the queue to an empty state without resulting in any
//memory leaks.
template < class T >
void FIFOQueueClass< T >::clear()
{
    LinkedNodeClass< T > *iter = head;

    if (iter == NULL)
    {
        return;
    }
    else
    {
        while (iter != NULL)
        {
            LinkedNodeClass< T > *temp = iter;
            iter = iter->getNext();
            delete temp;
        }
        head = tail = NULL;
    }
}