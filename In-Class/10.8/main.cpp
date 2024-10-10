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

    Rational r(1, 4);
    Rational r2(1, 4);

    Rational r3 = r+r2;

    std::cout << r3.getTop() << "/" << r3.getBottom() << std::endl;

    return 0;
}

