#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>  
#include <stdexcept>
#include <iostream>

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data; // storing value
        Node* next; //pointer to next node
        Node(const Item_Type& item, Node* next_ptr = nullptr)
            : data(item), next(next_ptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items; // keeps track of number of items

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}
    ~Single_Linked_List() { while (!empty()) pop_front(); }
//add elemnts to front 
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item, head);
        head = new_node;
        if (num_items == 0) tail = head;
        ++num_items;
    }
//add elemment to back
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (num_items == 0) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        ++num_items;
    }

    void pop_front() {
        if (empty()) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        --num_items;
        if (num_items == 0) tail = nullptr;
    }
//remove first element
    void pop_back() {
        if (empty()) return;
        if (num_items == 1) {
            delete head;
            head = tail = nullptr;
            num_items = 0;
            return;
        }
        Node* cur = head;
        while (cur->next != tail) cur = cur->next;
        delete tail;
        tail = cur;
        tail->next = nullptr;
        --num_items;
    }

    Item_Type& front() {
        if (empty()) throw std::runtime_error("front() called on empty list");
        return head->data;
    }

    Item_Type& back() {
        if (empty()) throw std::runtime_error("back() called on empty list");
        return tail->data;
    }

    bool empty() const { return num_items == 0; }
//insert at given index
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) { push_front(item); return; }
        if (index >= num_items) { push_back(item); return; }
        Node* prev = head;
        for (size_t i = 0; i < index - 1; ++i) prev = prev->next;
        Node* new_node = new Node(item, prev->next);
        prev->next = new_node;
        ++num_items;
    }

    bool remove(size_t index) {
        if (index >= num_items) return false;
        if (index == 0) { pop_front(); return true; }
        Node* prev = head;
        for (size_t i = 0; i < index - 1; ++i) prev = prev->next;
        Node* to_delete = prev->next;
        prev->next = to_delete->next;
        if (to_delete == tail) tail = prev;
        delete to_delete;
        --num_items;
        return true;
    }

    size_t find(const Item_Type& item) const {
        Node* cur = head;
        size_t idx = 0;
        while (cur) {
            if (cur->data == item) return idx;
            cur = cur->next;
            ++idx;
        }
        return num_items;
    }

    void print_list() const {
        Node* cur = head;
        std::cout << "[";
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << "]\n";
    }
//return number of items
    size_t size() const { return num_items; }
};

#endif
