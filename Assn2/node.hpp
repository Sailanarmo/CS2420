#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <memory>

struct Node
{

    Node(std::string w ="", int k = 0, std::shared_ptr<Node> p = nullptr, std::shared_ptr<Node> c = nullptr, std::shared_ptr<Node> s = nullptr): word(w), kid(k), head(p), left(c), right(s) {}

    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> head;
    int kid;
    std::string word;
};


#endif
