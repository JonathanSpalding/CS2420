/********************************************************************************************
 **    Project: External Iterator
 **  Programmer: Jonathan Spalding
 **  Course:        cs2420
 **    Section:    001
 **    Assignment: 6
 **    Data:        September 28, 2018
 **
 **    I certify that I wrote all code in this project except that which was
 **    provided by the instructor.
 **
 ***********************************************************************************************/

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
    // build the list<int>
    List intList;
    for (int i = 0; i < 10; i++)
    {
        intList.push_back(i);
        intList.push_front(i);
    }
    cout << "Initial List" << endl;
    intList.PrintList();
    cout << endl;
    
    // display the list with iterators
    Iterator start = intList.begin();
    Iterator end = intList.end();
    cout << "Displaying List with external iterators" << endl;
    while (start != end)
    {
        cout << *start << " ";
        ++start;
    }
    cout << endl << endl;
    
    // display the list with new for-loop
    // this type of for iterating for-loop was added in c++11
    // for this to work, this list must have both begin() and end() functions
    // which return an iterator to the beginning and end of the list.
    // The returned iterators must implement the following functions:
    //        int operator*()
    //        void operator++()
    //        bool operator!=(Iterator& other)
    // Since our Iterator does, we can use this new for-loop
    // to iterate over the entire list.
    // here's a good explanation of this new for-loop:
    //    https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html
    cout << "Displaying List with new for-loop" << endl;
    for (auto x : intList)
    {
        cout << x << " ";
    }
    cout << endl << endl;
    
    // remove all 0's, 9's, and 6's
    intList.remove(0);
    intList.remove(9);
    intList.remove(6);
    cout << "Displaying List without 0's, 9's, or 6's" << endl;
    for (auto x : intList)
    {
        cout << x << " ";
    }
    cout << endl << endl;
    
    cout << "Press [Enter] to quit";
    getchar();
}
