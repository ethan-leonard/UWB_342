#include <iostream>

int numLeaves(int height, int branches) {
    if  ((height <= 0) || (branches <= 0)) {
        return 0;
    } else if (height == 1) {
        return 1;
    } else {
        return (branches * numLeaves(height-1, branches));
    }
}

int main(int argc, char* argv[]) {
    std::cout << argc << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    std::cout << numLeaves(2, 3) << std::endl;
}

