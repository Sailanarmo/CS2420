#include <iostream>
#include <chrono>

#include "binaryHeap.hpp"
#include "random.hpp"


int main()
{

	BinaryHeap a;
	std::vector<int> b;


	int next;
	double time;
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::high_resolution_clock::now();
	
	for (int i = 0; i < 1000000; ++i)
	{
		next = rand(0,1000);
		a.addNum(next);
		b.push_back(next);	
	}

	end = std::chrono::high_resolution_clock::now();

	time = std::chrono::duration<double,std::milli>(end - start).count();

	std::cout << "It took: " << time << " milliseconds to sort 1 million random numbers with Heap Sort." << std::endl;


	start = std::chrono::high_resolution_clock::now();

	std::sort(b.begin(), b.end());
	
	end = std::chrono::high_resolution_clock::now();

	time = std::chrono::duration<double,std::milli>(end - start).count();
	
	std::cout << "It took: " << time << " milliseconds to sort 1 million random numbers with std::sort." << std::endl;
	return 0;
}
