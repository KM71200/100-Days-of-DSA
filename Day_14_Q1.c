/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. 
An identity matrix is a square matrix in which all diagonal 
elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"
*/

#include <stdio.h>
int main()
{
    int r,c,flag = 1;
    printf("Enter number of rows and columns:");
    scanf("%d %d",&r,&c);

    int arr[r][c];
    printf("Enter elements of matrix:\n");
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    if (r != c){
        printf("Not an Identity Matrix ");
    }

    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (i == j && arr[i][j] != 1){
                flag = 0;
            }
            else if (i != j && arr[i][j] != 0){
                flag = 0;
            }
        
        }

    }
    if (flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");
        
    return 0;
}
