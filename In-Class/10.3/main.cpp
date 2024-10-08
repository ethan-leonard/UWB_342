#include <iostream>
#include <string>
#include <vector>

#include "mySwap.h"
#include "findMax.h"
#include "rectangle.h"
#include "playingCard.h"

using namespace std;

int main() {
    string name1 = "sue";
    string name2 = "ravi";
    
    cout << name1 << " " << name2 << endl;
    MySwap(name1, name2);
    cout << name1 << " " << name2 << endl;

    vector<int> v = {1, 5, 15, 35, -2, 0, -8};

    cout << findMax(v) << endl; 

    // could also do Rectangle r = {10, 20}
    Rectangle r;
    r.width = 10;
    r.height = 20;
    
    cout << "Area: " << findArea(r) << endl;

    playingCard G;

    cout << G << endl;
}

