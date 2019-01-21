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
#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph g;
    
    g.AddVertex("A");
    g.AddVertex("B");
    g.AddVertex("C");
    g.AddVertex("D");
    g.AddVertex("E");
    g.AddVertex("F");
    
    g.AddEdge("A", "B", 2);
    g.AddEdge("A", "F", 9);
    
    g.AddEdge("B", "F", 6);
    g.AddEdge("B", "D", 15);
    g.AddEdge("B", "C", 8);
    
    g.AddEdge("C", "D", 1);
    
    g.AddEdge("E", "C", 7);
    g.AddEdge("E", "D", 3);
    
    g.AddEdge("F", "E", 3);
    
    g.PrintGraph();
    
    g.BreadthFirstSearch("A");
    
    g.DijkstraShortedPath("A");
    g.DijkstraShortedPath("B");
    g.DijkstraShortedPath("C");
    g.DijkstraShortedPath("D");
    g.DijkstraShortedPath("E");
    g.DijkstraShortedPath("F");
    
    
    cout << "Press [Enter] to exit  ";
    getchar();
}
