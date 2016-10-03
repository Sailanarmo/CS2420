#ifndef TREE_STARTER_HPP
#define TREE_STARTER_HPP

#include <fstream>
#include <memory>
#include <string>
#include <sstream>

#include "node.hpp"


class Tree {

public:
	Tree() : root(nullptr) { }

	void makeEmpty() { makeEmpty(root); }

	void makeEmpty(std::shared_ptr<Node> &r);

	void printTree(std::string indent, std::shared_ptr<Node> n);

	void printTree(std::string indent = "   ");

	std::string toPreorder(std::shared_ptr<Node> n);

	std::string toPreorder();

	std::shared_ptr<Node> preorderBuild(std::ifstream &inf);

	std::shared_ptr<Node> preorderBuild(std::ifstream &inf, std::shared_ptr<Node> parent);

	int countNodes(std::shared_ptr<Node> root);

	std::shared_ptr<Node> findWord(std::string word, std::shared_ptr<Node> r);

	std::shared_ptr<Node> findWord(std::string word) { return findWord(word, root); }

	void upCase(std::shared_ptr<Node> n);

	void upCase() { upCase(root); }

	Tree clone();

	std::shared_ptr<Node> clone(std::shared_ptr<Node> n, std::shared_ptr<Node> p);

	int fringe() { return fringe(root); }

	int fringe(std::shared_ptr<Node> n);

	int nodesInLevel(int level) { return nodesInLevel(level, root); }

	int nodesInLevel(int level, std::shared_ptr<Node> r);

	bool isIsomorphic(Tree &t2) { return isIsomorphic(root, t2.root); }

	bool isIsomorphic(std::shared_ptr<Node> r1, std::shared_ptr<Node> r2);

	std::string commonAncestor(std::string s1, std::string s2);

	std::shared_ptr<Node> commonAncestor(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2);


private:
	std::shared_ptr<Node> root;
};

#endif
