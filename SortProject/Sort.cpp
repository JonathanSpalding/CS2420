#include "Sort.h"

Sort::Sort()
{
}

Sort::Sort(int size)
{
    this->size = size;
    this->myArray = new int[size];
    
}

Sort::~Sort()
{
    delete[] myArray;
}

void Sort::selectionSort()
{
    if (size == 0)
    {
        return;
    }
    
    for (int i = size - 1; i > 0; --i)
    {
        int largest = myArray[0];
        int index_of_largest = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (myArray[j] > largest)
            {
                largest = myArray[j];
                index_of_largest = j;
            }
        }
        if (i != index_of_largest)
        {
            swap(myArray[i], myArray[index_of_largest]);
        }
    }
}

void Sort::UnsortedArray()
{
    for (int i = 0; i < size; i++)
    {
    myArray[i] = ((rand() % 15));
    }
}

void Sort::insertionSort()
{
    int temp;
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        temp = myArray[i];
        while (temp < myArray[j] && j > 0)
        {
            myArray[j + 1] = myArray[j];
            --j;
        }
        myArray[j + 1] = temp;
    }
}

void Sort::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Sort::mergeSort()
{
    mergeSort(myArray, size);
}

void Sort::mergeSort(int myArray[], int size)
{
    int n1, n2;
    if (size > 1)
    {
        //find sizes of subarrays
        n1 = size / 2;
        n2 = size - n1;
        
        mergeSort(myArray, n1);
        mergeSort(myArray + n1, n2);
        
        //merge both sorted halves
        merge(myArray, n1, n2);
    }
}

void Sort::merge(int myArray[], int n1, int n2)
{
    int* temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int i;
    
    temp = new int[n1 + n2];
    
    while ((copied < n1) && (copied2 < n2))
    {
        if (myArray[copied] < (myArray + n1)[copied2])
        {
            temp[copied++] = myArray[copied1++];
        }
        else
        {
            temp[copied++] = (myArray + n1)[copied2++];
        }
    }
    
    while (copied1 < n1)
    {
        temp[copied++] = myArray[copied1++];
    }
    while (copied2 < n2)
    {
        temp[copied++] = (myArray + n1)[copied2++];
    }
    
    for (i = 0; i < n1 + n2; ++i)
    {
        myArray[i] = temp[i];
    }
    delete[] temp;
}

void Sort::quickSort(int myArray[], int lowIndex, int highIndex)
{
    int size = highIndex - lowIndex;
    if (size == 0 || size == 1)
    {
        return;
    }
    int midIndex = partition(myArray, lowIndex, highIndex);
    quickSort(myArray, lowIndex, midIndex);
    quickSort(myArray, midIndex + 1, highIndex);
}

void Sort::quickSort()
{
    quickSort(myArray, 0, size);
}

int Sort::partition(int myArray[], int lowIndex, int highIndex)
{
    bool finished = false;
    int middle = myArray[lowIndex + (highIndex - lowIndex) / 2];
    while (!finished)
    {
        while (myArray[lowIndex] < middle)
        {
            ++lowIndex;
        }
        while (middle < myArray[highIndex])
        {
            --highIndex;
        }
        if (lowIndex >= highIndex)
        {
            finished = true;
        }
        else
        {
            int temp;
            temp = myArray[lowIndex];
            myArray[lowIndex] = myArray[highIndex];
            myArray[highIndex] = temp;
            ++lowIndex;
            --highIndex;
        }
    }
    return highIndex;
}
