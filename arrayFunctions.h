#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

const int MAX_SIZE = 100;

// Load array from file
int loadArray(const char* filename, int arr[], int& size);

// Find index of a target integer
int findIndex(int arr[], int size, int target);

// Modify value at index (with old value returned)
void modifyValue(int arr[], int size, int index, int newValue, int& oldValue);

// Add new integer to the array
void addValue(int arr[], int& size, int newValue);

// Delete integer at index
void deleteValue(int arr[], int& size, int index);

// Display array contents
void displayArray(int arr[], int size);

#endif
