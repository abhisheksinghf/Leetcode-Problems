#include <stdio.h>

int bs_occurance(int *arr, int size, int key)
{
    int low = 0, mid, high = size - 1;
    int first = -1, last = -1;


    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            first = mid;
            high = mid - 1;
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

    if (first == -1) 
    {
        return 0;
    }

    // Find last occurrence
    low = first; 
    high = size - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            last = mid;
            low = mid + 1;
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

    return last - first + 1;
}

int main()
{
    int arr[] = {1, 3, 3, 3, 3, 3, 3, 3, 8, 9, 9, 10}; // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    int count;

    count = bs_occurance(arr, size, key);

    if (count > 0)
    {
        printf("Count of %d is %d\n", key, count);
    }
    else
    {
        printf("Element not found!!\n");
    }

    return 0;
}
