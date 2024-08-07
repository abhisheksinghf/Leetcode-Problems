#include<stdio.h>

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    
    while(i < j)
    {
        while(arr[i] <= pivot && i <= high)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quick_sort(int *arr, int low, int high)
{
    int index;
    if (low < high)
    {
        index = partition(arr,low,high);
        quick_sort(arr,low,index-1);
        quick_sort(arr,index+1,high);
    }
    
}

int main()
{
    int arr[] = {6, 3, 8, 2, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr,0,size-1);
    display(arr, size);
}