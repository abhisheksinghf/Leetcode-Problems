
#include<stdio.h>
#include<malloc.h>

int* reverseArray(int *arr, int size)
{
    int i;
    int *newArr = (int*) malloc(size * sizeof(int));
    int j=0;
    // printf("%d",size);
    for(i=size-1;i>=0;i--)
    {
        newArr[j] = arr[i];
        j++;
    }
    return newArr;
}

int main()
{
    int i,arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    // printf("%d",n);

    int *newArr = reverseArray(arr, size);

    for(i = 0; i < size; i++)
    {
        printf("%d ", newArr[i]);
    }

    free(newArr);

}