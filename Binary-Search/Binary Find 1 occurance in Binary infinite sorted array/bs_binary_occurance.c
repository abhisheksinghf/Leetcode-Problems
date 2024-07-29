#include <stdio.h>
#include <limits.h>

// Function to find the first occurrence of 1 in an infinite sorted binary array
int findFirstOne(int arr[], int size) {
    // Initialize the search boundaries
    int low = 0;
    int high = 1;

    // Expand the range exponentially until we find a high boundary containing 1
    while (arr[high] != 1) {
        low = high;
        high *= 2;
        // Ensure high does not go out of array bounds for practical scenarios
        if (high >= size) {
            high = size - 1;
            break;
        }
    }

    // Apply binary search within the found range
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)) {
            return mid;  // Found the first occurrence of 1
        } else if (arr[mid] == 1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;  // If no 1 is found
}

int main() {
    int arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}; // Infinite sorted binary array simulation
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = findFirstOne(arr, size);

    if (index != -1) {
        printf("The first occurrence of 1 is at index %d\n", index);
    } else {
        printf("No 1 found in the array\n");
    }

    return 0;
}
