/********************************************************************************************
**	Project: Stack Project
**  Programmer: Jonathan Spalding
**  Course:		cs2420
**	Section:	001
**	Assignment: 2
**	Data:		September 8, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

string postfix(string &infix);
string removeSpace(string line);
char precedenceWeight();
bool operatorChecker(char c);
int evaluatePostfix(string& postFix);
int evaluate(int left, int right, char operation);

int main()
{
	char dataFileName[] = "C:\\CS2420\\Assignment3\\data.txt";
	//start by opening the file, looping, and reads each line. Then work through the list.
	ifstream fileData;

	fileData.open(dataFileName, 0); //This 0 is an extraction operator that only works on Windows. If you're on mac/linux you should remove the , 0

	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << dataFileName << endl;
		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
		return -1;
	}

	// I've got the data file open.
	// read and use the data
	string line;
	double solution;
	while (getline(fileData, line))
	{
		line = removeSpace(line);
		cout << "infix: " << line << endl;
		line = postfix(line);
		cout << "postfix: " << line << endl;
		solution = evaluatePostfix(line);
		cout << "answer: " << solution << endl;
		cout << endl;
	}

	//Don't forget to close the file!
	fileData.close();
	// wait for the user to press enter to quit
	cout << endl << "Press the [Enter] key to quit...";
	cin.get();
}

string removeSpace(string line)
{
	stringstream foo(line);
	string tmpString;
	string removeString;

	for (size_t i = 0; i < line.size(); i++)
	{
		if (line.at(i) != ' ') {
			tmpString += foo.get();
		}
		else {
			removeString += foo.get();
		}
	}
	return tmpString;
}

char precedenceWeight()
{
	return 0;
}

int evaluatePostfix(string& line)
{
	// 1. Initialize a stack of doubles
	stack<int> numberStack; //Jon's note. stack<double> stk;
	for (unsigned int i = 0; i < line.size(); i++)
	{
		const char nextCharacter = line.at(i);
		// if (next input is a number)
		if (isdigit(nextCharacter))    //The helper function declared in InToPostFix.h
		{
			//Read the next input and push it onto the stack
			stringstream str;
			str << nextCharacter;
			int x;
			str >> x;
			numberStack.push(x);
		}
		else if (nextCharacter == ' ')
		{
		}
		else
		{
			//Read the next character, which is an operator symbol 	
			//Use top and pop to get the two numbers off the top of the stack 
			int top = numberStack.top();
			numberStack.pop();
			int top2 = numberStack.top();
			numberStack.pop();
			//Combine these two numbers with the operation(using the second number popped as the left operand)
			int answer = evaluate(top2, top, nextCharacter);
			//Push the result onto the stack
			numberStack.push(answer);
		}
	}
	//3. At this point, the stack contains one number which is the result of the expression
	return numberStack.top();
}

int evaluate(int left, int right, char operation)
{
	if (operation == '+') {
		return (left + right);

	}
	else if (operation == '-') {
		return (left - right);

	}
	else if (operation == '*') {
		return (left * right);

	}
	else if (operation == '/') {
		return (left / right);

	}
	else {
		cout << endl << "Error with evaluate function" << endl;
	}
}

bool operatorChecker(char character)
{
	if (character == '+' || character == '-' || character == '*' || character == '/')
	{
		return true;
	}
	return false;
}

char precedenceWeight(char operand)
{
	if (operand == '+' || operand == '-') {
		return 1;
	}
	else if (operand == '*' || operand == '/' || operand == '%') {
		return 2;
	}
	else {
		return 0;
	}
}

string postfix(string &infix)
{
	// 1. initialize stack to hold operation symbols and parenthesis
	string returnString;
	stack<char> symbolStack;
	// 2. do if (the next input is a left parenthesis)
	for (unsigned int i = 0; i < infix.size(); i++)
	{
		char nextCharacter = infix.at(i);
		if (nextCharacter == '(') {
			//Read the left parenthesis and push it onto the stack
			symbolStack.push(nextCharacter);
		} //else if (the next input is a number or operand)
		else if (isdigit(nextCharacter))
		{
			//Read the operand (or number) and write it to the output
			returnString.push_back(nextCharacter);
			returnString.push_back(' ');
		}
		else if (operatorChecker(nextCharacter))
		{
			//while ( stack is not empty AND stack’s top is not left parenthesis AND stack’s top is an operation with equal or higher precedence than the next input symbol) {
			while (symbolStack.size() > 0 && symbolStack.top() != '(' && precedenceWeight(symbolStack.top()) >= precedenceWeight(nextCharacter)) {
				//print the stack’s top pop the stack’s top
				returnString.push_back(symbolStack.top());
				returnString.push_back(' ');
				symbolStack.pop();
			}
			//push the next operation symbol onto the stack
			symbolStack.push(nextCharacter);
		}
		else {
			//read and discard the next input symbol (should be a right parenthesis)
			if (nextCharacter == ' ')
			{
			}
			else {
				if (nextCharacter != ')')
				{
					cout << "Something went wrong. There should have been parenthesis";
				}
				//print the top operation and pop it
				returnString.push_back(symbolStack.top());
				returnString.push_back(' ');
				symbolStack.pop();
				//while ( stack’s top is not a left parenthesis )
				while (symbolStack.top() != '(')
				{
					//print next symbol on stack and pop stack pop and discard the last left parenthesis
					returnString.push_back(symbolStack.top());
					returnString.push_back(' ');
					symbolStack.pop();
				}
				symbolStack.pop();
			}
		}
	}
	//while (there is more of the expression to read)
	while (symbolStack.size() != 0)
	{
		// 3. print and pop any remaining operations on the stack (there should be no remaining left parenthesis)
		returnString.push_back(symbolStack.top());
		returnString.push_back(' ');
		symbolStack.pop();
	}
	return returnString;
}