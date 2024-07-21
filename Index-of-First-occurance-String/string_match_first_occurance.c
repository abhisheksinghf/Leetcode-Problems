#include<stdio.h>
#include<string.h>

int strStr(char* text, char* pattern) {
    int n = strlen(text);
    int p = strlen(pattern);
    int i;
    // Iterate through the text to find the pattern
    for(i = 0; i <= n - p; i++) {
        int j;
        // Check if the substring starting from index i matches the pattern
        for (j = 0; j < p; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Break if a mismatch is found
            }
        }
        if (j == p) {
            // Pattern found, return the index where it starts
            return i;
        }
    }

    // Pattern not found, return -1
    return -1;
}

int main() {
    char text[20] = "sadlife";
    char pattern[20] = "ad";

    int index = strStr(text, pattern);
    if (index != -1) {
        printf("Pattern found at index: %d\n", index);
    } else {
        printf("Pattern not found!\n");
    }

    return 0;
}