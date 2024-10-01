#include <iostream>
#include <string>

using namespace std;


int main() {
    string input = "";
    string temp = "";

    cout << "Enter a string: ";
    cin >> input;

    // Better way would be to compare first and last letter and move towards the middle
    for (int i = input.length() - 1; i >= 0; i--) {
        temp += input[i];
    }

    if (input == temp) {
        cout << "The string is a palindrome" << endl;
    } else {
        cout << "The string is not a palindrome" << endl;
    }

    return 0;

}