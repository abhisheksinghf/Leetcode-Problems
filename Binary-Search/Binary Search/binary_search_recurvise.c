#include <stdio.h>

int binary_search(int *arr, int size, int key, int low, int high)
{
    int mid;
    if (low > high)
    {
        return -1;
    }

    mid = (low + high) / 2;

    if (key == arr[mid])
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        return binary_search(arr, size, key, low, mid - 1);
    }

    else
    {
        return binary_search(arr, size, key, mid + 1, high);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 91;
    int index = 0;

    index = binary_search(arr, size, key, 0, 9);

    if (index)
    {
        printf("Element found at index %d", index);
    }
    else
    {
        printf("Element not found");
    }
}