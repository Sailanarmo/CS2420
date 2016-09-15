#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <sstream>

template<typename T>
struct Node {

    T data;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;

    Node(T t, std::shared_ptr<Node> p = nullptr, std::shared_ptr<Node> n = nullptr) : data(t), prev(p), next(n) { }
};

template<typename T>
class LinkedList {

public:

    LinkedList() : head(nullptr), tail(nullptr) { }

    void push_Back(T);

    //void push_Front(T);

    T pop();

    T back();

    void clear() { recurClear(head); head = tail = nullptr; }

    //std::string toString();

    int sizeOf() { return sizeOfRecur(head); }

private:

    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

    void recurClear(std::shared_ptr<Node<T>> curr);

    int sizeOfRecur(std::shared_ptr<Node<T>>);
};

template<typename T>
void LinkedList<T>::push_Back(T t) {

    if (!head) {
        head = tail = std::make_shared<Node<T>>(t);
        return;
    }

    tail->next = std::make_shared<Node<T>>(t, nullptr, tail);
    tail = tail->next;
}

//template<typename T>
//void LinkedList<T>::push_Front(T t) {
//
//    if (!head) {
//        head = tail = std::make_shared<Node<T>>(t);
//        return;
//    }
//
//    head->prev = std::make_shared<Node<T>>(t, head, nullptr);
//    head = head->prev;
//}

template<typename T>
T LinkedList<T>::pop() {
    //td::cout << "pop" << std::endl;
    if (!head) {
        throw std::domain_error("Out of range :(");
        //return 0;
    }

    auto temp = head;
    if (!head->next) {
        head = tail = nullptr;
        return temp->data;
    }

    head = head->next;
    head->prev = nullptr;

    return temp->data;
}

template<typename T>
T LinkedList<T>::back() {

    if (!tail) {
       throw std::domain_error("The list is empty.");
        //return 0;
    }

    return tail->data;
}

template<typename T>
void LinkedList<T>::recurClear(std::shared_ptr<Node<T>> curr) {

    if (!curr) {
        //throw std::domain_error("Bad things have happened, aborting. :( :( ");
        return;
    }

    curr->prev = nullptr;
    recurClear(curr->next);
}

//template<typename T>
//std::string LinkedList<T>::toString() {
//
//    std::stringstream ss;
//
//    for (auto curr = head; curr != nullptr; curr = curr->next) {
//        ss << curr->data << " ";
//    }
//
//    ss << std::endl;
//
//    return ss.str();
//}

template<typename T>
int LinkedList<T>::sizeOfRecur(std::shared_ptr<Node<T>> curr) {

    if (!curr) return 0;

    return 1 + sizeOfRecur(curr->next);
}


#endif
