#include "Node.h"

Node::Node(int value)
{
	data = value;
	height = 0;
	rightChild = nullptr;
	leftChild = nullptr;
}


Node::~Node()
{
}
