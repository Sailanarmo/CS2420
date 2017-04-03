#include <iostream>

#include "hashtable.hpp" 


int Hashtable::hashFunction(int key)
{

	return key % tablesize;

}

void Hashtable::insert(int key, std::string item)
{
	//std::cout << key << std::endl;
	
	int index = linearProbe(hashFunction(key));

	auto nextPos = std::make_shared<hashNode>(key, item);
		
	hashTable[index] = nextPos;

	//hashTable[linearProbe(hashFunction(key))]=std::make_shared<hashNode>(key, item);
	rehash();	
	//print();
}

int Hashtable::linearProbe(int index)
{
	
	while(hashTable[index] != nullptr){
	
		if(index == static_cast<int>(hashTable.size()-1))
		{
			index = 0;
		}
		else
		{
		    ++index;
		}
	}

	return index;
}

void Hashtable::rehash()
{

	if(tableCount >= tablesize/2)
	{
		tableCount = 0;
		std::cout << "Rehashing" << std::endl;		
		tablesize = tablesize*2;

		std::vector<std::shared_ptr<hashNode>> tempTable;

		tempTable = hashTable;
		
		hashTable.clear();
		hashTable.resize(tablesize);
		
		for(std::shared_ptr<hashNode>& e : tempTable)
		{
			if(e)
			{
			    insert(e->key, e->item);
			}
		}

	}
	else
	{	
		tableCount++;
	}
}

void Hashtable::remove(int key)
{

	int target = hashFunction(key);

	int index = recursiveFind(key, target);

	if(index >= 0) 
	{
		std::cout << "Removing: " << hashTable[index]->item << std::endl;
		hashTable[index] = nullptr;
	}
	else
	{
		std::cout << "Item not found." << std::endl;
	}

	print();

}

void Hashtable::find(int key)
{

	int target = hashFunction(key);

	int index = recursiveFind(key, target);
	
	if(index >= 0) 
	{
		std::cout << "Found: " << hashTable[index]->item << std::endl;
	}
	else
	{
		std::cout << "Item not found." << std::endl;
	}
}

int Hashtable::recursiveFind(int key, int index)
{

	if(hashTable[index] == nullptr)
	{
		return -1;
	}
	else if(hashTable[index]->key != key)
	{
		recursiveFind(key, index+1);
	}
	else
	{
		return index; 
	}
	

}

void Hashtable::print()
{


	for(std::shared_ptr<hashNode>& e : hashTable)
	{
		if(e == nullptr)
		{
			std::cout << "[0,0]" << std::endl;
		}
		else
		{
		std::cout << "[" << e->key << ",'" << e->item;
		std::cout << "']" << std::endl;
		}
	}

	std::cout << std::endl;
}
