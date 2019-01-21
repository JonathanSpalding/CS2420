#include "Transaction.h"


Transaction::Transaction(int transactionID, std::string date, std::string description, double amount)// should this be void?
{
	idNumber = transactionID; // unique identification number of the 
	this->date = date;
	this->description = description;
	this->amount = amount; // amount of transaction
	cleared = false; // has the transaction been "cleared"
}
