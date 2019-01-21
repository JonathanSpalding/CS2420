#include "Iterator.h"

Iterator::Iterator(Node* start)
{
    this->itr = start;
}

int Iterator::operator*()
{
    return this->itr->data;
}

void Iterator::operator++()
{
    itr = itr->next;
}

bool Iterator::operator!=(Iterator & other)
{
    if (itr == other.itr)
        return false;
    else
        return true;
}

bool Iterator::is_item()
{
    if (itr == nullptr) {
        return false;
    } else {
        return true;
    }
}
