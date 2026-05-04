// Day 98: Generate All Permutations (Backtracking)
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }

void permute(char *str, int l, int r) {
    if (l == r) { printf("%s\n", str); return; }
    for (int i = l; i <= r; i++) {
        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]);
    }
}

int main() {
    char str[100];
    printf("Enter a string: "); scanf("%s", str);
    printf("All permutations:\n");
    permute(str, 0, strlen(str) - 1);
    return 0;
}
