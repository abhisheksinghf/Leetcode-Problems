#include <stdio.h>
#include <stdlib.h>

int findMinDiff(int *arr, int size, int key) {
    int low = 0, high = size - 1, mid;

    // Handle edge cases where the key is outside the array bounds
    if (key < arr[low]) {
        return arr[low] - key;
    }
    if (key > arr[high]) {
        return key - arr[high];
    }

    while (low <= high) {
        mid = low + (high - low) / 2;

        // If the key is found, the minimum difference is 0
        if (arr[mid] == key) {
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // At this point, high < low and the closest elements are arr[high] and arr[low]
    int diffHigh = abs(arr[high] - key);
    int diffLow = abs(arr[low] - key);

    return diffHigh < diffLow ? diffHigh : diffLow;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10}; // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int minDiff = findMinDiff(arr, size, key);

    printf("Minimum difference is %d\n", minDiff);

    return 0;
}
