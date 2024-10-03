#include <iostream>
#include <string>
#include <vector>

using namespace std;

// const as there is no reason to change vector
int findMax(const vector<int> a) {
    int max = a[0];
    int i = 0;

    for (i=1; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];    
        }
    }
    return max;
}