#ifndef SKEW_HEAP_MAX_HPP
#define SKEW_HEAP_MAX_HPP

#include <memory>
#include "Node.hpp"

class SkewHeapMax{

public:

    SkewHeapMax() : maxRoot(nullptr), sizeOfMaxHeap(0), numOfMaxMerge(0){}

    std::shared_ptr<Node> merge(std::shared_ptr<Node> & root1, std::shared_ptr<Node> root2);
    void addNum(int newValue);
    int size();
    int numHeap();
    int deleteMax();

    std::string toString();
    std::string toString(std::shared_ptr<Node> & root, int level);

private:

    std::shared_ptr<Node> maxRoot;

    int sizeOfMaxHeap;
    int numOfMaxMerge;
};



#endif
