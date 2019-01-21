// File/Project Prolog
// Name: Jonathan Spalding
// CS 2420 Section 003
// Project: External Iterator
// Date: 10/3/2018
//
// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
//
// I also state that the Standard Template Library is NOT used in this project
// ---------------------------------------------------------------------------

#include "HashMap.h"

Iterator::Iterator(int index, Node **hashArray, int sizeOfArray) { 
    this->index = index;
    this->hashArray = hashArray;
    this->sizeOfArray = sizeOfArray;
    if (hashArray == nullptr) {
        current = nullptr;
    } else {
        while (hashArray[index] == nullptr) {
            index++;
        }
        current = hashArray[index];
    }
}

Iterator::Iterator() { 
}

bool Iterator::is_item() { 
    if (current != nullptr) {
        return true;
    } else {
        return false;
    }
}

std::string Iterator::operator*() { 
    return current->key;
}

void Iterator::operator++() {
    // current = current->next;
    if (current != nullptr)
    {
        current = current->next;
    }
    while (current == nullptr && index < sizeOfArray - 1)
    {
        current = hashArray[++index];
    }
}

bool Iterator::operator!=(Iterator &other) {
    if (current != nullptr)
        return true;
    else
        return false;
}
