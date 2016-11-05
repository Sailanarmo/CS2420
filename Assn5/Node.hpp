#ifndef ASSN5_NODE_HPP
#define ASSN5_NODE_HPP

#include <memory>

struct Node{

    //Node with a value in it's constructor
    Node(int v) : value(v){};

    int value;
    std::shared_ptr<Node> left = nullptr;
    std::shared_ptr<Node> right = nullptr;

};


#endif