#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <iostream>
#include <vector>


template <class T>
class SortedList {
    private:
        std::vector<T> list_;

    public:
        // Constructor
        SortedList();

        // Getters and Setters
        void add(const T& item);
        void print() const;
        void sort();

    
    
};

#include "SortedList.cpp"
#endif