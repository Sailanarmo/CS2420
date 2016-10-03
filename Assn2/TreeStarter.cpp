#include "TreeStarter.hpp"

#include <iostream>

std::shared_ptr<Node> Tree::preorderBuild(std::ifstream &inf) {

    return preorderBuild(inf, root);

}

std::shared_ptr<Node> Tree::preorderBuild(std::ifstream &inf, std::shared_ptr<Node> parent)
{

    std::string words;
    int kidCount;

    inf >> words >> kidCount;

    std::shared_ptr<Node> newParent = std::make_shared<Node>(words, kidCount, parent);
	
    std::shared_ptr<Node> previous = nullptr;


    for (int i = 0; i < kidCount; ++i)
    {
	std::shared_ptr<Node> kid = preorderBuild(inf, newParent);
	if(i == 0) newParent->left = kid;
	else
	{
	    previous->right = kid;
	}
	
	previous = kid;	

    }
    //std::cout << "Tree built" << std::endl;
    printTree(words, newParent);
    return newParent;

}

void Tree::printTree(std::string indent) {
    indent = "   ";

    return printTree(indent, root);
}

void Tree::printTree(std::string indent, std::shared_ptr<Node> n) {

    if(!n) return;
    std::cout << indent << "[" << n->kid << ", " << n->left << "]\n";
    if(n->left) printTree(indent, n->left);
    if(n->right) printTree(indent, n->right);

}




