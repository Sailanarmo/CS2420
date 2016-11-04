#include "SkewHeap.hpp"
#include <sstream>
#include <iostream>


SkewHeap::SkewHeap() { }


void SkewHeap::insert(std::shared_ptr<Node> &root, std::shared_ptr<Node> newNode, bool isMin) {

    std::shared_ptr<Node> temp = nullptr;

    std::cout << "Inserting: " << newNode->value << std::endl;

    if (!root) {
        root = newNode;
        return;
    }

    if (!isMin) {
        if (newNode->value > root->value) {
            newNode->left = root;
            root = newNode;
        }
        else {
            insert(root->right, newNode, isMin);
            temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
    }

    if (isMin) {
        if (newNode->value < root->value) {
            newNode->left = root;
            root = newNode;
        }
        else {
            insert(root->right, newNode, isMin);
            temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
    }

}

void SkewHeap::addNum(int newValue) {


    std::shared_ptr<Node> newNode = std::make_shared<Node>(newValue);


    if (!currMedian) {
        currMedian = newNode;
        //std::cout <<"PLS: " << currMedian->value << std::endl;
    }

    if (newValue < currMedian->value) {
        sizeOfMaxHeap++;
        insert(maxRoot, newNode, false);
    }
    else if (newValue > currMedian->value) {
        sizeOfMinHeap++;
        insert(minRoot, newNode, true);
    }

    return;
}

std::string SkewHeap::report() {

    //creating a string stream object	
    std::stringstream ss;
    ss <<
    report(minRoot, 1); // calling the recursive report to print out the min skewHeap first, giving 1 at it's level.
    ss << report(currMedian, 0); //calling the recursive report to print out the median value, being at level 0.
    ss << report(maxRoot, 1); //calling the recursive reprt to print out max skewHeap last, being at level 1.

    return ss.str(); //returning the stringstream object.
}

std::string SkewHeap::report(std::shared_ptr<Node> root, int level) {

    std::stringstream ss;


    if (!root) return "";

    //std::cout << root->value << std::endl;
    ss << report(root->right, level + 1);

    for (int i = 0; i < level; ++i) {

        ss << "    ";

    }

    ss << root->value << std::endl;

    ss << report(root->left, level + 1);

    return ss.str();


}
