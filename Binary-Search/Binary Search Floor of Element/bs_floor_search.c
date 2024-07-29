//floor of 5 means greatest element smaller than 5
#include <stdio.h>

int find_floor(int *arr, int size, int key)
{
    int low = 0, high = size - 1, mid;
    int result = -1;  // Initialize result as -1 to indicate floor not found

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;  // Key itself is the floor
        }
        else if (arr[mid] < key)
        {
            result = mid;  // Update result to the current mid
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 11;
    int index = find_floor(arr, size, key);

    if (index != -1)
    {
        printf("Floor Element is %d\n", arr[index]);
    }
    else
    {
        printf("Floor element not found\n");
    }

    return 0;
}
