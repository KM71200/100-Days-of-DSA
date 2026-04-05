/*Rotting Oranges*/
#include <stdio.h>

#define MAX 100

int orangesRotting(int grid[MAX][MAX], int rows, int cols) {
    int queue[MAX * MAX][2];
    int front = 0, rear = 0;

    int fresh = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int minutes = -1;

    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (front < rear) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;

                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int grid[MAX][MAX];

    printf("Enter grid values (0, 1, 2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, rows, cols);

    printf("Minimum minutes: %d\n", result);

    return 0;
}