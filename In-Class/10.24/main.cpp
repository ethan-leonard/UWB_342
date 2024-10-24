#include <iostream>

// dosen't work
std::string convertBinary(int num) {
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
} 

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

int main() {
    int num = 1957;
    std::string answer;
    printBase(num, 2, answer);
    std::cout << answer << std::endl;
}