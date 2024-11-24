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
        List342(const List342<T>& other);

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

// Copy constructor
template <class T>
List342<T>::List342(const List342& list) {
    head_ = nullptr;
    *this = list; 
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
bool List342<T>::Insert(T* obj) {
    if (obj == nullptr) {
        return false;
    }

    T* new_obj = new T(*obj); 
    Node<T>* new_node = new Node<T>{new_obj, nullptr};

    if (head_ == nullptr || *(head_->data) > *new_obj) {
        if (head_ != nullptr && *(head_->data) == *new_obj) {
            delete new_node; 
            delete new_obj; 
            return false;
        }
        new_node->next = head_;
        head_ = new_node;
        return true;
    }

    Node<T>* current = head_;
    Node<T>* previous = nullptr;
    while (current != nullptr && *(current->data) < *new_obj) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr && *(current->data) == *new_obj) {
        delete new_node; 
        delete new_obj; 
        return false;
    }

    new_node->next = current;
    if (previous != nullptr) {
        previous->next = new_node;
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
    if (this == &list1 || !list1.head_) return false;
    if (!head_) { head_ = list1.head_; list1.head_ = nullptr; return true; }

    Node<T> dummy;
    Node<T>* tail = &dummy;
    Node<T>* a = head_;
    Node<T>* b = list1.head_;

    while (a && b) {
        if (*(a->data) < *(b->data)) {
            tail->next = a;
            a = a->next;
        }
        else if (*(b->data) < *(a->data)) {
            tail->next = b;
            b = b->next;
        }
        else {
            tail->next = a;
            a = a->next;
            delete b->data;
            Node<T>* temp = b;
            b = b->next;
            delete temp;
        }
        tail = tail->next;
    }

    tail->next = a ? a : b;
    head_ = dummy.next;
    list1.head_ = nullptr;
    return true;
}


template <class T>
List342<T> List342<T>::operator+(const List342<T> &list) const {
    List342<T> temp = list;
    List342<T> result = *this;
    result.Merge(temp);
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
    if (this == &list) return *this; 

    DeleteList(); 

    Node<T>* current = list.head_;
    Node<T>* last = nullptr;

    while (current != nullptr) {
        Node<T>* new_node = new Node<T>{
            new T(*(current->data)), 
            nullptr
        };

        if (head_ == nullptr) {
            head_ = new_node; 
        } else {
            last->next = new_node; 
        }

        last = new_node; 
        current = current->next;
    }

    return *this;
}

template <class U>
std::ostream &operator <<(std::ostream& stream, const List342<U> &list) { 
    Node<U>* cursor = list.head_;
    while(cursor != nullptr) {
        stream << *(cursor->data); 
        cursor = cursor->next;
    }return stream;
}
#endif