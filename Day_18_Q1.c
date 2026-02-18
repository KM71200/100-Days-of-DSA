/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

#include <stdio.h>

void reverse(int *nums , int start , int end){
    while (start<end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int *nums , int numsize, int k){
    if (numsize == 0)
        return;
    k = k % numsize;

    reverse(nums,0,numsize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsize-1);

}



int main()
{
    int n,k;
    printf("Enter size of Array:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter array elements:\n");
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter position to rotate the array:");
    scanf("%d",&k);

    rotate(arr,n,k);

    printf("Rotated array:\n");
    for (int i=0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}