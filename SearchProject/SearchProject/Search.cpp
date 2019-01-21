#include "Search.h"
#include <cstdlib>

Search::Search()
{
	Array = new int[1000000];
	size = 1000000;
	for (int i = 0; i < size; i++)
	{
		Array[i] = i;
	}
}

Search::Search(int size)
{
	size = 1000000;

}

Search::~Search()
{
	delete[] Array;
	Array = nullptr;

}

bool Search::SequentialSearch(int target)
{
	for (int i = 0; i < size; i++) {
		if (target == Array[i])
			return true;
	}
	return false;
}

bool Search::RecursiveBinarySearch(int target)
{
	return RecursiveBinarySearchHelper(target, 0, size);
}

bool Search::IterativeBinarySearch(int target)
{
	int start = 0;
	int finish = size;
	int middle;

	while (true) { 
		middle = (start + finish) / 2;

		if (start == finish)
			break;
		if (target == Array[middle])
			return true;
		else
		{
			if (target < Array[middle])
			{
				finish = middle;
			}
			else if (target > Array[middle])
			{
				start = middle;
			}
		}
	}
	return false;
}

void Search::InitSortedArray()
{
	// Function to initialize the array with sorted random numbers
	// call srand(0) before initializing to get the same numbers each time
	srand(0);
	// Don't use a sort() function here. Rather, when initializing, insert a number a bit larger than the previous number
		// Array [0] =  rand()%5
		// Array[i + 1] = Array[i] + rand() %5 etc.
	/*Array[0] = rand() % 5;
	for (int i = 1; i < this->size; i++)
	{
		Array[i + 1] = Array[i] + (rand() % 5);
	}*/
	{
		for (int i = 0; i < size; i++)
		{
			Array[i] = rand() % 1000;
		}
	}
}

int Search::GetSize()
{
	return size;
}

void Search::SetSeed(unsigned int seed)
{
	void srand(long);
}

bool Search::RecursiveBinarySearchHelper(int target, int lowIndex, int highIndex)
{

	int middle = (lowIndex + highIndex) / 2;

	if (lowIndex == highIndex)
	{
		return false;
	}

	// base case
	if (target == Array[middle])
		return true;
	// recursive case
	else
	{
		if (target < Array[middle])
		{
			return RecursiveBinarySearchHelper(target, lowIndex, middle);
		}
		else
		{
			return RecursiveBinarySearchHelper(target, middle, highIndex);
		}
	}
}

int Search::GetFirst()
{
	int temp = (size / 4);
	int randIndex = rand() % temp;
	return Array[randIndex];
}
int Search::GetMiddle()
{
	int temp = (size / 2);
	int randIndex = (rand() % temp) + (size / 4);
	return Array[randIndex];
}
int Search::GetEnd()
{
	int temp = (size / 4) * 3;
	int randIndex = (rand() % (size / 4) + (temp));
	return Array[randIndex];
}