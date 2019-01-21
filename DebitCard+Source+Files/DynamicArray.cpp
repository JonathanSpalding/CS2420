#include "DynamicArray.h"
DynamicArray::DynamicArray()
{
	capacity = INITIAL_CAPACITY;
	transactions = new Transaction[capacity]; //make a new Transaction object with a capacity of 2.
	used = 0;
}

DynamicArray::~DynamicArray()
{
	//capacity = 2; //I guess i don't need this?
	//used = 0; //I guess i don't need this?
	//transactions = new int[2]; //I guess i don't need this?
}

void DynamicArray::push_back(const Transaction & newTransaction)
{
	if (used == capacity)
	{
		Realloc();
	}
	transactions[used] = newTransaction;
	used = used + 1;
}

int DynamicArray::size() const
{
	return used;
}

Transaction & DynamicArray::at(int index)
{
	// Copied this code from (int DynArray::at(int n))
	if (index < 0 || index >= capacity)
	{
		throw(std::runtime_error("invalid index"));
	}
	return transactions[index];
}

void DynamicArray::Realloc()
{
	// grow array larger
	Transaction *tmpData = new Transaction[capacity * 2];

	// save old data
	for (int i = 0; i < used; i++)
	{
		tmpData[i] = transactions[i]; 
	}

	// destroy old data
	delete[] transactions;

	// updata data ptr
	transactions = tmpData;

	capacity *= 2;
}
