#include <iostream>
#include "bst.hpp"
#include "avl.hpp"


int main()
{

	int answer = 0;

	std::cout << "Which version of the program would you like to run?" << std::endl;

	std::cout << "Press 1 for Binary Search Tree." << std::endl;
	std::cout << "Press 2 for AVL Search Tree." << std::endl;
	
	std::cin >> answer;

	while(answer != 1 && answer != 2){
		std::cout << "Please enter 1 for BST, or 2 for AVL implementation: " << std::endl;
		std::cin >> answer;
	}

	if (answer == 1){
		BST a("nums.txt");
	}
	if (answer == 2){
		AVL a("nums.txt");
	}

	return 0;


}
