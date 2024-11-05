#include <iostream>
#include "intStack.h"

// Might be in next test
int sweetCombos(int k, int n) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return n;
    } else if (k == n) {
        return 1;
    } else {
        return sweetCombos(k-1, n-1) + sweetCombos(k, n-1);
    }
}

int main() {
    int days = 2;
    int sweets = 4;

    std::cout << sweetCombos(days, sweets) << std::endl;

    IntStack numbers;
    numbers.push(37);
    numbers.push(25);
    numbers.push(19);
    numbers.push(11);
    numbers.push(5);
    numbers.push(0);

    int x = 0;
    numbers.pop(x);

    numbers.insert(12);

    numbers.remove(19);

    std::cout << numbers << std::endl;

}