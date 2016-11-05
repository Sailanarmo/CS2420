#ifndef SKEW_HEAP_MIN_HPP
#define SKEW_HEAP_MIN_HPP

#include <memory>
#include "Node.hpp"

class SkewHeapMin{

public:

    SkewHeapMin() : minRoot(nullptr), sizeOfMinHeap(0), numOfMinMerge(0){}

    std::shared_ptr<Node> merge(std::shared_ptr<Node> & root1, std::shared_ptr<Node> root2);

    void addNum(int newValue);
    int size();
    int numHeap();
    int deleteMin();

    std::string toString();
    std::string toString(std::shared_ptr<Node> & root, int level);


private:

    std::shared_ptr<Node> minRoot;

    int sizeOfMinHeap;
    int numOfMinMerge;
};



#endif
