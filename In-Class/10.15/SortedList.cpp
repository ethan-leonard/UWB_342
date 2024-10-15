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

template <class T>
void SortedList<T>::sort() {
    bool swapped;
    for (int i = 0; i < list_.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < list_.size() - i - 1; j++) {
            if (list_[j] > list_[j + 1]) {
                std::swap(list_[j], list_[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

template <class T>
void SortedList<T>::isort() {
    for (int i = 1; i < list_.size(); i++) {
        T key = list_[i];
        int j = i - 1;

        // Move elements of list_[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && list_[j] > key) {
            list_[j + 1] = list_[j];
            j = j - 1;
        }
        list_[j + 1] = key;
    }
}

#endif