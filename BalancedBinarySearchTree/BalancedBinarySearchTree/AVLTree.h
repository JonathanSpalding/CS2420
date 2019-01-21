#pragma once
#include <string>
#include <algorithm>
#include "Node.h"


class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void Insert(int data);
	void Print();
	void PreOrderTraversal();

private:
	Node * root;

	void DestructorHelper(Node *cursor);
	Node* InsertHelper(Node *cursor, int data);
	void PrintHelper(Node *cursor, std::string indent);
	void PreOrderHelper(Node* cursor);
	void UpdateHeight(Node * cursor);
	int determineRotation(Node* cursor);
	Node* RotateRight(Node* cursor);
	Node* RotateLeft(Node* cursor);
};

