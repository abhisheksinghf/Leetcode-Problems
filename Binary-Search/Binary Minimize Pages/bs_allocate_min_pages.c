#include <stdio.h>

// Function to find the maximum element in the array
int findMax(int *arr, int size) {
    int i, max = arr[0];
    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the sum of all elements in the array
int findSum(int *arr, int size) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to check if a given maximum pages allocation is valid
int isValid(int arr[], int size, int k, int max) {
    int i,studentCount = 1; // Start with the first student
    int currentSum = 0;

    for (i = 0; i < size; i++) {
        currentSum += arr[i];

        // If adding arr[i] exceeds max, allocate to the next student
        if (currentSum > max) {
            studentCount++;
            currentSum = arr[i]; // Start new sum for the next student

            // If the number of students exceeds k, return false
            if (studentCount > k) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to find the minimum possible maximum pages allocation
int binary_search(int *arr, int size, int k) {
    int low, high, mid, result = -1;
    low = findMax(arr, size);
    high = findSum(arr, size);

    if (k > size) {
        return -1; // More students than books
    }

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (isValid(arr, size, k, mid)) {
            result = mid; // Mid is a valid allocation, but we search for a better one
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int arr[] = {10, 20, 30, 40}; 
    int k = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binary_search(arr, size, k);
    
    if (result != -1) {
        printf("The minimum possible maximum pages allocated is: %d\n", result);
    } else {
        printf("Not possible to allocate books.\n");
    }

    return 0;
}
