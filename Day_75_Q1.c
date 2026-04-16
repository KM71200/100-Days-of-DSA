/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/


#include <stdio.h>

// Structure for storing prefix sum and index
struct Map {
    int sum;
    int index;
};

int maxLenZeroSum(int arr[], int n) {
    struct Map map[1000];
    int size = 0;

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum becomes 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Check if prefixSum seen before
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (map[j].sum == prefixSum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - map[found].index;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // store first occurrence
            map[size].sum = prefixSum;
            map[size].index = i;
            size++;
        }
    }

    return maxLen;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLenZeroSum(arr, n);
    printf("Length of longest zero sum subarray: %d\n", result);

    return 0;
}