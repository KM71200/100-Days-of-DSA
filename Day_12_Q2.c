/*Toeplitz Matrix*/
#include <stdio.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] != matrix[i-1][j-1])
                return false;

    return true;
}

int main() {
   
    int r1[] = {1, 2, 3, 4};
    int r2[] = {5, 1, 2, 3};
    int r3[] = {9, 5, 1, 2};
    int* matrix1[] = {r1, r2, r3};
    int cols1[] = {4, 4, 4};
    printf("Example 1: %s\n", isToeplitzMatrix((int**)matrix1, 3, cols1) ? "true" : "false");

   
    int r4[] = {1, 2};
    int r5[] = {2, 2};
    int* matrix2[] = {r4, r5};
    int cols2[] = {2, 2};
    printf("Example 2: %s\n", isToeplitzMatrix((int**)matrix2, 2, cols2) ? "true" : "false");

    return 0;
}
