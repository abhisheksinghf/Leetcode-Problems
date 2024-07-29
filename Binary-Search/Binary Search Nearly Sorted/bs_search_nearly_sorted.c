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
        else if(mid-1 >= low && arr[mid-1] == key)
        {
            return mid - 1;
        }
        else if(mid+1 <= high && arr[mid+1] == key)
        {
            return mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 2;
        }

        else
        {
            low = mid + 2;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,2,4,5,8,7,10,9,11}; // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key =11;
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