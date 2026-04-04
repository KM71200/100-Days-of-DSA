/*Flood Fill*/
#include <stdio.h>

#define MAX 100

int image[MAX][MAX];
int m, n;

void dfs(int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;

    if (image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    dfs(r + 1, c, oldColor, newColor);
    dfs(r - 1, c, oldColor, newColor);
    dfs(r, c + 1, oldColor, newColor);
    dfs(r, c - 1, oldColor, newColor);
}

int main() {
    int sr, sc, newColor;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter image matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter starting row, column and new color: ");
    scanf("%d %d %d", &sr, &sc, &newColor);

    int oldColor = image[sr][sc];

    if (oldColor != newColor) {
        dfs(sr, sc, oldColor, newColor);
    }

    printf("Updated Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}