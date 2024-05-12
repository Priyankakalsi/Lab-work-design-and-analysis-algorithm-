#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the key is present at the middle itself
        if (arr[mid] == key) {
            return mid;
        }

        // If the key is greater than the middle element, ignore left half
        if (arr[mid] < key) {
            low = mid + 1;
        }
        // If the key is smaller than the middle element, ignore right half
        else {
            high = mid - 1;
        }
    }

    // If the key is not found, return -1
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key = 30;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
