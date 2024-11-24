#ifndef LIST342_H_
#define LIST342_H


template <class T>
struct Node {
    T* data;
    Node* next;
};

template <class T>
class List342 {
    private:
        Node <T>* head_;


    public:
        List342();
        ~List342();

        // Builds an order list from objects in an file
        bool BuildList(string file_name);

        // Inserts an object into its correct place within the list
        bool Insert(T* obj);

        // Removes target item from the list
        bool Remove(T target, T& result);

        // Peeks target item from the list
        bool Peak(T target, T& result);

        // Returns number of items in the list
        int Size() const;

        // Removes all items from the list
        void DeleteList();

        // Merges inputted list with the list
        bool Merge(List342& list1);

        // Overloads
        List342<T> operator+(const List342<T> &list) const;
        List342<T>& operator+=(const List342<T> &list);
        bool operator==(const List342<T> &list) const;
        bool operator!=(const List342<T> &list) const;
        List342<T>& operator=(const List342<T> &list);

        template <class U>
        friend std::ostream& operator<<(std::ostream& out_stream, const List342<U>& list);



};

#endif