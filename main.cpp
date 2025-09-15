#include <iostream>
#include <stdexcept>
#include "arrayFunctions.h"
using namespace std;

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Load array from input file
    const char* filename = "A1input.txt";
    if (loadArray(filename, arr, size) == -1) {
        return 1; // exit if file not found
    }

    cout << "Array loaded successfully from " << filename << endl;
    displayArray(arr, size);

    int choice;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Search for an integer" << endl;
        cout << "2. Modify a value by index" << endl;
        cout << "3. Add a new value" << endl;
        cout << "4. Delete a value by index" << endl;
        cout << "5. Display array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int target;
                cout << "Enter integer to search: ";
                cin >> target;
                int index = findIndex(arr, size, target);
                if (index != -1)
                    cout << "Found " << target << " at index " << index << endl;
                else
                    cout << "Value not found." << endl;
                break;
            }
            case 2: {
                int index, newValue, oldValue;
                cout << "Enter index to modify: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> newValue;

                try {
                    modifyValue(arr, size, index, newValue, oldValue);
                    cout << "Modified index " << index << ": old value = " 
                         << oldValue << ", new value = " << newValue << endl;
                } catch (out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 3: {
                int newValue;
                cout << "Enter value to add: ";
                cin >> newValue;
                try {
                    addValue(arr, size, newValue);
                    cout << "Added value " << newValue << " at the end." << endl;
                } catch (overflow_error& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 4: {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                deleteValue(arr, size, index);
                cout << "If index was valid, value deleted." << endl;
                break;
            }
            case 5:
                displayArray(arr, size);
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
