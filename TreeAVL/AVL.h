// CS2420 Programming Project #07
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: Nov 2016
// Header file for main - constants and function prologues
// =================================================

/*I Matthew Vaughan have not used any code other than my own(or that in the textbook)
for this project.I also have not used any function or data - structure from
the Standard - Template Library.I understand that any violation of this
disclaimer will result in a 0 for the project.*/

#include "Node.h"
#include <iostream>

using namespace std;

#pragma once
class AVL
{
private:
	Node* root;
	int size;
	void InsertH(Node* &temp, int val);
	void destroyTree(Node* temp);
	void PrintTreeH(Node* temp, int depth);
	string tab(int depth);
	int updateHeight(Node* temp);
	int checkBalance(Node* temp);
	void rebalance(Node* &temp);
	Node* rotateRight(Node* temp);
	Node* rotateLeft(Node* temp);
	void rotateLeftRight(Node* &temp);
	void rotateRightLeft(Node* &temp);
public:
	AVL();
	~AVL();
	void PrintTree();
	void Insert(int val);
	int getSize();
};

