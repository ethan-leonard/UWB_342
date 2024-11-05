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

bool IntStack::insert(int value) {
    Node *insNode = new Node;
    insNode->value = value;

    if (head_ == nullptr) { // If empty list
        head_ = insNode;
        return true;
    } else if (value <= head_->value) { // If first in line
        insNode->next = head_;
        head_ = insNode;
        return true;
    } else { // Find spot
        Node* p_node = head_; // Current pointer

        while (p_node->next != nullptr && p_node->next->value < value) {
            p_node = p_node->next;
        }

        insNode->next = p_node->next;
        p_node->next = insNode;
        return true;
    }

}

bool IntStack::remove(int value) {
    if (head_ == nullptr) {
        return false; // Stack is empty
    }

    // If the node to be removed is the head node
    if (head_->value == value) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        return true;
    }

    // Find the node to be removed
    Node* p_node = head_;
    while (p_node->next != nullptr && p_node->next->value != value) {
        p_node = p_node->next;
    }

    // If the node was not found
    if (p_node->next == nullptr) {
        return false;
    }

    // Remove the node
    Node* temp = p_node->next;
    p_node->next = p_node->next->next;
    delete temp;
    return true;

}

std::ostream& operator<<(std::ostream& stream, const IntStack& st) {
    Node* p_node = st.head_;
    while (p_node != nullptr) {
        stream << p_node->value << " ";
        p_node = p_node->next;
    } return stream;
}

