#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "hashNode.hpp"

#include <vector>
#include <memory>


class Hashtable
{

public:

	Hashtable() : hashTable(10) {};

	int hashFunction(int key);
	int find(int key);
	
	void remove(int key);
	void rehash();
	void insert(int key, std::string item);
	void print();

private:
	int tableCount = 0;
	int tablesize = 10;
	std::vector<std::shared_ptr<hashNode>> hashTable;	

};



#endif
