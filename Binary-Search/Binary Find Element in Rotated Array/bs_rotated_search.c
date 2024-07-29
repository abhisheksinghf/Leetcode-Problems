#include <stdio.h>

// Function to find the number of times the array has been rotated
int findRotationCount(int arr[], int n) {
    int low = 0, high = n - 1;
    
    // Binary search logic
    while (low <= high) {
        // If the array is already sorted, then no rotation
        if (arr[low] <= arr[high]) {
            return low;
        }
        
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        
        // Check if mid element is the minimum element
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid;
        }
        
        // Decide whether to go to the left half or the right half
        if (arr[mid] <= arr[high]) {
            high = mid - 1;
        } else if (arr[mid] >= arr[low]) {
            low = mid + 1;
        }
    }
    
    return -1;
}

// Binary search function
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
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

// Function to find the element in rotated array
int findElementInRotatedArray(int arr[], int n, int key) {
    int rotations = findRotationCount(arr, n);
    
    // Perform binary search in the two subarrays
    int result = binarySearch(arr, 0, rotations - 1, key);
    if (result != -1) {
        return result;
    }
    return binarySearch(arr, rotations, n - 1, key);
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int index = findElementInRotatedArray(arr, n, key);

    if (index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Element not found in the array\n");
    }
    
    return 0;
}
