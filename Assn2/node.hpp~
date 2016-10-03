#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <memory>

struct Node
{

    Node(std::string w ="", int k = 0, std::shared_ptr<Node> c = nullptr, std::shared_ptr<Node> s = nullptr, std::shared_ptr<Node> p = nullptr): word(w), kid(k), child(c), sibling(s), parent(p){}

    std::shared_ptr<Node> child;
    std::shared_ptr<Node> sibling;
    std::shared_ptr<Node> parent;
    int subNodes;
    int kid;
    std::string word;
};


#endif
