#include "avl.hpp"



//TODO: Write code.



std::shared_ptr<Node> AVL::insert(std::shared_ptr<Node> &curr, int data)
{

	//if the root is null, make yourself the root and return yourself.
	if(!curr)
	{
		curr = std::make_shared<Node>(data);
		return curr;
	}
	
	if(data < curr->data) //if data is less than the parents data, go to the left, then balance yourself.
	{
		insert(curr->leftChild, data);
		curr = balance(curr);
	}
	else if(data > curr->data) //if data is less than the parent's data, go to the right, then balance yourself.
	{
		insert(curr->rightChild, data);
		curr = balance(curr);
	}

	return curr;

}

void AVL::addValue(int value)
{

	std::ofstream myFile;

	myFile.open("output.txt", std::ios_base::app);

	insert(root, value);
	std::cout << "Inserting: " << value << ", Level: " << height << std::endl;
	myFile << "Inserting: " << value << ", Level: " << height << std::endl;
	std::cout << toString() << std::endl;
	myFile << toString() << std::endl;
	myFile.close();

}

int AVL::difference(std::shared_ptr<Node> &curr)
{
	int leftTree = treeHeight(curr->leftChild);
	int rightTree = treeHeight(curr->rightChild);
	int heightDiff = leftTree - rightTree;

	return heightDiff;
}

std::shared_ptr<Node> AVL::balance(std::shared_ptr<Node> &curr)
{

	int weight = difference(curr);

	if(weight > 1)
	{
		if(difference(curr->leftChild) > 0)
		{
			curr = llRotation(curr);
			std::cout << "left-left rotation" << std::endl;
		}
		else
		{
			curr = lrRotation(curr);
			std::cout << "left-right rotation" << std::endl;
		}
	}
	else if(weight < -1)
	{
		if(difference(curr->rightChild) > 0)
		{
			curr = rrRotation(curr);
			std::cout << "right-right rotation" << std::endl;
		}
		else
		{
			curr = rlRotation(curr);
			std::cout << "right-left rotation" << std::endl;
		}
	}
	return curr;
}

/*
Rotations:
*/

std::shared_ptr<Node> AVL::llRotation(std::shared_ptr<Node> &curr)
{

	std::shared_ptr<Node> temp = std::make_shared<Node>(curr->data);

	temp = curr->leftChild;
	curr->leftChild = temp->rightChild;
	temp->rightChild = curr;

	return temp;

}

std::shared_ptr<Node> AVL::rrRotation(std::shared_ptr<Node> &curr)
{

	std::shared_ptr<Node> temp = std::make_shared<Node>(curr->data);

	temp = curr->rightChild;
	curr->rightChild = temp->leftChild;
	temp->leftChild = curr;

	return temp;

}

std::shared_ptr<Node> AVL::lrRotation(std::shared_ptr<Node> &curr)
{

	std::shared_ptr<Node> temp = std::make_shared<Node>(curr->data);

	temp = curr->leftChild;
	curr->leftChild = rrRotation(temp);

	return llRotation(curr);

}

std::shared_ptr<Node> AVL::rlRotation(std::shared_ptr<Node> &curr)
{

	std::shared_ptr<Node> temp = std::make_shared<Node>(curr->data);
	
	temp = curr->rightChild;
	curr->rightChild = llRotation(temp);

	return rrRotation(curr);
}

void AVL::import(std::string file)
{

	std::ifstream fin(file);
	int num;
	if(!fin)
	{
		std::cout << "Bad file, or file not loaction." << std::endl;
	}
	while(fin >> num)
	{
		addValue(num);
	}

	std:: cout << "Text File imported, numbers add to tree." << std::endl;

}

std::string AVL::toString()
{
	std::stringstream ss;

	ss << toString(root, 1);

	return ss.str();
}

std::string AVL::toString(std::shared_ptr<Node> &root, int level)
{

	std::stringstream ss;

	if(!root) return "";

	ss << toString(root->rightChild, level + 1);

	for(int i = 0; i < level; ++i)
	{
		ss << "    ";
	}

	ss << root->data << std::endl;

	ss << toString(root->leftChild, level + 1);

	return ss.str();
}

int AVL::treeHeight(std::shared_ptr<Node> &curr)
{

	if(curr == nullptr)
	{
		height = 0;
		return height;
	}

	height = std::max(treeHeight(curr->rightChild), treeHeight(curr->leftChild));

	return height + 1;
}
