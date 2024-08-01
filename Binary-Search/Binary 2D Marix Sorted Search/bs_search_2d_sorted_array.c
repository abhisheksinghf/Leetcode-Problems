#include <stdio.h>

#define ROWS 4
#define COLS 4

int searchInSortedMatrix(int matrix[ROWS][COLS], int rows, int cols, int key) {
    int i = 0;       // Start from the first row
    int j = cols - 1; // Start from the last column

    while (i < rows && j >= 0) {
        if (matrix[i][j] == key) {
            return 1; // Key found
        } else if (matrix[i][j] > key) {
            j--; // Move left if the current element is greater than the key
        } else {
            i++; // Move down if the current element is less than the key
        }
    }

    return 0; // Key not found
}

int main() {
    int matrix[ROWS][COLS] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int key = 29;

    if (searchInSortedMatrix(matrix, ROWS, COLS, key)) {
        printf("Key %d found in the matrix.\n", key);
    } else {
        printf("Key %d not found in the matrix.\n", key);
    }

    return 0;
}
