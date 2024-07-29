#include <stdio.h>

// Function to find the number of times the array has been rotated
int countRotations(int arr[], int n) {
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

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotations = countRotations(arr, n);
    printf("The array has been rotated %d times\n", rotations);
    return 0;
}
