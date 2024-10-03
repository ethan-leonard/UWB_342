#include <iostream>
#include <string>
#include "mySwap.h"

using namespace std;

int main() {
    string name1 = "sue";
    string name2 = "ravi";
    
    cout << name1 << " " << name2 << endl;
    MySwap(name1, name2);
    cout << name1 << " " << name2 << endl;
}

