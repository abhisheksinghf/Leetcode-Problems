#include <stdio.h>

int binary_search(int *arr, int size, int key)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (key != arr[mid] && low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    int index = 0;

    index = binary_search(arr, size, key);

    if (index)
    {
        printf("Element found at index %d", index);
    }
    else
    {
        printf("Element not found");
    }
}