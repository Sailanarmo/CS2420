#ifndef AVL_HPP
#define AVL_HPP

#include "node.hpp"


#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

//TODO: Make work


class AVL 
{

public:

	AVL(std::string file): root(nullptr), height(0) {import(file);}
	
	int treeHeight(std::shared_ptr<Node> &curr);
	int difference(std::shared_ptr<Node> &curr);

	std::shared_ptr<Node> insert(std::shared_ptr<Node> &curr, int data);
	std::shared_ptr<Node> balance(std::shared_ptr<Node> &curr);

	std::shared_ptr<Node> llRotation(std::shared_ptr<Node> &curr);
	std::shared_ptr<Node> rrRotation(std::shared_ptr<Node> &curr);
	std::shared_ptr<Node> lrRotation(std::shared_ptr<Node> &curr);
	std::shared_ptr<Node> rlRotation(std::shared_ptr<Node> &curr);

	std::string toString();
	std::string toString(std::shared_ptr<Node> &root, int level);

	void import(std::string file);
	void addValue(int value);

private:

	std::shared_ptr<Node> root;
	int height;
};




#endif
