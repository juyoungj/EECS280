#include <iostream>
using namespace std;
#include "LIFOStackClass.h"
#include "LinkedNodeClass.h"
//Programmer: Juyoung Jung
//Date: November-20-2018
/*
Purpose: This class will be used to store a simple last-in-first-out 
stack data structure.  
*/

//Class LIFOStackClass - Last in First Out Stack Data Structure
//Default Constructor.
//be an empty stack, to which values can be added.
LIFOStackClass::LIFOStackClass()
{
    head = tail = NULL;
}
//Destructor. Responsible for making sure any dynamic memory 
//associated with an object is freed up when the object is
//being destroyed.
LIFOStackClass::~LIFOStackClass()
{
    clear();
}
//Inserts the value provided (newItem) into the stack.
void LIFOStackClass::push(const int &newItem)
{
    LinkedNodeClass *newNodePtr;
    LinkedNodeClass *temp;

    if (head == NULL)
    {
        newNodePtr = new LinkedNodeClass(NULL, newItem, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
        temp = head;
        newNodePtr = new LinkedNodeClass(NULL, newItem, temp);
        head = newNodePtr;
        newNodePtr->setBeforeAndAfterPointers();
    }
}
//Attempts to take the next item out of the stack. If the
//stack is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//stack is not empty, the function returns true and outItem
//becomes a copy of the next item in the stack, which is
//removed from the data structure.
bool LIFOStackClass::pop(int &outItem)
{
    LinkedNodeClass* temp = head;
    if (head == NULL)
    {
        cout << "Stack is Empty!" << endl;
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
//Prints out the contents of the stack. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end.
void LIFOStackClass::print() const
{
    LinkedNodeClass* temp = head;
    if (head == NULL)
    {
        cout << "Stack is Empty!" << endl;
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
//Returns the number of nodes contained in the stack.
int LIFOStackClass::getNumElems() const
{
    int emptyStack = 0; //Not a magic number according to Professor Morgan
    int elementCounts = emptyStack;

    LinkedNodeClass *temp = head;

    if (temp == NULL)
    {
        return emptyStack;
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
//Clears the stack to an empty state without resulting in any
//memory leaks.
void LIFOStackClass::clear()
{
    LinkedNodeClass *iter = head;

    if (iter == NULL)
    {
        return;
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
