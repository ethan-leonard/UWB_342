#ifndef LIST342_H_
#define LIST342_H_

#include <iostream>
#include <string>
#include <fstream>

template <class T>
struct Node {
    T* data;
    Node* next;
};

template <class T>
class List342 {
    private:

        Node<T>* head_;

    public:
        List342();
        ~List342();

        // Builds an order list from objects in an file
        bool BuildList(std::string file_name);

        // Inserts an object into its correct place within the list
        bool Insert(T* obj);

        // Removes target item from the list
        bool Remove(T target, T& result);

        // Peeks target item from the list
        bool Peek(T target, T& result) const;

        // Returns number of items in the list
        int Size() const;

        // Removes all items from the list
        void DeleteList();

        // Merges inputted list with the list
        bool Merge(List342& list1);

        // Overloads
        List342<T> operator+(const List342<T> &list) const;
        List342<T>& operator+=(const List342<T> &list);
        bool operator==(const List342<T> &list) const;
        bool operator!=(const List342<T> &list) const;
        List342<T>& operator=(const List342<T> &list);

        template <class U>
        friend std::ostream& operator<<(std::ostream& out_stream, const List342<U>& list);

};

// Constructor
template <class T>
List342<T>::List342() {
    head_ = nullptr;
}

// Deconstructor 
template <class T> 
List342<T>::~List342() {
    if (head_ != nullptr) {
        DeleteList();
    }
}

template <class T>
bool List342<T>::BuildList(std::string file_name) {
    std::ifstream in_file(file_name);

    // If not in file
    if (!in_file) {
        return false;
    }

    T obj; 
    while (in_file >> obj) {
        Insert(&obj);
    }

    in_file.close();
    return true;

}

template <class T>
bool List342<T>::Insert(T* val) {
    if(val == nullptr){
        return false;  
    }

    Node<T>* cursor = head_;

    while (curr != nullptr) {
        if (*(cursor->data) == *val) {
            return false; 
        }
        cursor = curr->next;
    }

    Node<T>* insert_node = new Node<T>;
    insert_node->data = new T(*val);

    if (head_ == nullptr || *val < *(head_->data)) {
        insert_node->next = head_;
        head_ = insert_node;
        return true;
    }

    Node<T>* prev = nullptr;
    cursor = head_;
    while (cursor != nullptr && *(cursor->data) < *val) {
        prev = cursor;
        cursor = curr->next;
    }
    if(prev == nullptr){
        delete insert_node->data;
        delete insert_node;

    }else{

    insert_node->next = cursor;
    prev->next = insert_node;
    }
    return true;
}

template <class T> 
bool List342<T>::Remove(T target, T& result) {
    // Empty list
    if (head_ == nullptr) {
        return false;
    }

    Node<T>* current = head_;
    Node<T>* previous = nullptr;

    // Go through list to find
    while (current != nullptr && *(current->data) != target) {
        previous = current;
        current = current->next;
    }

    // If not found 
    if (current == nullptr)  {
        return false;
    } else { // If found
        result = *(current->data);
        if (previous == nullptr) {
            head_ = current->next;
        } else {
            previous->next = current->next;
        }
        delete current->data;
        delete current;
        return true;
    }

}

template <class T>
bool List342<T>::Peek(T target, T& result) const {
    // Empty list
    if (head_ == nullptr) {
        return false;
    }

    Node<T>* current = head_;

    // Go through list to find
    while (current != nullptr && *(current->data) != target) {
        current = current->next;
    }

    // If not found 
    if (current == nullptr)  {
        return false;
    } else { // If found
        result = *(current->data);
        return true;
    }
}

template <class T>
int List342<T>::Size() const {
    if (head_ == nullptr) {
        return 0;
    } else {
        Node<T>* current = head_;

        int size = 0;

        while (current != nullptr) {
            size++;
            current = current->next;
        } return size;
    }
}

template <class T>
void List342<T>::DeleteList() {
    Node<T>* current = head_;
    Node<T>* next_node = nullptr;

    while (current != nullptr) {
        next_node = current->next;
        delete current->data;
        delete current;
        current = next_node;
    }

    head_ = nullptr;
}

template <class T>
bool List342<T>::Merge(List342& list1) {
    if (this == &list1 || list1.head_ == nullptr) {
        return false;
    }

    Node<T>* current1 = head_;
    Node<T>* current2 = list1.head_;
    Node<T>* previous1 = nullptr;

    while (current2 != nullptr) {
        Node<T>* next2 = current2->next;

        while (current1 != nullptr && *(current1->data) < *(current2->data)) {
            previous1 = current1;
            current1 = current1->next;
        }

        if (current1 != nullptr && *(current1->data) == *(current2->data)) {
            current2 = next2;
            continue;
        }

        if (previous1 == nullptr) {
            current2->next = head_;
            head_ = current2;
        } else {
            previous1->next = current2;
            current2->next = current1;
        }
        previous1 = current2;
        current2 = next2;
    }

    list1.head_ = nullptr;
    return true;
}

template <class T>
List342<T> List342<T>::operator+(const List342<T>& list) const {
    List342<T> result;
    Node<T>* current1 = head_;
    Node<T>* current2 = list.head_;

    while (current1 != nullptr && current2 != nullptr) {
        if (*(current1->data) < *(current2->data)) {
            result.Insert(new T(*(current1->data)));
            current1 = current1->next;
        } else if (*(current2->data) < *(current1->data)) {
            result.Insert(new T(*(current2->data)));
            current2 = current2->next;
        } else {
            result.Insert(new T(*(current1->data)));
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != nullptr) {
        result.Insert(new T(*(current1->data)));
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        result.Insert(new T(*(current2->data)));
        current2 = current2->next;
    }

    return result;
}

template <class T>
List342<T>& List342<T>::operator+=(const List342<T>& list) {
    *this = *this + list;
    return *this;
}

template <class T>
bool List342<T>::operator==(const List342<T>& list) const {
    Node<T>* current1 = head_;
    Node<T>* current2 = list.head_;

    while (current1 != nullptr && current2 != nullptr) {
        if (*(current1->data) != *(current2->data)) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    } return (current1 == nullptr && current2 == nullptr);
}

template <class T>
List342<T>& List342<T>::operator=(const List342<T>& list) {
    if (this == &list) {
        return *this;
    }

    DeleteList();

    Node<T>* current = list.head_;
    while (current != nullptr) {
        Insert(new T(*(current->data)));
        current = current->next;
    } return *this;
}

template <class U>
std::ostream &operator <<(std::ostream& stream, const List342<U> &list) { 
    Node<U>* cursor = list.head_;
    while(cursor != nullptr) {
        stream << *(cursor->data); //print data individually
        cursor = cursor->next;
    }return stream;
}
#endif