#include <iostream>
#include "intStack.h"

IntStack::IntStack() : head_(nullptr) {}

IntStack::~IntStack() {
    /*
    while (head_ != nullptr) {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp;
    } */

   int x;
   while(pop(x));
}

bool IntStack::push(int value) {
    Node* insert_node = new Node();
    insert_node->value = value;
    insert_node->next = head_;
    head_ = insert_node;
    return true;
}

bool IntStack::pop(int& value) {
    if (head_ == nullptr) {
        return false;
    } else {
        Node* tmp = head_;
        head_ = head_->next;
        value = tmp->value;
        delete tmp;
    } return true;
}

std::ostream& operator<<(std::ostream& stream, const IntStack& st) {
    Node* p_node = st.head_;
    while (p_node != nullptr) {
        stream << p_node->value << " ";
        p_node = p_node->next;
    } return stream;
}

