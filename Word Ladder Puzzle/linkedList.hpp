#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <sstream>

template <typename T>
struct Node{

    T data;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;
    Node(T t, std::shared_ptr<Node> p = nullptr, std::shared_ptr<Node> n = nullptr) : data(t), prev(p), next(n){}
};

template <typename T>
class LinkedList{

public:
    
    LinkedList() : head(nullptr) {}

    void pushBack(T);
    void pushFront(T);
    T popOff();
    T pushOff();
    void clear() { recurClear(head) : head = tail = nullptr; };
    std::string toString();
    int sizeOf(){ return sizeOfRecur(head); }

private: 

    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> prev;

    void recurClear(std::shared_ptr<Node> curr);
};

template <template T>
void LinkedList<T>::pushBack(T t){
 
    if(!head){
	 head = tail = std::make_shared<Node>(d);
	 return;
    }

    tail->next = std::make_shared<Node>(d, nullptr, tail);
    tail = tail->next;
}

template <template T>
void LinkedList<T>::pushFront(T t){

    if(!head){
	head = tail = std::make_shared<Node>(d);
	return;
    }

    head->prev = std::make_shared<Node>(d, head, nullptr);
    head = head->prev;
}

template <template T>
T LinkedList<T>::popOff(){

    if(!head){
	std::cout << "No list found, aborting!!" << std::endl;
	return nullptr;
    }

    auto temp = head;
    if(head->next){
	head = tail = nullptr;
	return temp->data;
    }

    head = head->next;
    head->prev = nullptr;
    return temp->data;
}

template <template T>
T LinkedList<T>::pushOff(){

    if(!tail){
	std::cout << "The list is empty, aborting!! " << std::endl;
        return nullptr;
    }

    tail->data;
}

template <template T>
void LinkedList<T>::recurClear(std::shared_ptr<Node> curr){

    if(!curr){
	return;
    }
    
    curr->prev = nullptr;
    recurClear(curr->next);
}

template <template T>
std::string LinkedList<T>::toString(){

    std::stringstream ss;

    for(auto curr = head; curr != nullptr; curr=curr->next){
	ss << curr->data << " ";
    }

    ss << std::endl;

    return ss.str();
}

template <template T>
int LinkedList<T>::sizeOfRecur(std::shared_ptr<Node> curr){

    if(!curr){
	return;
    }

    return 1 + sizeOfRecur(curr->next);
}




#endif
