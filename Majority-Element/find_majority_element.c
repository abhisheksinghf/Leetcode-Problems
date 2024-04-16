#include <stdio.h>


int majorityElement(int* arr, int numsSize) {
    int i, j, count, ele;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (arr[i] == arr[j]) {
                count++;
                ele = arr[i];
                if(count > numsSize/2)
                {
                	break;
				}
            }
        }
    }
    return ele;
}


int main() {
    int myArray[] = {2,2,1,1,1,2,2};
    
	int size = sizeof(myArray) / sizeof(myArray[0]);
    
    int x = majorityElement(myArray, size);

printf("%d",x);
    return 0;
}