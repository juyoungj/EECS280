#ifndef _LIFOStackClass_H_
#define _LIFOStackClass_H_
#include "LinkedNodeClass.h"
//Programmer: Juyoung Jung
//Date: November-15-2018
/*
Purpose: This class will be used to store a simple last-in-first-out 
stack data structure.  
*/

//Class LIFOStackClass - Last in First Out Stack Data Structure
class LIFOStackClass{
    private:
        LinkedNodeClass *head;
        LinkedNodeClass *tail;
    public:
        //Default Constructor.
        //be an empty stack, to which values can be added.
        LIFOStackClass(
            );
        //Destructor. Responsible for making sure any dynamic memory 
        //associated with an object is freed up when the object is
        //being destroyed.
        ~LIFOStackClass(
            );
        //Inserts the value provided (newItem) into the stack.
        void push(
            const int &newItem
            );
        //Attempts to take the next item out of the stack. If the
        //stack is empty, the function returns false and the state
        //of the reference parameter (outItem) is undefined. If the
        //stack is not empty, the function returns true and outItem
        //becomes a copy of the next item in the stack, which is
        //removed from the data structure.
        bool pop(
            int &outItem
            );
        //Prints out the contents of the stack. All printing is done
        //on one line, using a single space to separate values, and a
        //single newline character is printed at the end.
        void print(
            ) const;
        //Returns the number of nodes contained in the stack.
        int getNumElems(
            ) const;
        //Clears the stack to an empty state without resulting in any
        //memory leaks.
        void clear(
            );
};
#endif