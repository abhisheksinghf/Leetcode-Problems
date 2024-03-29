#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i, count = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            int temp;
            temp = nums[i];
            nums[i] = nums[count];
            nums[count] = temp;

            count++;
        }
    }

    return count;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    printf("Original array:\n");
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newSize = removeElement(nums, numsSize, val);

    printf("Array after removing %d:\n", val);
    for (i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
