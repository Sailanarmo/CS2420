#include <iostream>

#include "hashtable.hpp"


int main(){

	Hashtable a;

	a.insert(4218, "Apricots");
	a.insert(4011, "Banana");
	a.insert(3177, "Beans Red");
	a.insert(4550, "Brussel Sprouts");
	a.find(3177);
	a.insert(4062, "Cucumber");

	a.remove(4011);

	a.insert(4889, "Cilantro");
	a.insert(4430, "Pineapple");

	a.insert(4819, "Yucca");
	
	a.insert(4051, "Mango");
	a.insert(4048, "Limes");


//	std::cout << "PLZ" << std::endl;
	return 0;
}
