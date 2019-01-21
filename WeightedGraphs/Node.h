// File/Project Prolog
// Name: Jonathan Spalding
// CS 2420 Section 003
// Project: Weighted Graphs
// Date: 12/1/2018
//
// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
//
// I also state that the Standard Template Library is NOT used in this project
// ---------------------------------------------------------------------------
#pragma once
#include <climits>
#include <string>

using namespace std;

class Node
{
public:
    Node();
    Node(string label);
    string label;
    int distance;
    int previousVert;
    bool beenVisited;
};
