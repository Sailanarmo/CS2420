#ifndef ASSN5_SKEWHEAP_HPP
#define ASSN5_SKEWHEAP_HPP

#include <memory>

struct Node{

    //Node with a value in it's constructor
    Node(int v) : value(v){};

    int value;
    std::shared_ptr<Node> left = nullptr;
    std::shared_ptr<Node> right = nullptr;

};

class SkewHeap{

public:

    SkewHeap();

    void insert(std::shared_ptr<Node> & root, std::shared_ptr<Node> newNode, bool isMin);
    void addNum(int newValue);
    std::string report();
    std::string report(std::shared_ptr<Node> root, int level);

    const std::shared_ptr<Node> &getCurrMedian() const {
        return currMedian;
    }



private:

    std::shared_ptr<Node> minRoot = nullptr;
    std::shared_ptr<Node> maxRoot = nullptr;
    std::shared_ptr<Node> currMedian = nullptr;

    int sizeOfMinHeap = 0;
    int sizeOfMaxHeap = 0;
    int numMergeMinHeap = 0; // number of merges needed in the min heap
    int numMergeMaxHeap = 0; // number of merges needed in the max heap

};






#endif
