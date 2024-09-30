#include <iostream>

using namespace std;
void function_lect01(int& x, int& y);

int main()
{
    std::cout << "Hello World" << std::endl;
    int a = 10;
    int b = 5;
    function_lect01(a, b);
}

void function_lect01(int& x, int& y)
{
    if (x > y)
    {
        cout << "x is greater than y" << endl;
    }
}