#include "binaryHeap.hpp"



void BinaryHeap::addNum(int data)
{
	std::cout << "Inserting: " << data << std::endl;
	binHeap.push_back(data);
	bubbleUp(binHeap.size()-1);
	toString();	
}


void BinaryHeap::toString()
{
	
	for(auto & e : binHeap)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;

}

void BinaryHeap::sortedString()
{

	for(auto & e : heapSort)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;

}

void BinaryHeap::removeMin()
{
	
	if(binHeap.size() == 0)
	{
		std::cout << "Heap is empty!" << std::endl;
		return;
	}

	std::cout << "Removing: " << binHeap[0] << std::endl;
	std::iter_swap(binHeap.begin(), binHeap.end()-1);
	heapSort.push_back(binHeap[binHeap.size() -1]);
	binHeap.pop_back();
	bubbleDown(0);
	toString();
		
}

void BinaryHeap::bubbleUp(int index)
{

	if(index && binHeap[parent(index)] > binHeap[index])
	{
		toString();
		std::swap(binHeap[index],binHeap[parent(index)]);

		bubbleUp(parent(index));
	}

}

void BinaryHeap::bubbleDown(int index)
{
	int leftChild = left(index);
	int rightChild = right(index);
	int smallestChild = index;

	if(leftChild < sizeOf() && binHeap[leftChild] < binHeap[index])
	{

		smallestChild = leftChild;
		toString();
	}

	if(rightChild < sizeOf() && binHeap[rightChild] < binHeap[smallestChild])
	{
		
		smallestChild = rightChild;
		toString();
	}

	if(smallestChild != index)
	{
		toString();
		std::swap(binHeap[index],binHeap[smallestChild]);
		bubbleDown(smallestChild);

	}

}

int BinaryHeap::left(int parent)
{
	return (2 * parent + 1);
}

int BinaryHeap::right(int parent)
{
	return (2 * parent + 2);
}

int BinaryHeap::parent(int child)
{
	return (child - 1) / 2;
}


