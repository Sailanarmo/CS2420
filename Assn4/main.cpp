#include <iostream>

#include "hashtable.hpp"


int main(){

	Hashtable a;

	a.insert(4218, "Apricots");
	a.insert(4011, "Banana");
	a.insert(3177, "Beans Red");
	a.insert(4550, "Brussel Sprouts");
	a.print();
	a.insert(4062, "Cucumber");
	a.print();
	a.insert(4889, "Cilantro");
	a.insert(4430, "Pineapple");
	a.insert(4819, "Yucca");
	a.insert(4051, "Mango");
	a.print();
	a.insert(4048, "Limes");
	a.print();
	a.insert(4536, "Bean Sprouts");
	a.insert(4065, "Bell Pepper Green");
	a.insert(4039, "Plums Black");
	a.insert(4471, "Tuna");
	a.insert(4032, "Watermelon Seedless");
	a.insert(4472, "Tejocote");
	a.insert(4445, "Pomegranate");
	a.insert(4926, "Nuts Brazil");
	a.insert(4036, "Nectarines");
	a.print();
	a.insert(4870, "Jamaica");
	a.print();

	a.find(4218);
	a.find(4051);
	a.find(4039);

	a.remove(4926);
	a.remove(3177);
	a.remove(4471);

	a.find(4926);
	a.find(3177);
	a.find(4471);

	return 0;
}
