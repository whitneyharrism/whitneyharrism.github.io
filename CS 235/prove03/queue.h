/***********************************************************************
* Program:
*    Assignment 02, queue
*    Brother Jones, CS 235
* Author:
*
* Summary:
*    This file contains a custom queue.
*    No code was used without understanding what it was doing.
************************************************************************/
#ifndef queue_H
#define queue_H

#include "assert.h"

#include <iostream>
// using namespace std;
namespace custom
{

template <class T>
class queue
{
    // Private member variables
private:
    T *array;        // dynamically allocate array of T
    int numPush;     //Back
    int numPop;      //Front
    int numCapacity; // Capacity
    void resize(int size) throw(const char *);
    ;
    int iTail() const { return (numPush - 1) % numCapacity; }
    int iHead() const { return numPop % numCapacity; }

public:
    queue();                                                //Default Constructor
    queue(int capacity) throw(const char *);                // non-default constructor
    queue(queue<T> &rhs) throw(const char *);               //Copy Constructor
    queue<T> &operator=(queue<T> &rhs) throw(const char *); //assignment

    ~queue();                                        //Deconstructor
    int capacity() const { return numCapacity; }     // return the maximum number of elements
    int size() const { return numPush - numPop; }    // return the current number of elements
    bool empty() const { return numPush == numPop; } // return true if push and pop are the same meani\
ng the array is empty
    void clear() { numPush = numPop; }               // set the number of elements (not capacity) to ze\
ro
    void push(const T &t) throw(const char *);       //push
    T &back() throw(const char *);                   // gets the back value
    T &front() throw(const char *);                  //Gets the value from the front
    void pop() throw(const char *);                  // Gets The value from the top
};

/**********************************************************************
* QUEUE :: Default constructor
*  setting initial capacity and elements to zero
**********************************************************************/
template <class T>
queue<T>::queue()
{
    array = NULL;
    numPop = 0;
    numPush = 0;
    numCapacity = 0;
}

/**********************************************************************
* QUEUE :: Copy Constructor
*  Copy an existing queue
**********************************************************************/
template <class T>
queue<T>::queue(queue<T> &rhs) throw(const char *) : queue()
{

    numCapacity = rhs.numCapacity;
    numPop = rhs.numPop;
    numPush = rhs.numPush;

    array = new T[numCapacity];
    for (int i = 0; i < numCapacity; i++)
    {
        array[i] = rhs.array[i];
    }
}

/**********************************************************************
* QUEUE :: Destructor
*  just frees the private array
**********************************************************************/
template <class T>
queue<T>::~queue()
{
    if (array)
    {
        delete[] array;
    }
}

/**********************************************************************
* QUEUE :: Non-Default Constructor
* If there is insufficient memory to allocate a new buffer
**********************************************************************/
template <class T>
queue<T>::queue(int capacity) throw(const char *) : queue()
{
    if (capacity <= 0)
        throw "ERROR: Unable to allocate a new buffer for queue";
    resize(capacity);
}

/**********************************************************************
* QUEUE :: Assignment
*  Copy an existing queue overwite existing queue
**********************************************************************/
template <class T>
queue<T> &queue<T>::operator=(queue<T> &rhs) throw(const char *)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (capacity() < rhs.size())
    {
        resize(rhs.size());
    }
    numPush = rhs.size();
    numPop = 0;
    for (int i = 0; i < rhs.size(); i++)
    {
        array[i] = rhs.array[(i + rhs.numPop) % rhs.numCapacity];
    }
    return *this;
}

/****************************************************************
 * QUEUE :: Push
 * Add the value to the back of the queue
 ****************************************************************/
template <class T>
void queue<T>::push(const T &t) throw(const char *)
{
    if (size() >= capacity())
        resize(capacity() * 2);
    numPush++;
    array[iTail()] = t;
}

/****************************************************************
* QUEUE :: Pop
* Removes the first Item on the queue
****************************************************************/
template <class T>
void queue<T>::pop() throw(const char *)
{
    // if queue is not empty, pop off first element
    if (!empty())
    {
        numPop++;
    }
}

/****************************************************************
* QUEUE :: BACK
* Get the value at the back of the queue
****************************************************************/
template <class T>
T &queue<T>::back() throw(const char *)
{
    if (this->empty())
    {
        throw "ERROR: attempting to access an element in an empty queue";
    }

    return array[iTail()];
}

/****************************************************************
* QUEUE :: Front
* Get the value at the front of the queue
****************************************************************/
template <class T>
T &queue<T>::front() throw(const char *)
{
    if (this->empty())
    {
        throw "ERROR: attempting to access an element in an empty queue";
    }
    return array[iHead()];
}

/*********************************************************
* QUEUE :: RESIZE
* Grow the size of the queue to (at a minimum) of a given
* size. If the size is set to zero, then the capacity will
* be doubled. If the stack is currently not empty, the contents
* will be copied over to the new buffer
*********************************************************/
template <class T>
void queue<T>::resize(int newCapacity) throw(const char *)
{
    assert(newCapacity >= 0);

    // determine the new buffer size
    if (newCapacity == 0)
        newCapacity = (numCapacity != 0 ? numCapacity * 2 : 1);

    // allocate the new buffer
    T *newData = new (std::nothrow) T[newCapacity];
    if (NULL == newData)
        throw "ERROR: Unable to allocate a new buffer for queue";

    // copy the array
    int iDestination = 0;
    for (int iSource = numPop; iSource < numPush; iSource++)
        newData[iDestination++] = array[iSource % numCapacity];

    // set the new capacity, numPush, and numPop
    numCapacity = newCapacity;
    numPop = 0;
    numPush = iDestination;

    // free the old
    if (NULL != array)
        delete[] array;
    array = newData;
}

} // namespace custom

#endif // queue_H
