#include <stdio.h>

int findPeakElement(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is not at the edges
        if (mid > 0 && mid < n - 1) {
            // Check if mid is a peak element
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

    return -1; // No peak element found (shouldn't happen if array has at least one element)
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, n);
    if (peakIndex != -1) {
        printf("Peak element is at index %d with value %d\n", peakIndex, arr[peakIndex]);
    } else {
        printf("No peak element found.\n");
    }

    return 0;
}
