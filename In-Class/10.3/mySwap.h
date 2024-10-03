#include <iostream>
#include <string>

using namespace std;

void MySwap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}