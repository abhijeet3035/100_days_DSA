// Day 15: Diagonal Sum of a Matrix
#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int mat[10][10];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        primarySum += mat[i][i];
        secondarySum += mat[i][n - 1 - i];
    }

    printf("Primary diagonal sum: %d\n", primarySum);
    printf("Secondary diagonal sum: %d\n", secondarySum);
    printf("Total diagonal sum: %d\n", primarySum + secondarySum);

    return 0;
}
