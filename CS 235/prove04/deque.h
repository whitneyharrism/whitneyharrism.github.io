#ifndef deque_H
#define deque_H

#include "assert.h"

#include <iostream>
// using namespace std;
namespace custom
{

template <class T>
class deque
{
    // Private member variables
private:
    T *array;        // dynamically allocate array of T
    int iBack;     //Back
    int iFront;      //Front
    int numCapacity; // Capacity
    void resize(int size) throw(const char *);
    int iBackNormalized() const { return (iBack - 1) % numCapacity; }
    int iFrontNormalized() const { return iFront % numCapacity; }

public:
    deque();                                                //Default Constructor
    deque(int capacity) throw(const char *);                // non-default constructor
    deque(deque<T> &rhs) throw(const char *);               //Copy Constructor
    deque<T> &operator=(deque<T> &rhs) throw(const char *); //assignment

    ~deque();                                        //Deconstructor
    int capacity() const { return numCapacity; }     // return the maximum number of elements
    int size() const { return iBack - iFront + 1; }    // return the current number of elements
    bool empty() const { return iBack == iFront; } // return true if push and pop are the same meani\
ng the array is empty
    void clear() { iFront = 0; iBack = -1; }               // set the number of elements (not capacity) to ze\
ro
    void push_front(const T &t) throw(const char *);       //push onto the front
    void pop_front() throw(const char *);                  // Gets The value from the top
    void push_back(const T &t) throw(const char *);       //push onto the front
    void pop_back() throw(const char *);                  // Gets The value from the top
    T &back() throw(const char *);                   // gets the back value
    T &front() throw(const char *);                  //Gets the value from the front
};

/**********************************************************************
* deqUE :: Default constructor
*  setting initial capacity and elements to zero
**********************************************************************/
template <class T>
deque<T>::deque()
{
    array = NULL;
    iFront = 0;
    iBack = 0;
    numCapacity = 0;
}

/**********************************************************************
* deqUE :: Copy Constructor
*  Copy an existing deque
**********************************************************************/
template <class T>
deque<T>::deque(deque<T> &rhs) throw(const char *) : deque()
{

    numCapacity = rhs.numCapacity;
    iFront = rhs.iFront;
    iBack = rhs.iBack;

    array = new T[numCapacity];
    for (int i = 0; i < numCapacity; i++)
    {
        array[i] = rhs.array[i];
    }
}

/**********************************************************************
* deqUE :: Destructor
*  just frees the private array
**********************************************************************/
template <class T>
deque<T>::~deque()
{
    if (array)
    {
        delete[] array;
    }
}

/**********************************************************************
* deqUE :: Non-Default Constructor
* If there is insufficient memory to allocate a new buffer
**********************************************************************/
template <class T>
deque<T>::deque(int capacity) throw(const char *) : deque()
{
    if (capacity <= 0)
        throw "ERROR: Unable to allocate a new buffer for deque";
    resize(capacity);
}

/**********************************************************************
* deqUE :: Assignment
*  Copy an existing deque overwite existing deque
**********************************************************************/
template <class T>
deque<T> &deque<T>::operator=(deque<T> &rhs) throw(const char *)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (capacity() < rhs.size())
    {
        resize(rhs.size());
    }
    iBack = rhs.size();
    iFront = 0;
    for (int i = 0; i < rhs.size(); i++)
    {
        array[i] = rhs.array[(i + rhs.iFront) % rhs.numCapacity];
    }
    return *this;
}

/****************************************************************
 * deqUE :: Push Front
 * Add the value to the front of the deque
 ****************************************************************/
template <class T>
void deque<T>::push_front(const T &t) throw(const char *)
{
    if (size() >= capacity())
        resize(capacity() * 2);
    iFront--;
    array[iFrontNormalized()] = t;
}

/****************************************************************
 * deqUE :: Push Back
 * Add the value to the back of the deque
 ****************************************************************/
template <class T>
void deque<T>::push_back(const T &t) throw(const char *)
{
    if (size() >= capacity())
        resize(capacity() * 2);
    iBack++;
    array[iBackNormalized()] = t;
}

/****************************************************************
* deqUE :: Pop Front
* Removes the first Item on the deque
****************************************************************/
template <class T>
void deque<T>::pop_front() throw(const char *)
{
    // if deque is not empty, pop off first element
    if (!empty())
    {
        iFront++;
    }
}

/****************************************************************
* deqUE :: Pop Back
* Removes the last Item on the deque
****************************************************************/
template <class T>
void deque<T>::pop_back() throw(const char *)
{
    // if deque is not empty, pop off first element
    if (!empty())
    {
        iBack--;
    }
}

/****************************************************************
* deqUE :: BACK
* Get the value at the back of the deque
****************************************************************/
template <class T>
T &deque<T>::back() throw(const char *)
{
    if (this->empty())
    {
        throw "ERROR: attempting to access an element in an empty deque";
    }

    return array[iBackNormalized()];
}

/****************************************************************
* deqUE :: Front
* Get the value at the front of the deque
****************************************************************/
template <class T>
T &deque<T>::front() throw(const char *)
{
    if (this->empty())
    {
        throw "ERROR: attempting to access an element in an empty deque";
    }
    return array[iFrontNormalized()];
}

/*********************************************************
* deqUE :: RESIZE
* Grow the size of the deque to (at a minimum) of a given
* size. If the size is set to zero, then the capacity will
* be doubled. If the stack is currently not empty, the contents
* will be copied over to the new buffer
*********************************************************/
template <class T>
void deque<T>::resize(int newCapacity) throw(const char *)
{
    assert(newCapacity >= 0);

    // determine the new buffer size
    if (newCapacity == 0)
        newCapacity = (numCapacity != 0 ? numCapacity * 2 : 1);

    // allocate the new buffer
    T *newData = new (std::nothrow) T[newCapacity];
    if (NULL == newData)
        throw "ERROR: Unable to allocate a new buffer for deque";

    // copy the array
    int iDestination = 0;
    for (int iSource = iFront; iSource < iBack; iSource++)
        newData[iDestination++] = array[iSource % numCapacity];

    // set the new capacity, iBack, and iFront
    numCapacity = newCapacity;
    iFront = 0;
    iBack = iDestination;

    // free the old
    if (NULL != array)
        delete[] array;
    array = newData;
}

} // namespace custom

#endif // deque_H