#ifndef ASSN5_MEDIAN_HPP
#define ASSN5_MEDIAN_HPP


#include "SkewHeapMin.hpp"
#include "SkewHeapMax.hpp"
#include "Node.hpp"

#include <iostream>



class Median{

public:

    Median() : median(0){}

    void addNum(int value);
    std::string report();
    std::string toString();




    SkewHeapMin BigValues;
    SkewHeapMax SmallValues;

private:

    int median;

};





#endif
