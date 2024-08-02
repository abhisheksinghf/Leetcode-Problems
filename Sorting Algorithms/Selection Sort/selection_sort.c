#include <stdio.h>

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
void selectionSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 2; i++)
    {
        int min = i;
        for (j = i + 1; j < size - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        }
    }

    display(arr, size);
}

int main()
{
    int arr[] = {6, 3, 8, 2, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);
}