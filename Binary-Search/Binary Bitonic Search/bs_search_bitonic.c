#include <stdio.h>

// Function to find the peak element in a bitonic array
int findPeakElement(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid > 0 && mid < n - 1) {
            if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (mid == 0) {
            return (arr[mid] > arr[mid + 1]) ? mid : mid + 1;
        } else if (mid == n - 1) {
            return (arr[mid] > arr[mid - 1]) ? mid : mid - 1;
        }
    }

    return -1;
}

// Binary search in increasing order
int binarySearchAscending(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Binary search in decreasing order
int binarySearchDescending(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to search for a key in a bitonic array
int searchInBitonicArray(int arr[], int n, int key) {
    int peak = findPeakElement(arr, n);

    // Search in the increasing part
    int index = binarySearchAscending(arr, 0, peak, key);
    if (index != -1) {
        return index;
    }

    // Search in the decreasing part
    return binarySearchDescending(arr, peak + 1, n - 1, key);
}

int main() {
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int result = searchInBitonicArray(arr, n, key);
    if (result != -1) {
        printf("Key %d found at index %d\n", key, result);
    } else {
        printf("Key %d not found in the array\n", key);
    }

    return 0;
}
