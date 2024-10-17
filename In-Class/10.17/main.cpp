#include <iostream>

int addItUp(int* arr, int length);
int factorial(int n); 

int main() {
    int my_arrary[3] = {34, 7, 24};
    std::cout << addItUp(my_arrary, 3) << std::endl;
    std::cout << factorial(5) << std::endl;
    return 0;
}

int addItUp(int* arr, int length) {
    int answer = 0;
    for (int i = 0; i < length; i++) {
        // answer += arr[i]
        answer += *arr;
        std::cout << arr << " " << *arr << std::endl;
        arr++;
    }
    return answer;
}

int factorial(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}