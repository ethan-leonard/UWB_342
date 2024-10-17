#include <iostream>
#include "SortedList.h"

int main() {

    SortedList<int> ages;
    ages.add(3);
    ages.add(4);
    ages.add(15);
    ages.add(1);
    ages.add(8);
    ages.sort();
    ages.print();

    SortedList<std::string> names;
    names.add("Joe");
    names.add("Bob");
    names.add("Money");
    names.add("Joseph");
    names.add("Yessuh");
    names.add("Superduperlongname");
    names.add("Hi");
    names.sort();
    names.print();


    return 1;
}