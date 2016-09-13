#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>


template <typename T>
struct Node{

    T data;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;
    Node(T t, std::shared_ptr<Node> list = nullptr) : data(t), prev(list), next(list){}
};

template <typename T>
void insertN(std::shared_ptr<Node<T>> &list, T data){

    if(!list){
	list = std::make_shared<Node<T>>(data);
    } else if(list->data > data){
	auto temp = std::make_shared<Node<T>>(data, list);
    } else {
	insertN(list->next, data);
    }
}

template <typename T>
void removeN(std::shared_ptr<Node<T>> &list, T target){

    if(!list) return;
    if(target == list->data){
	list = list->next;
    } else {
	removeN(list->next, target);
    }
}

template <typename T>
class LinkedList{

public:
    
    LinkedList();


private: 

    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> prev;

};


#endif
