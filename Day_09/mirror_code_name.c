// Day 9: Mirror the Code Name (Reverse a String using Recursion)
#include <stdio.h>
#include <string.h>

void mirror(char str[], int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    mirror(str, start + 1, end - 1);
}

int main() {
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove trailing newline
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    mirror(str, 0, strlen(str) - 1);

    printf("Mirrored string: %s\n", str);

    return 0;
}
