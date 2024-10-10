#include <iostream>
#include <string>
#include <vector>
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

    Rational r(1, 3);
    Rational r2(1, 3);

    r2 *= r;

    std::cout << r2 << std::endl;

    std::vector<Rational> rationals;
    rationals.push_back(r);
    rationals.push_back(r2);

    for (int i = 0; i < rationals.size(); i++) {
        std::cout << rationals.at(i) << std::endl;
    }

    return 0;
}

