#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) {
        return numsSize; // If the array is empty or contains only one element, no duplicates to remove
    }

    int index = 0; // Index to store the position of the unique elements
    for(int i = 0; i < numsSize - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            nums[index++] = nums[i]; // Copying unique elements to the beginning of the array
        }
    }
    nums[index++] = nums[numsSize - 1]; // Copying the last element of the array

    return index; // Index gives the new size of the array after removing duplicates
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newSize = removeDuplicates(nums, numsSize);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
