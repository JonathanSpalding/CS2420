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

HashMap::HashMap(int size) {
    hashArray = new Node*[size];
    sizeOfArray = size;
    for (int i = 0; i < size; i++)
    {
        hashArray[i] = nullptr;
    }
}

HashMap::~HashMap() {
    Node* toBeDeleted;
    for (int i = 0; i < sizeOfArray; i++)
    {
        toBeDeleted = hashArray[i];
        while (toBeDeleted != nullptr)
        {
            toBeDeleted = toBeDeleted->next;
        }
        if (toBeDeleted == nullptr)
        {
            delete toBeDeleted;
        }
    }
}

bool HashMap::IsKeyPresent(const std::string &key) const { // return true if key is in map
    int destinationIndex = GenerateHash(key);
    if (hashArray[destinationIndex] != nullptr) {
        Node*temp = hashArray[destinationIndex];
        while (temp != nullptr) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    } else {
        return false;
    }
}

void HashMap::SetKeyValue(const std::string &key, int value) { // if key is not present, add to map and then set value
    int destinationIndex = GenerateHash(key);
    
    if (IsKeyPresent(key))
    {
        Node* currSpot = hashArray[destinationIndex];
        while (currSpot->key != key)
        {
            currSpot = currSpot->next;
        }
        currSpot->value = value;
    }
    else
    {
        hashArray[destinationIndex] = new Node(key, value, hashArray[destinationIndex]);
    }
}

// NOTE: GetKeyValue() returns a bool (true if the key was present in the map) and it ALSO "returns"
// the value of that key through the parameter "value". Notice that "value" is a "pass by reference" parameter
bool HashMap::GetKeyValue(const std::string &key, int &value) { // if key is not present, return false
    int destinationIndex = GenerateHash(key);
    Node*currSpot = hashArray[destinationIndex];
    if (IsKeyPresent(key))
    {
        while (currSpot != nullptr)
        {
            if (currSpot->key == key)
            {
                value = currSpot->value;
            }
            currSpot = currSpot->next;
        }
        return false;
    }
    else
    {
        return false;
    }
}

int HashMap::GenerateHash(std::string key) const { // converts the key to an value used to index into the array
    //"Where the magic happens."
    int total = 0;
    for (int i = 0; i < key.size(); i++)
    {
        total += key[i];
        total *= 2; //This is supposed to separate the difference between things like tab and bat.
    }
    return total % sizeOfArray;
}

Iterator HashMap::begin() {
    return Iterator(0, hashArray, sizeOfArray);
}

Iterator HashMap::end() {
    return Iterator(sizeOfArray, nullptr, sizeOfArray);
}
