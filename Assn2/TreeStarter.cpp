#include "TreeStarter.hpp"

#include <iostream>

std::shared_ptr<Node> Tree::preorderBuild(std::ifstream &inf)
{
    root = preorderBuild(inf, root);
    return root;
}

std::shared_ptr<Node> Tree::preorderBuild(std::ifstream & inf, std::shared_ptr<Node> parent)
{

    std::string word;
    int children;

    inf >> word;
    inf >> children;

    auto newParent = std::make_shared<Node>(word, children);

    std::shared_ptr<Node> nextChild;

    for (int i = 0; i < children; ++i)
    {
	if(i == 0)
	{
	    newParent->child = preorderBuild(inf, newParent);
	    nextChild = newParent->child;
	}
	else
	{
	    newParent->sibling = preorderBuild(inf, newParent);
	    nextChild = newParent->sibling;
	}
    }
    newParent->subNodes = countNodes(newParent);
    return newParent;
}

int Tree::countNodes(std::shared_ptr<Node> root)
{
    int counter = 0;
    if (!root) return 0;

    if (root->child) counter += countNodes(root->child);
    if (root->sibling) counter += countNodes(root->sibling);
    return counter + 1;
}

void Tree::printTree(std::string indent, std::shared_ptr<Node> n, std::stringstream &ss)
{

   if(!n) return;
    std::cout << "Please";
   ss << indent << n->word << "{" << n->subNodes << ", " << n->kid << "}" << std::endl;
   printTree(indent+ "| ", n->child, ss);
   printTree(indent, n->sibling, ss);

}

