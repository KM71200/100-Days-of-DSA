/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter elements of array:\n");
    for (int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    int max = arr[0];
    for (int i=0; i<n ; i++){
        if (arr[i] > max)
            max = arr[i];       
    }

    int size = max +1;
    int freq[size];

    for (int i=0 ; i<size ; i++){
        freq[i] = 0;
    }

    for (int i=0 ; i<n ; i++){
        freq[arr[i]] ++;
    }

    for (int i=0; i<size ; i++){
        if (freq[i] > 0)
            printf("%d:%d ", i , freq[i]);
    }
    return 0;

}