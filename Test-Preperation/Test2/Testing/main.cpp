#include <iostream>

int recursive(int n, int k) {
    if (n < k || n < 1 || k < 1) {
        return -1;
    } if (n == k) {
        return 1;
    } if (k == 1) {
        return n;
    } else {
        return (recursive(n-1, k-1) + recursive(n-1, k));
    }
}

int main() {
    std::cout << recursive(5,3) << std::endl;

}