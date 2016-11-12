#pragma once
struct Node
{
	int data;
	int height;
	Node* leftChild;
	Node* rightChild;
	Node(int value);
	~Node();
};

