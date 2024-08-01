// Finding max element in bitonic array

#include <stdio.h>

int findMaxElement(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is not at the edges
        if (mid > 0 && mid < n - 1) {
            // Check if mid is a Max element
            if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) {
                return mid;
            }
            // If the left neighbor is greater, search in the left half
            else if (arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            }
            // Otherwise, search in the right half
            else {
                low = mid + 1;
            }
        }
        // Edge case: Check if mid is the first element
        else if (mid == 0) {
            if (arr[mid] >= arr[mid + 1]) {
                return mid;
            } else {
                return mid + 1;
            }
        }
        // Edge case: Check if mid is the last element
        else if (mid == n - 1) {
            if (arr[mid] >= arr[mid - 1]) {
                return mid;
            } else {
                return mid - 1;
            }
        }
    }

    return -1; // No Max element found (shouldn't happen if array has at least one element)
}

int main() {
    int arr[] = {10, 12, 14, 17, 6, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int MaxIndex = findMaxElement(arr, n);
    if (MaxIndex != -1) {
        printf("Max element is at index %d with value %d\n", MaxIndex, arr[MaxIndex]);
    } else {
        printf("No Max element found.\n");
    }

    return 0;
}
