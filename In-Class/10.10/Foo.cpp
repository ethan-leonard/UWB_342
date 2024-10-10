#include <iostream>
#include <string>
#include "Foo.h"

Foo::Foo() {
    std::cout << "default" << std::endl;
    w_ = "empty";
}

Foo::Foo(std::string word) {
    w_ = word;
    std::cout << "alternative constructor: " << word << std::endl;
}