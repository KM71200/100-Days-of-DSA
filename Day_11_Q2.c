/*Transposse Matrix*/
#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {
    int m = matrixSize;
    int n = matrixColSize[0];


    int** result = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[i][j] = matrix[j][i];

    *returnSize = n;
    return result;
}

void printMatrix(int** matrix, int rows, int* colSizes) {
    printf("[\n");
    for (int i = 0; i < rows; i++) {
        printf("  [");
        for (int j = 0; j < colSizes[i]; j++)
            printf(j < colSizes[i] - 1 ? "%d," : "%d", matrix[i][j]);
        printf("]\n");
    }
    printf("]\n");
}

int main() {
   
    int rows1[] = {1,2,3};
    int rows2[] = {4,5,6};
    int rows3[] = {7,8,9};
    int* matrix1[] = {rows1, rows2, rows3};
    int colSizes1[] = {3, 3, 3};

    int returnSize1;
    int* returnColSizes1;
    int** result1 = transpose((int**)matrix1, 3, colSizes1,
                               &returnSize1, &returnColSizes1);

    printf("Example 1 Input:\n");
    printMatrix((int**)matrix1, 3, colSizes1);
    printf("Example 1 Output:\n");
    printMatrix(result1, returnSize1, returnColSizes1);

    int r1[] = {1,2,3};
    int r2[] = {4,5,6};
    int* matrix2[] = {r1, r2};
    int colSizes2[] = {3, 3};

    int returnSize2;
    int* returnColSizes2;
    int** result2 = transpose((int**)matrix2, 2, colSizes2,
                               &returnSize2, &returnColSizes2);

    printf("Example 2 Input:\n");
    printMatrix((int**)matrix2, 2, colSizes2);
    printf("Example 2 Output:\n");
    printMatrix(result2, returnSize2, returnColSizes2);


    for (int i = 0; i < returnSize1; i++) free(result1[i]);
    free(result1);
    free(returnColSizes1);

    for (int i = 0; i < returnSize2; i++) free(result2[i]);
    free(result2);
    free(returnColSizes2);

    return 0;
}
