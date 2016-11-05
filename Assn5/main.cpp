#include <iostream>
#include <time.h>

#include "Median.hpp"


int main()
{
    const int TEST_VALUE = 10;

    srand(unsigned (time(0)));
    
    Median m;

    for (int i = 0; i < TEST_VALUE; ++i)
    {
        int num = rand() % 100;
        m.addNum(num);
    }

    std::cout << m.report();
    std::cout << m.toString();

    return 0;
}
