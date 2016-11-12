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
	void PrintTreeH(Node* temp);
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

