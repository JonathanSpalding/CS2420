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
#ifndef Graph_h
#define Graph_h
#include "Node.h"
#include <stdio.h>
#include <vector>

using namespace std;

class Graph
{
public:
    vector<Node> verts;
    Graph();
    void AddEdge(string source, string target, int weight);
    void AddVertex(string label);
    bool IsEdge(int sourceIndex, int targetIndex);
    int GetWeight(int sourceIndex, int targetIndex);
    void BreadthFirstSearch(string startingVertex);
    void DijkstraShortedPath(string startingVertex);
    void PrintGraph();
    int FindIndex(const string &label);
    bool beenVisitedFunction();
    int PopMin();

private:
    const static int MAX_VERTICES = 10;
    bool matrix[6][6];
    int Weight[6][6];
    int numVertices;
    string labels[6];

};

#endif
