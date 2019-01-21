/********************************************************************************************
**	Project: AVL Trees
**  Programmer: Jonathan Spalding
**  Course:		cs2420
**	Section:	002
**	Assignment: 4
**	Data:		November 10, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
	DestructorHelper(root);
}

void AVLTree::DestructorHelper(Node * cursor)
{
	// base case
	if (cursor == nullptr) {
		return;
	}

	// delete left
	DestructorHelper(cursor->left);
	// delete right
	DestructorHelper(cursor->right);
	// delete me
	delete cursor;
}

void AVLTree::Insert(int data)
{
	root = InsertHelper(root, data);
}

Node * AVLTree::InsertHelper(Node * cursor, int data)
{
	// base case
	if (cursor == nullptr) {
		return new Node(data);
	}

	if (data <= cursor->data) {
		// go left
		cursor->left = InsertHelper(cursor->left, data);
	}
	else {
		// go right
		cursor->right = InsertHelper(cursor->right, data);
	}

	UpdateHeight(cursor);
	// update height
	int balance = determineRotation(cursor);

	// rotate if needed
	if (balance == 2) {
		balance = 0;
		if (cursor->left != nullptr) {
			balance = determineRotation(cursor->left);
		}

		if (balance < 0) {
			cursor->left = RotateLeft(cursor->left);
		}
		cursor = RotateRight(cursor);
	}
	if (balance == -2) {
		balance = 0;
		if (cursor->right != nullptr) {
			balance = determineRotation(cursor->right);
		}
		if (balance > 0) {
			cursor->right = RotateRight(cursor->right);
		}
		cursor = RotateLeft(cursor);
	}

	return cursor;
}

void AVLTree::Print()
{
	PrintHelper(root, "");
	cout << endl << endl;
}

void AVLTree::PrintHelper(Node * cursor, std::string indent)
{
	if (cursor == nullptr) {
		cout << indent << "[Empty]" << endl;
		return;
	}

	if (cursor->height == 0) {
		cout << indent << cursor->data << " (" << cursor->height << ")";
		cout << " [leaf]" << endl;
		return;
	}

	cout << indent << cursor->data << " (" << cursor->height << ")" << endl;
	PrintHelper(cursor->left, indent + "    ");
	PrintHelper(cursor->right, indent + "    ");
}

void AVLTree::PreOrderTraversal()
{
	PreOrderHelper(root);
	cout << endl;
}

void AVLTree::PreOrderHelper(Node * cursor)
{
	if (cursor == nullptr) {
		return;
	}

	cout << cursor->data << ", ";
	PreOrderHelper(cursor->left);
	PreOrderHelper(cursor->right);
}

void AVLTree::UpdateHeight(Node * cursor)
{
	if (cursor == nullptr) {
		return;
	}
	int leftHeight = -1;
	int rightHeight = -1;
	if (cursor->left != nullptr) {
		leftHeight = cursor->left->height; // does this hafe a left pointer? If so, go down and grab the height.
	}
	if (cursor->right != nullptr) {
		rightHeight = cursor->right->height;
	}

	cursor->height = max(leftHeight, rightHeight) + 1;
}

int AVLTree::determineRotation(Node * cursor)
{
	if (cursor->right == nullptr) {
		return cursor->left->height - -1;
	}

	if (cursor->left == nullptr) {
		return -1 - cursor->right->height;
	}
	else {
		return cursor->left->height - cursor->right->height;
	}
}

Node * AVLTree::RotateRight(Node * cursor)
{
	Node *tmp = cursor->left;
	cursor->left = tmp->right;
	tmp->right = cursor;
	UpdateHeight(cursor);
	UpdateHeight(tmp);
	return tmp; //return tmp here and not cursor. "tmp is the new top dog."
}

Node * AVLTree::RotateLeft(Node * cursor)
{
	Node* tmp = cursor->right; //1
	cursor->right = tmp->left; //2
	tmp->left = cursor; //3
	//3.5 update height tmp.cursor
	UpdateHeight(cursor);
	UpdateHeight(tmp);
	return tmp; //4
}