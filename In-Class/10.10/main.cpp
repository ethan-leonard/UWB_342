#include <iostream>
#include <string>
#include "Foo.h"

Foo obj_global("");

void MyFunc();

int main() {
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