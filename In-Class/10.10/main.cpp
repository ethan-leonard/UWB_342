#include <iostream>
#include <string>
#include <vector>
#include "Foo.h"


Foo obj_global("");

void MyFunc();

template<class T>
void Swap(T& a, T& b) {
    T tmp = a;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    std::vector<int> first;
    std::vector<int> second = {100, 200, 300};
    std::vector<int> third = second;
    std::vector<int> fourth{4, 100};
    second.push_back(400);

    double x = 5;
    double y = 7;

    std::cout << x << y << std::endl;
    Swap(x, y);
    std::cout << x << y << std::endl;

    std::string name1 = "Sue";
    std::string name2 = "Ravi";

    std::cout << name1 << name2 << std::endl;
    Swap(name1, name2);
    std::cout << name1 << name2 << std::endl;


    Foo object_local_a("local");
    
    for (int i = 1; i <= 3; i++) {
        static Foo obj_static("static");
        Foo obj_local("local: " + std::to_string(i));
        Foo* obj_dynamic;
        obj_dynamic = new Foo("dynamic");
        delete obj_dynamic;
    }
}

void MyFunc() {
    Foo another_local("another local");
    another_local.x_ = 5;
}

