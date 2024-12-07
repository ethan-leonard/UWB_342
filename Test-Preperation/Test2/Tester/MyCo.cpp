// MyCo.h - No changes needed since it already has constructors/destructors declared

// MyCo.cpp - Add print statements to track calls
#include "MyCo.h" 
#include <iostream>

MyCo::MyCo() {
    count = 1;
    std::cout << "Default Constructor called, count = " << count << std::endl;
}

MyCo::MyCo(const MyCo& m) {
    this->count = m.count + 3;
    std::cout << "Copy Constructor called, count = " << count << std::endl;
}

MyCo::MyCo(int i) {
    count = i;
    std::cout << "Int Constructor called, count = " << count << std::endl;
}

MyCo& MyCo::Foo(MyCo m1, MyCo& m2, int c) {
    MyCo m = m1;
    m.count += c;
    m2.count += c;
    return m2;
}

MyCo::~MyCo() {
    std::cout << "Destructor called, count = " << count << std::endl;
}

