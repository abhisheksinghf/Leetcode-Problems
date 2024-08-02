//do dry run u will understand

#include <stdio.h>

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void insertionSort(int arr[], int size)
{
    int i,j,value;
    
    for ( i = 1; i < size; i++)
    {
        value = i;
        j = i - 1;
        while (j >= 0 && arr[j] > value )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}
int main()
{
    int arr[] = {6, 3, 8, 2, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    display(arr,size);
}