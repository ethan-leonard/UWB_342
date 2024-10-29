#include <iostream>

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
}