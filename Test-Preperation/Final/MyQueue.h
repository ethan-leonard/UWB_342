#ifndef MY_QUEUE_H_
#define MY_QUEUE_H_

#include <iostream>

using namespace std;

class MyQueue
{
public:
	MyQueue();
	int Pop() throw (exception);
	void Push(int value);
	int Front() const throw (exception);
	int Back() const throw (exception);

	int count() const;
	bool IsEmpty() const;
	friend ostream& operator<<(ostream& stream, const MyQueue& rhs);

private:

};
#endif

MyQueue& MyQueue::operator=(const MyQueue& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // Delete existing nodes
    while (!IsEmpty()) {
        Pop();
    }

    // Copy nodes from other queue
    Node* current = other.front_;
    while (current != nullptr) {
        Push(current->data);
        current = current->next;
    }

    return *this;
}