#ifndef BINARY_HEAP
#define BINARY_HEAP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class BinaryHeap
{

public:

	void addNum(int data);
	void toString();
	void removeMin();

private:

	std::vector<int> binHeap;

	void bubbleUp(int index);
	void bubbleDown(int index);

	int left(int parent);
	int right(int parent);
	int parent(int child);

	int sizeOf() { return binHeap.size(); }
};



#endif
