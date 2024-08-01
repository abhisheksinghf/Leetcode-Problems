#include<stdio.h>

void bubbleSort(int *arr, int size)
{
    int i,j;
    for(i = 0; i < size-2 ; i++)
    {
        for(j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(int arr[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int arr[] = {6,3,8,2,1,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,size);

    display(arr,size);
}