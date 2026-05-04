// Day 97: Word Search in a Grid (Backtracking)
#include <stdio.h>
#include <string.h>
#define N 10

char grid[N][N];
int visited[N][N];
int rows, cols;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int search(int r, int c, char *word, int idx) {
    if (idx == strlen(word)) return 1;
    if (r < 0 || r >= rows || c < 0 || c >= cols) return 0;
    if (visited[r][c] || grid[r][c] != word[idx]) return 0;

    visited[r][c] = 1;
    for (int d = 0; d < 8; d++)
        if (search(r + dx[d], c + dy[d], word, idx + 1)) return 1;
    visited[r][c] = 0;
    return 0;
}

int main() {
    char word[100];
    printf("Enter grid rows and cols: "); scanf("%d %d", &rows, &cols);
    printf("Enter grid:\n");
    for (int i = 0; i < rows; i++) scanf("%s", grid[i]);
    printf("Enter word to search: "); scanf("%s", word);

    int found = 0;
    for (int i = 0; i < rows && !found; i++)
        for (int j = 0; j < cols && !found; j++) {
            memset(visited, 0, sizeof(visited));
            if (search(i, j, word, 0)) {
                printf("Word '%s' found starting at (%d, %d)\n", word, i, j);
                found = 1;
            }
        }
    if (!found) printf("Word '%s' not found.\n", word);
    return 0;
}
