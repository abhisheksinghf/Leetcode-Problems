//ceil means smallest element greater than 5
#include <stdio.h>

int find_ceil(int *arr, int size, int key)
{
    int low = 0, high = size - 1, mid;
    int result = -1;  // Initialize result as -1 to indicate ceil not found

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;  // Key itself is the ceiling
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            result = mid;  // Update result to the current mid
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = find_ceil(arr, size, key);

    if (index != -1)
    {
        printf("Ceil Element is %d\n", arr[index]);
    }
    else
    {
        printf("Ceil element not found\n");
    }

    return 0;
}
