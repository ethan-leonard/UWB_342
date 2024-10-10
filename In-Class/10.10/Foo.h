#ifndef FOO_H_
#define FOO_H_

#include <iostream>
#include <string>

class Foo {
    public:
        Foo();
        Foo(std::string word);

        ~Foo() {
            std::cout << "destructor: " << w_ << std::endl;
        }


        int x_;
        std::string w_;
};

#endif