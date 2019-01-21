#pragma once
#include <iostream>

class Sort // Create a Sort Class
{
public:
    //Member variables
    int* myArray; // dynamic array of ints
    int size; // size of
    
    Sort();
    // Constructor(array size)
    Sort(int size);
    // Destructor
    ~Sort();
    
    // A function to initialize the array with random integers
    void UnsortedArray(); //use the same seed before each array initialization, so the array is always the same
    
    // Sort functions
    void selectionSort();
    void insertionSort();
    void mergeSort();
    void quickSort();
    int partition(int data[], int lowIndex, int highIndex);
private:
    //Helper functions
    void swap(int& a, int&b);
    void merge(int data[], int n1, int n2);
    void mergeSort(int data[], int size);
    void quickSort(int data[], int lowIndex, int highIndex);
};
