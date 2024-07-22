#include<stdio.h>

int* kth(int *arr, int n, int k)
{
    int i,j=0;
    int arr2[n];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Kth Smallest Element is %d\t",arr[k-1]);
    printf("Kth Largest Element is %d\t",arr[n-k]);
}

int main()
{
    int arr[] = {39,2,21,40,20,6,2,22}; // 2 20 21 39 40
    int n = 8;

    kth(arr,n, 3);

    return 0;
}