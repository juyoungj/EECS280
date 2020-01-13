#include <iostream>
#include "SortedListClass.h"
#include "LinkedNodeClass.h"

using namespace std;

//Programmer: Juyoung Jung
//Date: November-20-2018
/*
Purpose: This class will be used to store a doubly-linked list in an 
always-sorted way, such that the user does not specify where in the 
list a value should be inserted, but rather the new value is inserted 
in the correct place to maintain a sorted order.
*/

//The sorted list class does not store any data directly.  Instead,
//it contains a collection of LinkedNodeClass objects, each of which
//contains one element.

//Default Constructor.  Will properly initialize a list to
//be an empty list, to which values can be added.
SortedListClass::SortedListClass()
{
    head = tail = NULL;
}

//Copy constructor.  Will make a complete (deep) copy of the list, such
//that one can be changed without affecting the other.
SortedListClass::SortedListClass(const SortedListClass &rhs)
{
    if (rhs.head == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        head = tail = NULL;

        head = new LinkedNodeClass(NULL, rhs.head->getValue(), NULL);
        LinkedNodeClass *temp = head;
        LinkedNodeClass *tempIter = rhs.head->getNext();
        
        while (tempIter != NULL)
        {
            LinkedNodeClass *newNodePtr;
            newNodePtr = new LinkedNodeClass(
                temp, 
                tempIter->getValue(), 
                NULL);
            newNodePtr->setBeforeAndAfterPointers();
            temp = temp->getNext();
            tempIter = tempIter->getNext();
        }
        tail = temp; 
    }
}

//Destructor. Responsible for making sure any dynamic memory
//associated with an object is freed up when the object is 
//being destroyed
SortedListClass::~SortedListClass()
{
    clear();
}

//Clears the list to an empty state without resulting in any
//memory leaks.
void SortedListClass::clear()
{
    LinkedNodeClass *iter = head;

    if (iter == NULL)
    {
        cout << "List is already Empty!" << endl;
    }
    else
    {
        while (iter != NULL)
        {
            LinkedNodeClass *temp = iter;
            iter = iter->getNext();
            delete temp;
        }
        head = tail = NULL;
    }
}

