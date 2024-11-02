#ifndef INT_STACK_H
#define INT_STACK_H

    struct Node {
        int value = 0;
        Node* next = nullptr;
    };

    class IntStack {
        private:
            Node* head_;

        public:
            // Constructor
            IntStack();
            ~IntStack();

            // Actions
            bool push(int value);
            bool pop(int& value);

            // Overloads 
            friend std::ostream& operator<<(std::ostream& stream, const IntStack& st);
    };

#endif