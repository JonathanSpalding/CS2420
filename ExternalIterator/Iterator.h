#pragma once
#include <cassert>
#include "Node.h"

using namespace std;

class Iterator
{
public:
    Node* itr;
    Iterator(Node *start);// The iterator initially points to “start”.
    
    int operator*(); // dereference the iterator
    
    void operator++(); // advance the iterator
    
    bool operator!=(Iterator& other); // returns true if and only if other iterator does not equal this iterator
    
    bool is_item(); // returns true if Iterator points to a valid Node (if nullptr return false…)
};
