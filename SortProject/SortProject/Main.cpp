/********************************************************************************************
 **    Project: Sort
 **  Programmer: Jonathan Spalding
 **  Course:        cs2420
 **    Section:    001
 **    Assignment: 5
 **    Data:        September 23, 2018
 **
 **    I certify that I wrote all code in this project except that which was
 **    provided by the instructor.
 **
 ***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"

#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 100000;
    Sort *sort = new Sort(ARRAY_SIZE);
    Timer ti;
    
    sort->UnsortedArray();
    cout << "starting SelectionSort" << endl;
    ti.Start();
    sort->selectionSort();
    ti.End();
    cout << "SelectionSort duration: " << ti.DurationInMilliSeconds() << "ms." << endl;
    
    sort->UnsortedArray();
    cout << endl << "starting InsertionSort" << endl;
    ti.Start();
    sort->insertionSort();
    ti.End();
    cout << "Insertion sort duration: " << ti.DurationInMilliSeconds() << "ms." << endl;
    
    sort->UnsortedArray();
    cout << endl << "starting MergeSort" << endl;
    ti.Start();
    sort->mergeSort();
    ti.End();
    cout << "MergeSort duration: " << ti.DurationInMilliSeconds() << "ms." << endl;
    
    sort->UnsortedArray();
    cout << endl << "starting QuickSort" << endl;
    ti.Start();
    sort->quickSort();
    ti.End();
    cout << "QuickSort duration: " << ti.DurationInMilliSeconds() << "ms." << endl;
    
    sort->UnsortedArray();
    cout << endl << "starting std::sort()" << endl;
    ti.Start();
    std::sort(sort->myArray, sort->myArray + ARRAY_SIZE);
    ti.End();
    cout << "std::sort() duration: " << ti.DurationInMilliSeconds() << "ms" << endl;
    
    delete sort;
    
    cout << endl << "Press [Enter] key to exit";
    getchar();
}
