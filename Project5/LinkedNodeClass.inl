#include <iostream>
#include "LinkedNodeClass.h"

using namespace std;

//Programmer: Juyoung Jung
//Date: Dec-05-2018
/*
Purpose: This class will be used to store individual nodes of 
a doubly-linked data structure. 
*/

//The LinkedNodeClass will be the data type for individual nodes of
//a doubly-linked data structure.

//The ONLY constructor for the linked node class - it takes in the
//newly created node's previous pointer, value, and next pointer, and
//assigns them.
template < class T >
LinkedNodeClass< T >::LinkedNodeClass(
    LinkedNodeClass< T > *inPrev,
    const T &inVal,
    LinkedNodeClass< T > *inNext)
{
    prevNode = inPrev;
    nodeVal = inVal;
    nextNode = inNext;
}

//Returns the value stored within this node.
template < class T >
T LinkedNodeClass< T >::getValue() const
{
    return nodeVal;
}

//Returns the address of the node that follows this node.
template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getNext() const
{
    return nextNode;
}

//Returns the address of the node that comes before this node.
template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getPrev() const
{
    return prevNode;
}

//Sets the object's next node pointer to NULL.
template < class T >
void LinkedNodeClass< T >::setNextPointerToNull()
{
    nextNode = NULL;
}

//Sets the object's previous node pointer to NULL.
template < class T >
void LinkedNodeClass< T >::setPreviousPointerToNull()
{
    prevNode = NULL;
}


//This function DOES NOT modify "this" node. Instead, it uses
//the pointers contained within this node to change the previous
//and next nodes so that they point to this node appropriately.
//In other words, if "this" node is set up such that its prevNode
//pointer points to a node (call it "A"), and "this" node's
//nextNode pointer points to a node (call it "B"), then calling
//setBeforeAndAfterPointers results in the node we're calling
//"A" to be updated so its "nextNode" points to "this" node, and
//the node we're calling "B" is updated so its "prevNode" points
//to "this" node, but "this" node itself remains unchanged.
template < class T >
void LinkedNodeClass< T >::setBeforeAndAfterPointers()
{
    if (prevNode != NULL)
    {
        prevNode->nextNode = this;
    }
    if (nextNode != NULL)
    {
        nextNode->prevNode = this;
    }
}