#pragma once
#include <iostream>
#include <cassert>
class Search
{
public:
	Search(); //Default Constructor
	Search(int size); // initializes a Search Object with an internal int array of the specified size
	~Search(); // destroys all data allocated by the constructor
	bool SequentialSearch(int target); // returns true if target is found in the object’s data array

	bool RecursiveBinarySearch(int target); // returns true if target is found in the object’s data array (recursive)
	bool IterativeBinarySearch(int target); // returns true if target is found in the object’s data array

	void InitSortedArray();
	int GetSize();

	void SetSeed(unsigned int seed);
	// stuff to get first, middle, and last sections of array
	int GetFirst();
	int GetMiddle();
	int GetEnd();

private:
	int *Array; // array of ints
	int size; // size of the array
	// "Whatever else you need"
	bool RecursiveBinarySearchHelper(int target, int lowIndex, int highIndex);
};