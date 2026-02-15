/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements. 
The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/

#include <stdio.h>
int main(){
    int r, c , s=0;
    printf("Enter number of rows and columns:");
    scanf("%d %d",&r,&c);
    int arr[r][c];

    printf("Enter elements of Matrix:\n");
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            scanf("%d",&arr[i][j]);
            
        }
    }
    
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (i==j){
                s += arr[i][j];
            }
        }
    }
    printf("Sum of diagonal element:%d",s);
    return 0;
}