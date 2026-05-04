// Day 13: Boundary-to-Center Matrix Walk (Spiral Inward Traversal)
#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int mat[20][20];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("Boundary-to-Center traversal:\n");

    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Top row
        for (int i = left; i <= right; i++)
            printf("%d ", mat[top][i]);
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            printf("%d ", mat[i][right]);
        right--;

        // Bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", mat[bottom][i]);
            bottom--;
        }

        // Left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }
    printf("\n");

    return 0;
}
