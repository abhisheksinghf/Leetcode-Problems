//sort an array consisting of only 0,1,2 elements without using any sorting algorithm
#include<stdio.h>
#include<malloc.h>

int main()
{
    int i = 0;
    int arr[] = {2,1,2,0,2,1,1,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *sorted = (int*) malloc(size * sizeof(int*));
    int j= 0;
    for(i=0;i<size;i++)
    {
        if(arr[i] == 0)
        {
            sorted[j] = arr[i];
        }
        else if (arr[i] == 1)
        {
            sorted[j] = arr[i];
        }
        else
        {
            sorted[j] = arr[i];
        }
        j++;
    }    

    for ( i = 0; i < size; i++)
    {
        printf("%d\t",sorted[i]);
    }
    
    return 0;
}