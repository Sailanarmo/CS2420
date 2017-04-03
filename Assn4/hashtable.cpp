#include <iostream>

#include "hashtable.hpp" 


int Hashtable::hashFunction(int key)
{

	return key % tablesize;

}

void Hashtable::insert(int key, std::string item)
{
	std::cout << key << std::endl;
	
	int index = hashFunction(key);

	if (!hashTable[index])
	{
		auto pos = std::make_shared<hashNode>(key, item);
		hashTable[index] = pos;
	}
	else
	{

		auto nextPos = std::make_shared<hashNode>(key, item);
		
		for(int i = 0; i < tablesize; ++i)
		{
			int temp = (index + i) % tablesize;
			std::cout << temp << std::endl;
			
			if(!hashTable[temp])
			{
				hashTable[temp] = nextPos;
				break;
			}
		}
	}

	rehash();	
	print();
}

void Hashtable::rehash()
{

	if(tableCount == tablesize/2)
	{
//		tablesize = tablesize*2;
		std::cout << "Rehashing" << std::endl;		

	}
	
	tableCount++;
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
		std::cout << "[" << e->key << "," << e->item;
		std::cout << "]" << std::endl;
		}
	}


}
