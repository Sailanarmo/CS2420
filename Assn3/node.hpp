#ifndef NODE_HPP
#define NODE_HPP

#include <memory>


struct Node
{

	Node(int d) : data(d){};

	std::shared_ptr<Node> leftChild = nullptr;
	std::shared_ptr<Node> rightChild = nullptr;
	int data;

};

#endif
