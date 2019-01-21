#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Iterator.h"

class List
{
public:
    List();
    ~List();
    void push_front(const int& value); // add new node to front of the list
    
    void push_back(const int& value); // add new node to back of the list
    
    void remove(const int& value); // removes ALL nodes in list with this value
    
    Iterator begin(); // iterator to the beginning of the list
    
    Iterator end(); // iterator to the end of the list
    
    int size(); // number of elements currently in list
    
    void PrintList(); // mainly for debugging
    
    
    Node* headptr;
    Node* tailptr;
    int length;
};


#endif

