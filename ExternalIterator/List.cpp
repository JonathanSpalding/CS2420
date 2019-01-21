#include <iostream>
#include "List.h"

List::List()
{
    this->headptr = nullptr;
    this->tailptr = nullptr;
    this->length = 0;
}

List::~List()
{
    Node* current = headptr;
    while (current != nullptr) {
        Node* nextNode = current->next;
        current = nextNode;
    }
}

void List::push_front(const int& value)
{
    if (headptr == nullptr) {
        headptr = new Node;
        tailptr = headptr;
    } else {
        Node* temp = headptr;
        headptr = new Node(value);
        headptr->next = temp;
    }
    length++;
}

void List::push_back(const int& value)
{
    if (length == 0) {
        headptr = new Node(value);
        tailptr = headptr;
    } else {
        Node* temp = tailptr;
        tailptr = new Node(value);
        temp->next = tailptr;
    }
    length++;
}

void List::remove(const int& value)
{
    while (headptr->data == value) {
        headptr = headptr->next;
        length--;
    }
    
    Node* prev = headptr;
    Node* temp = headptr->next;
    
    while (temp != nullptr)
    {
        if (temp->data == value) {
            prev->next = temp->next;
            if (temp == tailptr) {
                tailptr = prev;
            }
            temp = prev->next;
            length--;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

Iterator List::begin()
{
    return Iterator(headptr);
}

Iterator List::end()
{
    return Iterator(tailptr);
}

int List::size()
{
    return length;
}

void List::PrintList() // mainly for debugging
{
    Node* current = headptr;
    while (current != nullptr) {
        std::cout  << current->data << " ";
        current = current->next;
    }
}
