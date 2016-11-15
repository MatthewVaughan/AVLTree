#include "AVL.h"
#include <string>

using namespace std;

AVL::AVL()
{
	root = nullptr;
}


AVL::~AVL()
{
	if (root == nullptr)
	{
		cout << "There is nothing to delete!" << endl;
	}
	else
	{
		destroyTree(root);
		cout << "The Tree has been erased!" << endl;
		root = nullptr;
	}
	size = 0;
}

void AVL::PrintTree()
{
	if (root == nullptr)
	{
		cout << "The Tree is currently empty" << endl;
	}
	else
	{
		int depth = 0;
		PrintTreeH(root, depth);
	}
}

string AVL::tab(int depth)
{
	string arr[10] = { " ", "  ", "   ", "    ", "     ", "      ", "       ", "        ", "         ", "          " };
	return arr[depth];
}

void AVL::PrintTreeH(Node* temp, int depth)
{
	cout << tab(depth) << temp->data << endl;
	if (temp->leftChild != nullptr)
	{
		PrintTreeH(temp->leftChild, depth+1);
	}
	if (temp->rightChild != nullptr)
	{
		PrintTreeH(temp->rightChild, depth+1);
	}
}

void AVL::destroyTree(Node* temp)
{
	if (temp->rightChild == nullptr)
	{
		if (temp->leftChild == nullptr)
		{
			delete temp;
			return;
		}
		else
		{
			destroyTree(temp->leftChild);
		}
	}
	else if (temp->leftChild == nullptr)
	{
		if (temp->rightChild == nullptr)
		{
			delete temp;
			return;
		}
		else
		{
			destroyTree(temp->rightChild);
		}
	}
	else
	{
		destroyTree(temp->leftChild);
		destroyTree(temp->rightChild);
		delete temp;
	}
}

void AVL::InsertH(Node* &temp, int val)
{
	//No duplicates allowed
	if (temp->data == val)
	{
		return;
	}
	//If the insert is less than the node
	//(1)send it down the left side
	//(2)create new node saved as left child
	else if (temp->data > val)
	{
		if (temp->leftChild == nullptr)
		{
			size++;
			Node* NN = new Node(val);
			temp->leftChild = NN;
			temp->height = updateHeight(temp);
		}
		else
		{
			InsertH(temp->leftChild, val);
			temp->height = updateHeight(temp);

			rebalance(temp);
		}
	}
	//If the insert is greater than the node
	//(1)send it down the right side
	//(2)create new node saved as right child
	else if (temp->data < val)
	{
		if (temp->rightChild == nullptr)
		{
			size++;
			Node* NN = new Node(val);
			temp->rightChild = NN;
			temp->height = updateHeight(temp);
		}
		else
		{
			InsertH(temp->rightChild, val);
			temp->height = updateHeight(temp);

			rebalance(temp);
		}
	}
}

void AVL::Insert(int val)
{
	if (root == nullptr)
	{
		Node* NN = new Node(val);
		root = NN;
		size++;
		root->height = updateHeight(root);
	}
	else
	{
		InsertH(root, val);
		root->height = updateHeight(root);

		rebalance(root);
	}
}

//Checks the Nodes children and returns the highest height
int AVL::updateHeight(Node* temp)
{
	//Evaluate largest if both children exist
	if (temp->rightChild != nullptr && temp->leftChild != nullptr)
	{
		if (temp->rightChild->height >= temp->leftChild->height)
		{
			return temp->rightChild->height + 1;
		}
		if (temp->rightChild->height <= temp->leftChild->height)
		{
			return temp->leftChild->height + 1;
		}
	}//If only right child exists return right child height
	else if (temp->rightChild != nullptr)
	{
		return temp->rightChild->height + 1;
	}
	//If only left child exists return left child height
	else if (temp->leftChild != nullptr)
	{
		return temp->leftChild->height + 1;
	}
	//Else the node has no children return 0
	else
	{
		return 0;
	}
}

//Returns the balance accordingly
//If return = 0: [sub]Tree is balanced
//If return < 0: left side heavy
//If return > 0: right side heavy
int AVL::checkBalance(Node* temp)
{
	if (temp != nullptr)
	{
		if (temp->leftChild != nullptr)
		{
			if (temp->rightChild != nullptr)
			{
				return (temp->rightChild->height - temp->leftChild->height);
			}
			else
			{
				int newHeight = -1;
				newHeight = newHeight - temp->leftChild->height;
				return newHeight;
			}
		}
		else if (temp->rightChild != nullptr)
		{
			return temp->rightChild->height + 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void AVL::rebalance(Node* &temp)
{
	//Nodes left subtree is greater than right subtree by more than one
	if (checkBalance(temp) < -1)
	{
			//Nodes leftChild's LEFT subtree is greater than leftChild's RIGHT subtree
			if (checkBalance(temp->leftChild) < 0)
			{
				temp = rotateRight(temp);
			}
			else
			{
				rotateRightLeft(temp);
			}
	}
	//Nodes right subtree is greater than left subtree by more than one
	else if (checkBalance(temp) > 1)
	{
		//Nodes rightChild's RIGHT subtree is greater than rightChilds LEFT subtree
		if (checkBalance(temp->rightChild) > 0)
		{
			temp = rotateLeft(temp);
		}
		else
		{
			rotateLeftRight(temp);
		}
	}
}

Node* AVL::rotateRight(Node* temp)
{
	Node* tempC = new Node(temp->leftChild->data);
	tempC = temp->leftChild;

	temp->leftChild = temp->leftChild->rightChild;
	tempC->rightChild = temp;

	tempC->rightChild->height = updateHeight(tempC->rightChild);
	tempC->height = updateHeight(tempC);

	rebalance(tempC);

	return tempC;
}

Node* AVL::rotateLeft(Node* temp)
{
	Node* tempC = new Node(temp->rightChild->data);
	tempC = temp->rightChild;

	temp->rightChild = tempC->leftChild;
	tempC->leftChild = temp;

	tempC->leftChild->height = updateHeight(tempC->leftChild);
	tempC->height = updateHeight(tempC);

	return tempC;
}

void AVL::rotateLeftRight(Node* &temp)
{
	temp->rightChild = rotateRight(temp->rightChild);
	temp->rightChild->height = updateHeight(temp->rightChild);
	temp = rotateLeft(temp);
	temp->height = updateHeight(temp);
}

void AVL::rotateRightLeft(Node* &temp)
{
	temp->leftChild = rotateLeft(temp->leftChild);
	temp->leftChild->height = updateHeight(temp->leftChild);
	temp = rotateRight(temp);
	temp->height = updateHeight(temp);
}

int AVL::getSize()
{
	return size;
}
