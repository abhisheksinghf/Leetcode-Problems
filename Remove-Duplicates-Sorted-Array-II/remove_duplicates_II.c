#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize; 
    }
    int i;
    int count = 2; 
    for (i = 2; i < numsSize; i++) {
        if (nums[i] != nums[count - 2]) {
            nums[count++] = nums[i]; 
        }
    }

    return count; 
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3,3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    printf("Original array:\n");
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newSize = removeDuplicates(nums, numsSize);

    printf("Array after removing duplicates:\n");
    for ( i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
