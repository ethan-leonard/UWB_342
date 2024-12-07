#include <iostream>

class Foo {
private:
    static int counter;
    int id;

public:
    Foo() {
        id = ++counter;
    }
    
    ~Foo() {
        std::cout << "Destructor: Object " << id << " destroyed\n";
    }
};

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

void ReverseArray(int* array, int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = *(array + i);
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }
}

int cat(int n) {
    int sum = 0;

    if (n == 0) {
        return 1;
    } else {
        for (int k = 0; k < n-1; k++) {
            sum += ((k+1) * cat(n-k-1));
        }
    } return sum;

}


// Initialize static counter
int Foo::counter = 0;

int main() {
    std::cout << recursive(5,3) << std::endl;

    int arr[5] = {1, 2, 3, 4, 5};
    ReverseArray(arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Foo m[5], n[4];
    Foo* fp;
    Foo* fp2 = new Foo();
    
    for (int i = 0; i < 4; i++) {
        Foo c, d;
        static Foo e;  // only created once despite the loop
        fp = new Foo();
    }
    
    delete fp;
    delete fp2;
    
    return 0;

}