#include <stdio.h>

int bs_first_occurance(int *arr, int size, int key)
{
    int low, mid, high, result = -1;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            result = mid;
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
    return result;
}
int bs_last_occurance(int *arr, int size, int key)
{
    int low, mid, high, result = -1;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            result = mid;
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
    return result;
}

int main()
{
    int arr[] = {1, 3, 3, 3, 3, 3, 3, 3, 8, 9, 9, 10}; // sorted array

    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int first = 0;
    int last = 0;

    first = bs_first_occurance(arr, size, key);
    last = bs_last_occurance(arr, size, key);

    if (first != -1 && last != -1)
    {
        printf("Element first and last occured at index %d amd %d", first,last);
    }
    else
    {
        printf("Element not found");
    }
}
