#include <iostream>
#include <fstream>
#include <stdexcept>
#include "arrayFunctions.h"
using namespace std;

// Load integers from file into array
int loadArray(const char* filename, int arr[], int& size) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return -1;
    }

    size = 0;
    while (infile >> arr[size] && size < MAX_SIZE) {
        size++;
    }
    infile.close();
    return size;
}

// Find index of target number
int findIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // not found
}

// Modify a value at a given index
void modifyValue(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Invalid index for modifyValue.");
    }
    oldValue = arr[index];
    arr[index] = newValue;
}

// Add a new integer at the end
void addValue(int arr[], int& size, int newValue) {
    if (size >= MAX_SIZE) {
        throw overflow_error("Array is full, cannot add new value.");
    }
    arr[size] = newValue;
    size++;
}

// Delete value at given index
void deleteValue(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cerr << "Invalid index for deleteValue." << endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Display array contents
void displayArray(int arr[], int size) {
    cout << "Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
