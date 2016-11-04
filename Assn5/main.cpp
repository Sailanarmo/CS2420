#include <time.h>
#include <iostream>
//#include "Median.h"
#include "SkewHeap.hpp"

int main() {
    const int TEST_VALUE = 15;
    srand(unsigned(time(0)));

    SkewHeap m;

    for (int i = 0; i < TEST_VALUE; ++i) {
        int num = rand() % 1000;
        m.addNum(num);
    }
    std::cout << m.report();  // print Heaps
    char c;
    int size = 32;
//    for (int i = TEST_VALUE; i < 1028; ++i) {
//        int num = rand() % 1000;
//        //std::cout << num << " ";
//        m.addNum(num);
//        if (i == size) {
//            //m.report();
//            size *= 2;
//        }
    //}
    std::cin >> c;
    return 0;
}