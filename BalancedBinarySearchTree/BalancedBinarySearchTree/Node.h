#pragma once
class Node
{
public:
	Node();
	Node(int data);
	~Node();

	int data;
	Node *left;
	Node *right;
	int height;
};

