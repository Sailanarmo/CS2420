#include <iostream>


int iterateList(int r){
	if (r==0) return r;

    //std::cout << r << " + ";	
	return r + iterateList(r-1);
}


int main(){
	int r = 1000;
	
	std::cout <<" = " << iterateList(r) << std::endl;

}
