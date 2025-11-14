#include <iostream>
#include <vector>
using namespace std;

// This function looks for the last time the target appears.
// start from the end of the vector going backwards.
int recursive_last_search(vector<int>& items, int target, int pos) {
    
    if (pos == -1) {
        return -1;
    }

    
    if (items[pos] == target) {
        return pos;
    }

    
    return recursive_last_search(items, target, pos - 1);
}

// call the recursive one
int find_last_occurrence(vector<int>& items, int target) {
    // start from last index
    return recursive_last_search(items, target, items.size() - 1);
}
