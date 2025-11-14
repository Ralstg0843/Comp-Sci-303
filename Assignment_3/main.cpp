#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;


int find_last_occurrence(vector<int>& items, int target);


struct Node {
    int data;
    Node* next;
};

Node* insertion_sort_list(Node* head);
void push_front(Node*& head, int value);
void print_list(Node* head);

int main() {

    
    Queue<int> q;

    
    for (int i = 1; i <= 10; i++) {
        q.push(i * 5); 
    }

    cout << "Queue contents:" << endl;

    
    int s = q.size();
    for (int i = 0; i < s; i++) {
        int value = q.front();  // get front
        cout << value << " ";
        q.pop();                // remove
        q.push(value);          // put back
    }
    cout << endl;

    // testing move_to_rear
    cout << "Moving front to rear..." << endl;
    q.move_to_rear();

    cout << "Queue after move_to_rear:" << endl;
    s = q.size();
    for (int i = 0; i < s; i++) {
        int value = q.front();
        cout << value << " ";
        q.pop();
        q.push(value);
    }
    cout << endl;


    
    vector<int> nums = {3, 7, 2, 7, 9, 7};
    int target = 7;

    int pos = find_last_occurrence(nums, target);

    cout << "\nLast occurrence of " << target 
         << " is at index: " << pos << endl;


    
    Node* head = nullptr;

    
    push_front(head, 10);
    push_front(head, 30);
    push_front(head, 65);
    push_front(head, 20);

    cout << "\nLinked list before sorting: ";
    print_list(head);

    head = insertion_sort_list(head);

    cout << "Linked list after sorting: ";
    print_list(head);

    return 0;
}
