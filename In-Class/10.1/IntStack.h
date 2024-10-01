#ifndef INT_STACK_H_
#define INT_STACK_H_

class IntStack {
    public:
        bool Peek();
        bool Push(int x);
        bool Pop(int& x);   
    private:
        int size();
};

#endif
