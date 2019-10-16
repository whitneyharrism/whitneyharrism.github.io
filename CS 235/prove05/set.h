/***********************************************************************
* Program:
*    Assignment 01, set
*    Brother Jones, CS 235
* Author:
*    David Hendricks
* Summary:
*    This file contains a custom set and set iterator.
*    No code was used without understanding what it was doing.
************************************************************************/
#ifndef set_set_H
#define set_set_H

#include "assert.h"

// Declaration for iterator
template <class T>
class iterator;

#include <iostream>

namespace custom
{

template <class T>
class set
{
private:
    int numElements;
    int numCapacity;
    T *array;

public:
    set();
    set(int numCapacity);
    set(set &rhs);
    ~set();
    set &operator=(set &rhs);
    int size();
    bool empty();
    void clear();
    iterator find(T &t);
    void insert(T& t);
    iterator erase(iterator& t);
    iterator begin();
    iterator end();
    int findIndex(T& t);
    void resize(int numCapacity);
    //set union(set& rhs)
    //set intersection(set& rhs)
    //set difference(set& rhs)

};
} // namespace custom
#endif
