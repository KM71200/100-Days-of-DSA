/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements of array:");
    for (int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    int min_sum = arr[0] + arr[1];
    int num1 = arr[0];
    int num2 = arr[1];

    for (int i=0 ; i<n ; i++){
        for (int j = i+1 ; j<n ; j++){
            int sum = arr[i] + arr[j];

            int current_abs = sum;
            
            if(current_abs < 0){
                current_abs = -current_abs;
            }

            int min_abs = min_sum;
            if(min_abs < 0){
                min_abs = -min_abs;
            }
            
            if (current_abs < min_abs){
                min_sum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }

        }
    }
    printf("Pair of numbers whose sum is closest to zero:(%d,%d)",num1,num2);
    return 0;
}