/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = low + (high - low)/2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, i, key;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter sorted elements: ");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);

    int result = binarySearch(arr, n, key);

    if(result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}