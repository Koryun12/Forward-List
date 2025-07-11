#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <iostream>
#include <iterator>

template<typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    ForwardList();
    ~ForwardList();

    void push_front(const T& value);
    void pop_front();
    bool empty() const;
    void clear();
    void print() const;
    bool remove(const T& value);
    bool contains(const T& value) const;


    class Iterator {
    private:
        Node* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;

        Iterator(Node* ptr) : current(ptr) {}

        T& operator*() const { return current->data; }
        T* operator->() const { return &(current->data); }

        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

// Implementation

template<typename T>
ForwardList<T>::ForwardList() : head(nullptr) {}

template<typename T>
ForwardList<T>::~ForwardList() {
    clear();
}

template<typename T>
void ForwardList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void ForwardList<T>::pop_front() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
bool ForwardList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
void ForwardList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void ForwardList<T>::print() const {
    for (const auto& val : *this) {
        std::cout << val << " -> ";
    }
    std::cout << "null\n";
}

template<typename T>
bool ForwardList<T>::remove(const T& value) {
    Node** current = &head;
    while (*current) {
        if ((*current)->data == value) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return true;
        }
        current = &((*current)->next);
    }
    return false;
}

template<typename T>
bool ForwardList<T>::contains(const T& value) const {
    for (const auto& val : *this) {
        if (val == value) return true;
    }
    return false;
}

#endif 
