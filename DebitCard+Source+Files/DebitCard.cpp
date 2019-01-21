#include "DebitCard.h"
#include <iostream>
#include <iomanip>
using namespace std;


DebitCard::DebitCard()
{
	totalTransactions = 0;
	accountBalance = 0;
	totalDeposits = 0;
}

DebitCard::~DebitCard()
{

}

double DebitCard::Deposit(double deposit)
{
	accountBalance += deposit;
	totalDeposits += deposit;
	return accountBalance;
}

double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount)
{
	transactions.push_back(Transaction(idNumber, date, description, amount));
	totalTransactions++;
	accountBalance -= amount;
	return accountBalance;
}

bool DebitCard::ClearTransaction(int idNumber)
{
	
	for (int i = 0; i < transactions.size(); i++)
	{
		if (transactions.at(i).idNumber == idNumber)
		{
			transactions.at(i).cleared = true;
		}
	}
	return 0;
}

void DebitCard::DisplayActivity()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "total transactions: " << totalTransactions << endl; //this is the variable that has the amount of checks cleared
	cout << "total deposits: $" << totalDeposits << endl; //this is the variable that has the amount of checks deposited
	cout << "account balance: $" << accountBalance << endl; //this is the variable that has the total balance
	cout <<"\nList of cleared transactions: "<< endl;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions.at(i).cleared) {
			cout << transactions.at(i).date << "\t";
			cout << "$" << transactions.at(i).amount << "\t";
			cout << std::setprecision(2) << transactions.at(i).description << "\t";
			cout << endl;
		}
	}

	cout << "\nList of pending transactions: " << endl;
	for (int i = 0; i < transactions.size(); i++) {
		if (!(transactions.at(i).cleared)) {
			cout << transactions.at(i).date << "\t";
			cout << std::setprecision(2) << "$" << transactions.at(i).amount << "\t";
			cout << transactions.at(i).description << "\t";
			cout << endl;
		}
	}
}
