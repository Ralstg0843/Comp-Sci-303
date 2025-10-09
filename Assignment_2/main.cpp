#include <iostream>
#include "Single_Linked_List.h"
#include "StackVector.h"

int main() {
    std::cout << "=== Single_Linked_List Demo ===\n";
    Single_Linked_List<int> list; // creating linked list 

    list.push_back(10);
    list.push_front(5);
    list.push_back(20);
    list.insert(1, 7); 
    list.print_list();  
//removing elements from front and back
    list.pop_front();
    list.pop_back();
    list.print_list();  
//checks index of number
    std::cout << "Index of 10: " << list.find(10) << "\n";

    list.remove(0);
    list.print_list();  

    std::cout << "\n=== StackVector Demo ===\n";
    StackVector st;
    std::cout << "Empty stack? " << (st.empty() ? "Yes" : "No") << "\n";

    st.push(10);
    st.push(20);
    st.push(30);

    st.pop();
    std::cout << "Top element: " << st.top() << "\n";  
    std::cout << "Average: " << st.average() << "\n";   

    return 0;
}
