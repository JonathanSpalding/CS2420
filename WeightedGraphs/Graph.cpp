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
#include <cassert>
#include <stack>
#include <unordered_set>
#include <climits>
#include <queue>
#include <unordered_set>
#include "Node.h"
#include "Graph.h"

using namespace std;

Graph::Graph()
{
    for (int from = 0; from < 6; from++) {
        for (int to = 0; to < 6; to++) {
            matrix[from][to] = false;
            //Weight[from][to] = 0;
        }
    }
    numVertices = 0;
}

void Graph::AddEdge(string source, string target, int weight)
{
    matrix[FindIndex(source)][FindIndex(target)] = true;
    Weight[FindIndex(source)][FindIndex(target)] = weight;
}

bool Graph::IsEdge(int sourceIndex, int targetIndex)
{
    if (matrix[sourceIndex][targetIndex] == true) {
        return true;
    } else {
        return false;
    }
}

int Graph::GetWeight(int sourceIndex, int targetIndex)
{
    return Weight[sourceIndex][targetIndex];
}

void Graph::BreadthFirstSearch(string startingVertex)
{
    queue <int> whereImAt;
    unordered_set <int> set;
    int startingV = FindIndex(startingVertex);
    int currentVertex;
    int adjecentVertex;
    whereImAt.push(startingV);
    set.insert(startingV);
    cout << "Starting BFS with vertex A" << endl;
    while (!whereImAt.empty()) {
        //curv = queue front
        currentVertex = whereImAt.front();
        whereImAt.pop();
        //start = curv;
        startingV = currentVertex;
        verts.at(currentVertex).beenVisited = true;
        cout << "\t\t" << "visited " << verts.at(currentVertex).label << endl;
        for (int i = 0; i < verts.size(); i++) {
            if (IsEdge(startingV, i)) {
                adjecentVertex = i;
                if (set.count(adjecentVertex) == 0) { //sees if it is in the set or not.
                    whereImAt.push(adjecentVertex);
                    set.insert(adjecentVertex); // add to set
                }
            }
        }
    }
}

void Graph::AddVertex(string label)
{
    verts.push_back(Node(label));
    numVertices++;
}

void Graph::PrintGraph()
{
    cout << "numVerticies: " << numVertices << endl;
    cout << "\t\t";
    for (int i = 0; i < numVertices; i++) {
        cout << verts.at(i).label << "\t\t";
    }
    cout << endl;
    
    for (int from = 0; from < numVertices; from++) {
        cout << verts.at(from).label;
        for (int to = 0; to < numVertices; to++) {
            if (matrix[from][to] == true) {
                cout << "\t\t" << GetWeight(from, to);
            } else {
                cout << "\t\t ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int Graph::FindIndex(const string & label)
{
    for (int i = 0; i < numVertices; i++) {
        if (verts.at(i).label == label)
            return i;
    }
    return -1;
}

void Graph::DijkstraShortedPath(string startingVertex)
{
    int startingV = FindIndex(startingVertex);
    
    cout << "Shortest Distance starting from vertex " << startingVertex << endl;
    
    for (int i = 0; i < verts.size(); ++i) {
        verts.at(i).distance = 1000000; // had to change this to a really big number because INT_MAX got messed up after being incremented.
        verts.at(i).previousVert = -1;
        verts.at(i).beenVisited = false;
    }
    
    verts.at(startingV).distance = 0;
    
    while (beenVisitedFunction() == false) {
        int currentVertex = PopMin();
        
        for (int i = 0; i < verts.size(); i++) {
            if (IsEdge(currentVertex, i)) {
                int edgeWeight = Weight[currentVertex][i];
                int altPath = edgeWeight + verts.at(currentVertex).distance;
                if (verts.at(i).distance > altPath) {
                    verts.at(i).distance = altPath;
                    verts.at(i).previousVert = currentVertex;
                }
            }
        }
    }
    for (int i = 0; i < verts.size(); i++) {
        cout << "\t\t" << "To: " << verts.at(i).label << "\t";
        int previousVertex = i;
        
        if (verts.at(i).distance < 1000000) { // had to change from INT_MAX to 1000000 (Really big number representing infinite) because it was getting messed up.
            cout << verts.at(i).distance << "\t\t" << "Path: ";
            while (previousVertex != -1) {
                cout << verts.at(previousVertex).label;
                if (verts.at(previousVertex).previousVert != -1) {
                    cout << ", ";
                }
                previousVertex = verts.at(previousVertex).previousVert;
            }
            cout << endl;
        } else {
            cout << "No Path" << endl;
        }
    }
    cout << endl;
}

bool Graph::beenVisitedFunction()
{
    for (int i = 0; i < verts.size() - 1; i++) {
        if (verts.at(i).beenVisited == false) {
            return verts.at(i).beenVisited;
        }
    }
    return true;
}

int Graph::PopMin()
{
    int min = -1;
    for (int i = 0; i < verts.size(); ++i) {
        if (verts.at(i).beenVisited == false && min == -1) {
            min = i;
        }
        if (min != -1 && verts.at(i).distance < verts.at(min).distance && verts.at(i).beenVisited == false) {
            min = i;
        }
    }
    verts.at(min).beenVisited = true;
    return min;
}
