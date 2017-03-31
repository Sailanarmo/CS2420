#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "hashNode.hpp"

#include <vector>

class Hashtable
{

public:

	int hashFunction(int key);
	void insert(int key, std::string item);
	int find(int key);
	void remove(int key);
	 

private:

	int tablesize = 10;
	std::vector<std::vector<hashNode>> hashTable;	

};



#endif

