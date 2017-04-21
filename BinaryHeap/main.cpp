#include <iostream>
#include "binaryHeap.hpp"


int main()
{

	BinaryHeap a;
	
	a.addNum(2);
	a.addNum(3);
	a.addNum(7);
	a.addNum(22);
	a.addNum(5);
	a.addNum(21);
	a.addNum(1);
	a.addNum(28);
	a.addNum(4);
	a.addNum(16);
	a.addNum(0);
	a.addNum(17);
	a.addNum(12);
	a.addNum(18);
	a.addNum(20);
	a.addNum(25);

	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();
	a.removeMin();

	std::cout << std::endl;
	
	std::cout << "Sorted List: ";
	a.sortedString();
	return 0;

}
