#include <iostream>

using namespace std;

int main() {
    int a  = 0;
    int b = 0;
    
    cout << "Enter integer a: ";
    cin >> a;
    cout << "Enter integer b: ";
    cin >> b;

    if (a > b) {
        cout << "a is greater than b" << endl;
    } else if (a == b) {
        cout << "a is equal to b" << endl;
    } else {
        cout << "a is less than b" << endl;
    }
    
    return 0;
}