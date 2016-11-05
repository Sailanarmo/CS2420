#include "SkewHeapMax.hpp"
#include <iostream>
#include <sstream>

std::shared_ptr<Node> SkewHeapMax::merge(std::shared_ptr<Node> &root1, std::shared_ptr<Node> root2) {

    if(!root1) return root2;
    if(!root2) return root1;

    std::shared_ptr<Node> large;
    std::shared_ptr<Node> temp;

    if(root1->value > root2->value){
        large = root1;
        root1->left = merge(root1->left, root2);
        numOfMaxMerge++;
    }
    else{
        large = root2;
        root2->left = merge(root2->left, root1);
        numOfMaxMerge++;
        temp = root2->right;
        root2->right = root2->left;
        root2->left = temp;
    }

    return large;
}

void SkewHeapMax::addNum(int newValue) {

    std::shared_ptr<Node> newNode = std::make_shared<Node>(newValue);

    //std::cout << "MaxVal: " << newValue << std::endl;

    sizeOfMaxHeap++;
    maxRoot = merge(newNode,maxRoot);
}

int SkewHeapMax::size() {
    return sizeOfMaxHeap;
}

int SkewHeapMax::numHeap() {
    return numOfMaxMerge;
}

int SkewHeapMax::deleteMax(){

    int value = maxRoot->value;

    maxRoot = merge(maxRoot->right, maxRoot->left);
    sizeOfMaxHeap--;

    return value;

}

std::string SkewHeapMax::toString() {
    std::stringstream ss;

    ss << toString(maxRoot, 1);

    return ss.str();
}

std::string SkewHeapMax::toString(std::shared_ptr<Node> &root, int level) {
    std::stringstream ss;

    if (!root) return "";

    ss << toString(root->right, level + 1);

    for (int i = 0; i < level; ++i) {

        ss << "    ";

    }

    ss << root->value << std::endl;

    ss << toString(root->left, level + 1);

    return ss.str();
}