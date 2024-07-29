#include <stdio.h>

// Function to find the next character in a sorted array
char findNextChar(char arr[], int size, char target) {
    int low = 0, high = size - 1;
    char result = '\0';  // Initialize result as null character to indicate not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            result = arr[mid];  // Update result to the current mid
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    char arr[] = {'a', 'c', 'f', 'h', 'k'};
    int size = sizeof(arr) / sizeof(arr[0]);
    char target = 'f';
    char nextChar = findNextChar(arr, size, target);

    if (nextChar != '\0') {
        printf("Next character after '%c' is '%c'\n", target, nextChar);
    } else {
        printf("No next character found after '%c'\n", target);
    }

    return 0;
}
