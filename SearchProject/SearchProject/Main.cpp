/********************************************************************************************
**	Project: Search Project
**  Programmer: Jonathan Spalding
**  Course:		cs2420
**	Section:	001
**	Assignment: 4
**	Data:		September 11, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <Windows.h>
#include <random>
#include <cstdlib>
#include "Search.h"
#include "Timer.h"

using namespace std;

int main()
{
	Search s;
	Timer ti;
	bool result = false;
	int searchValue;
	int found = 0;

	// do something you want to time (don't do any "cout's" here. They take a long time...)
	//Sleep(521); // this should sleep for around 521 milliseconds

	//Search* s = new Search(100);
	s.SetSeed(rand());

	cout << "Creating a sorted array of " << s.GetSize() << endl;
	cout << "Finished creating a sorted array of " << s.GetSize() << endl << endl;

	cout << "Searching for a number at the start of the array" << endl;
	ti.Start();
	s.SequentialSearch(s.GetFirst());
	ti.End(); //end the timer
	if (s.SequentialSearch(s.GetFirst())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.sequentialSearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	s.IterativeBinarySearch(s.GetFirst());
	ti.End(); //end the timer
	if (s.IterativeBinarySearch(s.GetFirst())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.IterativeBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.RecursiveBinarySearch(s.GetFirst());
	ti.End(); //end the timer
	if (s.RecursiveBinarySearch(s.GetFirst())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.RecursiveBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "\nSearching for a number in the middle of the array" << endl;
	ti.Start();
	s.SequentialSearch(s.GetMiddle());
	ti.End(); //end the timer
	if (s.SequentialSearch(s.GetMiddle())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.SequentialSearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.IterativeBinarySearch(s.GetMiddle());
	ti.End(); //end the timer
	if (s.IterativeBinarySearch(s.GetMiddle())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.IterativeBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.RecursiveBinarySearch(s.GetMiddle());
	ti.End(); //end the timer
	if (s.RecursiveBinarySearch(s.GetMiddle())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.RecursiveBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "\nSearching for a number at the end of the array" << endl;
	ti.Start();
	s.SequentialSearch(s.GetEnd());
	ti.End(); //end the timer
	if (s.SequentialSearch(s.GetEnd())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.SequentialSearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.IterativeBinarySearch(s.GetEnd());
	ti.End(); //end the timer
	if (s.IterativeBinarySearch(s.GetEnd())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.IterativeBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.RecursiveBinarySearch(s.GetEnd());
	ti.End(); //end the timer
	if (s.RecursiveBinarySearch(s.GetEnd())) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.RecursiveBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "\nSearching for a number NOT in the array" << endl;
	ti.Start();
	s.SequentialSearch(-1);
	ti.End(); //end the timer
	if (s.SequentialSearch(-1)) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.SequentialSearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.IterativeBinarySearch(-1);
	ti.End(); //end the timer
	if (s.IterativeBinarySearch(-1)) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.IterativeBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
	ti.Start();
	s.RecursiveBinarySearch(-1);
	ti.End(); //end the timer
	if (s.RecursiveBinarySearch(-1)) {
		found = 1;
	}
	else {
		found = 0;
	}
	cout << "\ts.RecursiveBinarySearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "\n" << "Press [Enter] to terminate";
	cin.get();
}