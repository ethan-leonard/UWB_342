#include <iostream>

struct Item {
    int value;

    // Overload the == operator
    bool operator==(const Item& other) const {
        return value == other.value;
    }
};

class List {
	public:
		List();
		~List();
		// Member Functions
        List(const std::initializer_list<Item>& items);
		int Remove(const Item& it);
	
	private: 
		struct Node {
			Item* p_item;
			Node* next;
		};
        Node* head_;
};

// Destructor
List::~List() {
    Node* current = head_;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp->p_item;
        delete temp;
    }
}

// Constructor with Initializer List
List::List(const std::initializer_list<Item>& items) : head_(nullptr) {
    for (const Item& it : items) {
        Node* new_node = new Node{ new Item(it), nullptr };
        if (head_ == nullptr) {
            head_ = new_node;
        } else {
            Node* current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
}

int List::Remove(const Item& it) {
    // Count for values greater
    int count = -1;

    // Create cursor
	Node* cursor = head_;

    // If it is the head item
    if (*(head_->p_item) == it) {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp->p_item;
        delete tmp;
        // Start counting ones greater
        while (cursor->next != nullptr) {
            cursor = cursor->next;
            count++;
        } return count;
    }

    // While there is items in list
	while (cursor != nullptr) {
        // If it is the item to remove 
        if (*(cursor->next->p_item) == it) {
            Node* tmp = cursor->next;
            cursor->next = tmp->next;

            // Start counting ones greater
            while (cursor != nullptr) {
                cursor = cursor->next;
                count++;
            }

            delete tmp->p_item;
            delete tmp;
        } else {
            cursor = cursor->next;  
        }
        
    }
    return count;
}

// Main Function
int main() {
    // Test Case 1: Remove an item from the middle
    List myList1 = {Item{10}, Item{20}, Item{30}, Item{40}, Item{50}};
    Item itemToRemove1{30};
    int result1 = myList1.Remove(itemToRemove1);
    std::cout << "Items greater than 30 remaining: " << result1 << std::endl; // Should output 2

    // Test Case 2: Remove an item from the head
    List myList2 = {Item{10}, Item{20}, Item{30}, Item{40}, Item{50}};
    Item itemToRemove2{10};
    int result2 = myList2.Remove(itemToRemove2);
    std::cout << "Items greater than 10 remaining: " << result2 << std::endl; // Should output 4

    // Test Case 3: Remove an item from the end
    List myList3 = {Item{10}, Item{20}, Item{30}, Item{40}, Item{50}};
    Item itemToRemove3{50};
    int result3 = myList3.Remove(itemToRemove3);
    std::cout << "Items greater than 50 remaining: " << result3 << std::endl; // Should output 0

    // Test Case 4: Remove an item that does not exist
    List myList4 = {Item{10}, Item{20}, Item{30}, Item{40}, Item{50}};
    Item itemToRemove4{60};
    int result4 = myList4.Remove(itemToRemove4);
    std::cout << "Items greater than 60 remaining: " << result4 << std::endl; // Should output 0

    return 0;
}