#include <iostream>
using namespace std;

// node for a simple linked list
struct Node {
    int data;
    Node* next;
};

// function to insert a new node at the front
void push_front(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// this function prints the whole list
void print_list(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// insertion sort for linked list
// sorts the list in ascending order
Node* insertion_sort_list(Node* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    
    Node* sorted = nullptr;

    // pointer to go through original list
    Node* current = head;

    
    while (current != nullptr) {
        Node* nextNode = current->next;

        
        if (sorted == nullptr || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } 
        else {
            // find where to insert in sorted list
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }

            // insert the node
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    return sorted;
}


