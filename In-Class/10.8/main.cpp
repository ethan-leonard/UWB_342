#include <iostream>
#include <string>
#include "Rational.h"

std::string reverseString(std::string &s) {
    std::string temp = s;
    std::string reverser = "";

    for (int i = s.length()-1; i >= 0; i--) {
        reverser += s[i];
    }

    s = reverser;
    return temp;

}

int main() {
    std::string j = "hello";
    std::cout << reverseString(j) << std::endl;

    Rational r(1, 10);

    std::cout << r.getTop() << "/" << r.getBottom() << std::endl;


    return 0;
}

