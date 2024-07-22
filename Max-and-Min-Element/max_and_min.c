#include<stdio.h>

int maxElement(int *arr,int n)
{
    int i;
    int max = arr[0];
    for(i=0;i<n;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int minElement(int *arr,int n)
{

    int i;
    int min = arr[0];
    for(i=0;i<n;i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int arr[] = {10,40,5,50,2,12,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Maximum Element : %d\n",maxElement(arr,n)); 
    printf("Minimum Element : %d\n",minElement(arr,n));

    return 0;
}