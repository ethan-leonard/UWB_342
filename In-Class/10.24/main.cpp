#include <iostream>
#include "bird.h"

// dosen't work
/* std::string convertBinary(int num) {
    std::string s = "";
    if (num <= 0) {
        return "0";
    } else if (num == 1) {
         s+="1";
    } else {
        s+=(num%2);
        convertBinary(num/2);
    }
    return s;
} */

bool printBase(int num, int base, std::string &answer) {
    std::string static kDigitArrary = "0123456789ABCDEF";

    if ((num < 0) || (base < 2) || (base > 16)) {
        return false;
    } if (num < base) {
        answer = kDigitArrary[num] + answer; 
    } else {
        answer = kDigitArrary[num%base] + answer;
        printBase(num / base, base, answer);
    } return true;
}

/* Bird* createFlock(int num, std::string name) {
    Bird* pBird;
    pBird = new Bird[num];

    for (int i = 0; i < num; i++) {
        pBird[i].set_name(name);
        pBird[i].set_id(i);
    }
    return pBird;
} */

int binarySearch(int arr[], int x, int min, int max) {
    while (min <= max) {
        int mid = (min + max) / 2;
        if (x == arr[mid]) {
            return mid;
        } else if (x > arr[mid]) {
            min = mid + 1;
        } else if (x < arr[mid]) {
            max = mid - 1;
        }
    } return -1;
}

/* Recursive Method
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }
  return -1;
} */

int comboSweets(int days, int sweets) {
    
}

int main() {
    int num = 1957;
    std::string answer;
    printBase(num, 2, answer);
    std::cout << answer << std::endl;

    int arr[] = {-1, 5, 8, 11, 22, 34};
    int x = 11;

    int location = binarySearch(arr, x, 0, 5);

    std::cout << location << std::endl;
}