/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8
*/

#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid == n / mid && n % mid == 0)
            return mid;

        if (mid <= n / mid) {
            ans = mid;      
            low = mid + 1;   
        } else {
            high = mid - 1; 
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d", integerSqrt(n));

    return 0;
}