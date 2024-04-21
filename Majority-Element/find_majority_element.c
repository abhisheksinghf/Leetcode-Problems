#include <stdio.h>


int majorityElement(int* arr, int numsSize) {
    int majority = arr[0]; // Assume the first element is the majority
    int i,count = 1; // Initialize count of majority element
    for (i = 1; i < numsSize; i++) {
        if (arr[i] == majority) {
            count++; // Increment count if current element is the same as majority
        } else {
            count--; // Decrement count if current element is different from majority
        }
        if (count == 0) {
            // If count becomes zero, update majority to current element
            majority = arr[i];
            count = 1; // Reset count
        }
    }
    return majority;
}


// int majorityElement(int* arr, int numsSize) {
//     int i, j, count, ele;
//     for (i = 0; i < numsSize; i++) {
//         count = 0; // Reset count for each element
//         for (j = 0; j < numsSize; j++) {
//             if (arr[i] == arr[j]) {
//                 count++;
//                 ele = arr[i];
//                 if(count > numsSize/2)
//                 {
//                     return ele; // Return element if it appears more than half the time
//                 }
//             }
//         }
//     }
//     return -1; // No majority element found
// }


int main() {
    int myArray[] = {3,2,3};
    
	int size = sizeof(myArray) / sizeof(myArray[0]);
    
    int x = majorityElement(myArray, size);

printf("%d",x);
    return 0;
}