//Allows the user to insert a value into the list.  Since this
//is a sorted list, there is no need to specify where in the list
//to insert the element.  It will insert it in the appropriate
//location based on the value being inserted.  If the node value
//being inserted is found to be "equal to" one or more node values
//already in the list, the newly inserted node will be placed AFTER
//the previously inserted nodes
void SortedListClass::insertValue(const int &valToInsert)
{
    const int EMPTY_LIST = 0;
    const int ONE_ELEM = 1;
    const int TWO_ELEM = 2; 
    //Not Supposed to Change or Add class, so I made local constant variables.

    LinkedNodeClass *newNodePtr;
    LinkedNodeClass *temp = NULL;     

    int numElements = getNumElems();

    if (numElements == EMPTY_LIST)
    {
        newNodePtr = new LinkedNodeClass(NULL, valToInsert, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else if (numElements == ONE_ELEM)
    {
        temp = head;
        if (valToInsert < temp->getValue())
        {
            newNodePtr = new LinkedNodeClass(NULL, valToInsert, temp);
            head = newNodePtr;
            newNodePtr->setBeforeAndAfterPointers();
        }
        else if (valToInsert >= temp->getValue())
        {
            newNodePtr = new LinkedNodeClass(temp, valToInsert, NULL);
            tail = newNodePtr;
            newNodePtr->setBeforeAndAfterPointers();
        }
    }
    else if (numElements >= TWO_ELEM)
    {
        if (valToInsert < head->getValue())
        {
            temp = head;
            newNodePtr = new LinkedNodeClass(NULL, valToInsert, temp);
            head = newNodePtr;
            newNodePtr->setBeforeAndAfterPointers();
        }
        else if (valToInsert > tail->getValue())
        {
            temp = tail;
            newNodePtr = new LinkedNodeClass(temp, valToInsert, NULL);
            tail = newNodePtr;
            newNodePtr->setBeforeAndAfterPointers();
        }
        else
        {
            temp = head;
            while (valToInsert >= temp->getValue())
            {
                temp = temp->getNext();
            }
            newNodePtr = 
            new LinkedNodeClass(temp->getPrev(), valToInsert, temp);
            newNodePtr->setBeforeAndAfterPointers();
        }

    }
}

//Prints the contents of the list from head to tail to the screen.
//Begins with a line reading "Forward List Contents Follow:", then
//prints one list element per line, indented two spaces, then prints
//the line "End Of List Contents" to indicate the end of the list.
void SortedListClass::printForward() const
{
    LinkedNodeClass *temp = head;

    if (temp  == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        cout << "Forward List Contents Follow:" << endl;
        while (temp != NULL)
        {
            cout << "  ";
            cout << temp->getValue() << endl;
            temp = temp->getNext();
        }
        cout << "End of List Contents" << endl;
    }
}

//Prints the contents of the list from tail to head to the screen.
//Begins with a line reading "Backward List Contents Follow:", then
//prints one list element per line, indented two spaces, then prints
//the line "End Of List Contents" to indicate the end of the list.
void SortedListClass::printBackward() const
{
    LinkedNodeClass *temp = tail;

    if (temp == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        cout << "Backward List Contents Follow:" << endl;
        while (temp != NULL)
        {
            cout << "  ";
            cout << temp->getValue() << endl;
            temp = temp->getPrev();
        }
        cout << "End of List Contents" << endl;
    }
}

//Removes the front item from the list and returns the value that
//was contained in it via the reference parameter.  If the list
//was empty, the function returns false to indicate failure, and
//the contents of the reference parameter upon return is undefined.
//If the list was not empty and the first item was successfully
//removed, true is returned, and the reference parameter will
//be set to the item that was removed.
bool SortedListClass::removeFront(int &theVal)
{
    LinkedNodeClass *temp = head;

    if (head == NULL)
    {
        cout << "Can not delete from the empty list!" << endl;
        return false; 
    }
    
    //RESUBMISSION - fix segmentation fault problem by considering
    //the case when removing the last element.
    head = temp->getNext();
    theVal = temp->getValue();
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

//Removes the last item from the list and returns the value that
//was contained in it via the reference parameter.  If the list
//was empty, the function returns false to indicate failure, and
//the contents of the reference parameter upon return is undefined.
//If the list was not empty and the last item was successfully
//removed, true is returned, and the reference parameter will
//be set to the item that was removed.
bool SortedListClass::removeLast(int &theVal)
{
    LinkedNodeClass *temp = tail;

    if (tail == NULL)
    {
        cout << "Can not delete from the empty list!" << endl;
        return false;
    }
    
    //RESUBMISSION - fix segmentation fault problem by considering
    //the case when removing the last element.
    tail = temp->getPrev();
    theVal = temp->getValue();
    delete temp;
    
    if (tail != NULL)
    {
        tail->setNextPointerToNull();
    }
    else
    {
        head = NULL;
    }
    return true;
}

//Returns the number of nodes contained in the list.
int SortedListClass::getNumElems() const
{
    int emptyList = 0; //Not a magic number according to Professor Morgan
    int elementCounts = emptyList;

    LinkedNodeClass *temp = head;

    if (temp == NULL)
    {
        return emptyList;
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

//Provides the value stored in the node at index provided in the
//0-based "index" parameter. If the index is out of range, then outVal
//remains unchanged and false is returned.  Otherwise, the function
//returns true, and the reference parameter outVal will contain
//a copy of the value at that location.
bool SortedListClass::getElemAtIndex(
    const int index,
    int &outVal
    ) const
{
    const int ZERO_INDEX = 0;
    LinkedNodeClass *temp = head;

    int numElements = getNumElems();

    if (temp == NULL)
    {
        cout << "List is Empty!" << endl;
        return false;
    }
    //RESUBMISSION - change > to >= since list is 0-based index
    else if (index < ZERO_INDEX || index >= numElements)
    {
        cout << "Index out of range!" << endl;
        return false;
    }
    else
    {
        int numOfList = 0; //Not a magic number according to Professor Morgan

        while (numOfList != index)
        {
            temp = temp->getNext();
            numOfList++;
        }

        outVal = temp->getValue();
        return true;
    }
}