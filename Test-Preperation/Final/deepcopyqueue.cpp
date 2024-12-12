// Deep copy of queue
QueueLL& QueueLL::operator=(const QueueLL& rhs) {
    // Assigning queue to self
    if (this == &rhs) {
        return *this;
    }

    // Empty out destination queue
    while (count() > 0) {
        Pop();
    }

    // If rhs is empty return
    if (rhs.count() == 0) {
        return *this;
    }

    // Deep copy
    Node* p_node = rhs.front_;
    Node* d_node = new Node;
    d_node->value = p_node->value;
    this->front_ = d_node;

    while (p_node->next != nullptr) {
        p_node = p_node->next;
        d_node->next = new Node;
        d_node = d_node->next;
        d_node->value = p_node->value;
    }

    this->back_ = d_node;
    this->count_ = rhs.count();
    return *this;
}