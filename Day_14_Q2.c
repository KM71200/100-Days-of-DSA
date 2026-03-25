/*Rotate image*/
#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }

    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            int tmp = matrix[i][l];
            matrix[i][l] = matrix[i][r];
            matrix[i][r] = tmp;
            l++; r--;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(",");
        }
        printf("]\n");
    }
    printf("\n");
}

int main() {
    int r1[] = {1, 2, 3};
    int r2[] = {4, 5, 6};
    int r3[] = {7, 8, 9};
    int* matrix1[] = {r1, r2, r3};
    int cols1[] = {3, 3, 3};
    printf("Example 1 before:\n"); printMatrix((int**)matrix1, 3);
    rotate((int**)matrix1, 3, cols1);
    printf("Example 1 after:\n");  printMatrix((int**)matrix1, 3);

    int r4[] = { 5,  1,  9, 11};
    int r5[] = { 2,  4,  8, 10};
    int r6[] = {13,  3,  6,  7};
    int r7[] = {15, 14, 12, 16};
    int* matrix2[] = {r4, r5, r6, r7};
    int cols2[] = {4, 4, 4, 4};
    printf("Example 2 before:\n"); printMatrix((int**)matrix2, 4);
    rotate((int**)matrix2, 4, cols2);
    printf("Example 2 after:\n");  printMatrix((int**)matrix2, 4);

    return 0;
}
