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

#ifndef __NODE__
#define __NODE__

#include <string>

class Node
{
public:
    Node()
    {
        value = 0;
    }
    Node(std::string input)
    {
        key = input;
        value = 1;
        next = nullptr;
    }
    Node(std::string input, int count)
    {
        key = input;
        this->value = count;
        next = nullptr;
    }
    Node(std::string input, int count, Node *next)
    {
        key = input;
        this->value = count;
        this->next = next;
    }
    ~Node() = default; // really nothing to destruct
    
    Node *next;
    std::string key;    // this is the "word"
    unsigned int value;    // this is the "count"
};

#endif // !__NODE__
