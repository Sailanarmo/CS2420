#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP


#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "node.hpp"

class BST
{

public:

	BST(std::string file): root(nullptr),size(0) {import(file);}

	void insert(std::shared_ptr<Node> &curr, int data);
	void addValue(int value);
	void import(std::string file);
	std::string toString();
	std::string toString(std::shared_ptr<Node> &root, int level);
	int getSize();
	int treeHeight(std::shared_ptr<Node> &curr);
private:

	std::shared_ptr<Node> root;
	int size = 0;

};


#endif
