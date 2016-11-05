#include "Median.hpp"

#include <sstream>


void Median::addNum(int value) {
    std::cout << "Inserting: " << value << std::endl;
    if(BigValues.size() == 0 && SmallValues.size() == 0 && median == 0){
        median = value;
        return;
    }

    if(value > median){
        BigValues.addNum(value);
    }
    else {
        SmallValues.addNum(value);
    }

    if (BigValues.size() > SmallValues.size() + 1){
        SmallValues.addNum(median);
        median = BigValues.deleteMin();
    }
    if (BigValues.size() < SmallValues.size() - 1){
        BigValues.addNum(median);
        median = SmallValues.deleteMax();
    }



}

std::string Median::report() {
    //creating a string stream object
    std::stringstream ss;

    ss << "Median: " << median << std::endl;
    ss << "Size of MinHeap: " << BigValues.size() << " ";
    ss << "Size of MaxHeap: " << SmallValues.size() << std::endl;
    ss << "Number of MinHeap Merges: " << BigValues.numHeap() << " ";
    ss << "Number of MaxHeap Merges: " << SmallValues.numHeap() << std::endl;

    return ss.str(); //returning the stringstream object.
}

std::string Median::toString() {
    std::stringstream ss;

    ss << "MinHeap: " << std::endl << BigValues.toString() << std::endl;
    ss << "Median: " << std::endl << median << std::endl;
    ss << "MaxHeap: " << std::endl << SmallValues.toString() << std::endl;

    return ss.str();
}
