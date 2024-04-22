#include <stdio.h>
#include<string.h>

int lengthOfLastWord(char *s) {
    int len = strlen(s);
    int i, count = 0;

    // Traverse the string from the end to find the last word
    for (i = len - 1; i >= 0; i--) {
        // Skip trailing spaces
        if (s[i] == ' ') {
            continue;
        }
        // Count characters until a space is encountered
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        break; // Exit loop once the last word is counted
    }

    return count;
}


int main()
{
    char str[20] = "Hello world";

    int count = lengthOfLastWord(str);

    printf("%d", count);

    return 0;
}