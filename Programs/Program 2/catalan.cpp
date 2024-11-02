#include <iostream>
#include <cstdlib>

int catalan(int n) {
    if (n <= 1) {
        return 1;
    } else {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += (catalan(i) * catalan(n-i-1));
        } return result;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <non-negative number>" << std::endl;
        return 1;
    } 

    int arg = std::atoi(argv[1]);
    if (arg < 0) {
        std::cout << "Error: Input value must be positive." << std::endl;
        return 1;
    } if (arg > 18) {
        std::cout << "Error: Input value is too large." << std::endl;
        return 1;
    }

    int result = catalan(arg);
    std::cout << result << std::endl;
    return 0;
}

