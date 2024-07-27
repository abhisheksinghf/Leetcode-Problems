// We dont know whether the array is sorted in assending or decending order, its just sorted!!

#include <stdio.h>

int isAscending(int arr[], int size)
{
    if (size > 1)
    {
        if (arr[0] < arr[1])
        {
            return 1;
        }
    }
    return 0;
}

int binary_search(int *arr, int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        if(isAscending(arr,size))
        {
            if(key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(key > arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // sorted array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sorted array

    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int index = 0;

    index = binary_search(arr, size, key);

    if (index != -1)
    {
        printf("Element found at index %d", index);
    }
    else
    {
        printf("Element not found");
    }
}
