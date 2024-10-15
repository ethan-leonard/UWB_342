#include <iostream>
#include "SortedList.h"

int main() {

    SortedList<int> ages;
    ages.add(3);
    ages.add(4);
    ages.print();

    SortedList<std::string> names;
    names.add("Joe");
    names.add("Bob");
    names.print();


    return 1;
}