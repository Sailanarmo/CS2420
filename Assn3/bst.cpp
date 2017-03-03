#include "bst.hpp"

#include <iostream>


void BST::insert(std::shared_ptr<Node> &curr, int data){
	


	if(curr == nullptr)
	{
		curr = std::make_shared<Node>(data);
		return;
	}

	

	if(data < curr->data)
	{
		insert(curr->leftChild, data);
	}
	else if(data > curr->data)
	{	
		insert(curr->rightChild, data);
	}
	
	getSize();	
}

void BST::addValue(int value){
    std::cout << "Inserting: " << value <<", Level: " << size << std::endl << std::endl;
	insert(root, value);
	std::cout << toString() << std::endl;
}

void BST::import(std::string file)
{

	std::ifstream fin(file);
	int num;
	if(!fin)
	{
		std::cout << "Bad file, or file not located." << std::endl;
	}
	while(fin >> num)
	{
		addValue(num);
	}

	std::cout << "Text File imported, numbers added to tree." << std::endl;
	
}

std::string BST::toString(){

	std::stringstream ss;

	ss << toString(root, 1);

	return ss.str();
	
}

std::string BST::toString(std::shared_ptr<Node> &root, int level){

	std::stringstream ss;

	if(!root) return "";

	ss << toString(root->rightChild, level + 1);

	for (int i = 0; i < level; ++i)
	{
		ss << "    ";

	}

	ss << root->data << std::endl;

	ss << toString(root->leftChild, level + 1);

	return ss.str();
}

int BST::getSize(){

	return treeHeight(root);

}

int BST::treeHeight(std::shared_ptr<Node> &curr){

	if(curr == nullptr)
	{
		return 0;
	}

	size = std::max(treeHeight(curr->rightChild), treeHeight(curr->leftChild));
	
	return size + 1;
}
