#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, key, j;

    for(i = 0; i < n; i++) {
        nums1[i + m] = nums2[i];
    }

    for (i = 1; i < m + n; i++) {
        key = nums1[i];
        j = i - 1;
        while (j >= 0 && nums1[j] > key) {
            nums1[j + 1] = nums1[j];
            j = j - 1;
        }
        nums1[j + 1] = key;
    }
}

int main() {
    int nums1[10] = {1, 3, 5, 7, 9};
    int nums2[5] = {2, 4, 6, 8, 10};
    int m = 5;
    int n = 5;
    int mergedSize = m + n;

    printf("Array 1 before merging:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("Array 2 before merging:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    merge(nums1, 10, m, nums2, 5, n);

    printf("Merged and sorted array:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
