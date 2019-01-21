#include <iostream>
#include <string>

#include "LinkedList.h"
using namespace std;


LinkedList::~LinkedList()
{
	if (head != nullptr) {
		head->~Course();  //~Course calls other ~Courses recursivley
	}
}

// recursive helper for ~LinkedList()
void LinkedList::DestructorHelper(Course * cursor)
{
	// base case
	if (cursor == nullptr) {
		return;
	} else {
		Course *tmp = cursor->next;
		delete cursor;
		DestructorHelper(tmp);
	}
}

// precondition: list is in sorted order
// postcondition: newCourse is inserted into the list so the list maintains
//                sorted order. using recursison.
void LinkedList::Insert(Course * newCourse)
{	
	//head = InsertHelper(head, newCourse);
	if (head == nullptr) {
		head = newCourse;
		return;
	}

	if (newCourse->courseNumber < head->courseNumber) {
		newCourse->next = head;
		head = newCourse;
		return;
	} else if (head->next == nullptr) {
		head->next = newCourse;
	} else {
		Course* stepPointer = head->next;
		head->next = InsertHelper(stepPointer, newCourse);
	}
	
}

// recursive helper for insert()
Course * LinkedList::InsertHelper(Course * head, Course * newCourse)
{
	
	if (newCourse->courseNumber < head->courseNumber) {
		newCourse->next = head;
		return newCourse;
	} else if (head->next == nullptr) {
		head->next = newCourse;
		return head;
	} else {
		Course* stepPointer = head->next;
		head->next = InsertHelper(stepPointer, newCourse);
		return head;
	}
}

// postcondition: size is returned. Must be calculated using recursion.
int LinkedList::Size() const
{
	if (head == nullptr) {
		return 0;
	}
	else {
		//Do some math here? Return size recursively like this?
		return SizeHelper(head);
	}
}

// recursive helper for size()
int LinkedList::SizeHelper(Course const * cursor) const
{
	if (cursor->next == nullptr) {
		return 1;
	} else {
		return 1 + SizeHelper(cursor->next);
	}
}

// prints the contents of the list of courses to cout
void LinkedList::PrintList() const
{
	Course* head_ptr = head;
	if (head_ptr == nullptr) {
		//cout << endl << "Empty List, try again." << endl; //FIX ME: I should probably throw an exception here.
		return;
	}
	cout << "Current List: (" << Size() << ")" << endl;
	PrintListHelper(head_ptr);

	cout << endl << endl;
	return;
}

// recursive helper for PrintList()
void LinkedList::PrintListHelper(Course const * cursor) const
{
	cout << "cs" << cursor->courseNumber << " " << cursor->courseName << " ";
	cout << "Grade:" << cursor->grade << " " << "Credit Hours: " << cursor->credits << endl;
	// base case
	if (cursor->next == nullptr) {
		return;
	} else {
		//cout << cursor->data << ", "; //I believe this data variable is in reference to the 0xBADC0DE thing.
		PrintListHelper(cursor->next);
	}
}

// for help understanding the next two, google how to calulate Cumulative GPA

// total of all earned Grade Points in list of courses
double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
	double gradePoints = (cursor->grade) * (cursor->credits);
	if (cursor->next == nullptr) {
		return gradePoints;
	} else {
		return (gradePoints + CalculateTotalGradePoints(cursor->next));
	}
}
// total of all credits in list of courses
unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
	unsigned int totalCredits = cursor->credits;
	if (cursor == nullptr) {
		return totalCredits;
	} else if (cursor->next == nullptr) {
		return totalCredits;
	} else {
		return (totalCredits + CalculateTotalCredits(cursor->next));
	}
}

// calculates the Cumulative GPA of all courses in the list.
// Cumulative GPA is the sum of all "grade points" divided by the sum of all credits
// "grade points" is found by multiplying the grade of a course by the number of 
// credits for that course
// this must be calculated recursively.
double LinkedList::CalculateGPA() const
{
	if (head == nullptr) {
		return 0.0;
	} else {
		//do the math here.
		double totalGradePoints = CalculateTotalGradePoints(head);
		int totalCredits = CalculateTotalCredits(head);
		return (totalGradePoints / totalCredits);
	}
}
