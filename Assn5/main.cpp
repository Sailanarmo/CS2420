#include <time.h>
#include <iostream>
#include "Median.hpp"

int main() {
    const int TEST_VALUE = 10;
    srand(unsigned(time(0)));

    Median m;

    for (int i = 0; i < TEST_VALUE; ++i) {
        int num = rand() % 1000;
        m.addNum(num);
    }

    std::cout << m.report();// print Heaps
    std::cout << m.toString();

    return 0;
}
