#ifndef HASH_NODE_HPP
#define HASH_NODE_HPP

//TODO: Make a node that takes a key and an item.

#include <string>

struct hashNode
{

	hashNode(int k, std::string i) : key(k), item(i){};

	int key;
	std::string item;

};


#endif
