#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

// Simple queue using linked list

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front_ptr;
    Node* rear_ptr;
    int count;

public:
    Queue();                 // constructor
    ~Queue();                // destructor
    void push(const T& val); 
    void pop();              // remove from front
    T front();               // get front value
    int size();              // number of items
    bool empty();            
    void move_to_rear();     
};



// constructor
template <typename T>
Queue<T>::Queue() {
    front_ptr = nullptr;
    rear_ptr = nullptr;
    count = 0;
}

// destructor
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// push
template <typename T>
void Queue<T>::push(const T& val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (empty()) {
        front_ptr = rear_ptr = newNode;
    } else {
        rear_ptr->next = newNode;
        rear_ptr = newNode;
    }
    count++;
}

// pop
template <typename T>
void Queue<T>::pop() {
    if (empty()) return;

    Node* temp = front_ptr;
    front_ptr = front_ptr->next;
    if (front_ptr == nullptr) rear_ptr = nullptr;

    delete temp;
    count--;
}

// front
template <typename T>
T Queue<T>::front() {
    return front_ptr->data;
}

// size
template <typename T>
int Queue<T>::size() {
    return count;
}

// empty
template <typename T>
bool Queue<T>::empty() {
    return count == 0;
}

// move_to_rear
template <typename T>
void Queue<T>::move_to_rear() {
    if (empty() || size() == 1) return;

    T temp = front();
    pop();
    push(temp);
}

#endif

