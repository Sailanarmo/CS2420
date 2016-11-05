#include "SkewHeapMin.hpp"
#include <iostream>
#include <sstream>

std::shared_ptr<Node> SkewHeapMin::merge(std::shared_ptr<Node> & root1, std::shared_ptr<Node> root2) {


    if(!root1) return root2;
    if(!root2) return root1;

    std::shared_ptr<Node> small;
    std::shared_ptr<Node> temp;

    if(root1->value < root2->value){
        small = root1;
        root1->right = merge(root1->right, root2);
        numOfMinMerge++;
    }
    else{
        small = root2;
        root2->right = merge(root2->right, root1);
        numOfMinMerge++;
        temp = root2->right;
        root2->right = root2->left;
        root2->left = temp;
    }

    return small;
}


void SkewHeapMin::addNum(int newValue) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(newValue);

    //std::cout << "MinVal: " << newValue << std::endl;
    sizeOfMinHeap++;
    minRoot = merge(newNode, minRoot);
}

int SkewHeapMin::size() {
    return sizeOfMinHeap;
}

int SkewHeapMin::numHeap() {
    return numOfMinMerge;
}

int SkewHeapMin::deleteMin() {

    int value = minRoot->value;

    minRoot = merge(minRoot->left, minRoot->right);
    sizeOfMinHeap--;

    return value;
}

std::string SkewHeapMin::toString() {
    std::stringstream ss;

    ss << toString(minRoot, 1);

    return ss.str();
}

std::string SkewHeapMin::toString(std::shared_ptr<Node> &root, int level) {
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