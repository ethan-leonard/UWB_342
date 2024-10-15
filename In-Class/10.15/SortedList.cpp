#ifndef SORTED_LIST_CPP_
#define SORTED_LIST_CPP_

#include <iostream>
#include <vector>
#include "SortedList.h"

template <class T>
SortedList<T>::SortedList() {
    
}

template <class T>
void SortedList<T>::add(const T& item) {
    list_.push_back(item);
}

template <class T>
void SortedList<T>::print() const {
    for (int i = 0; i < list_.size(); i++) {
        std::cout << list_[i] << std::endl;
    }
}


#endif