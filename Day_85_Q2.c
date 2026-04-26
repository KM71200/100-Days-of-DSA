/*Find minimum in Rotated Sorted Array*/
#include <stdio.h>

int findMin(int arr[], int n)
{
    int low = 0, high = n - 1;

    while(low < high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] > arr[high])
            low = mid + 1; 
        else
            high = mid;      
    }

    return arr[low];
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter rotated sorted array elements: ");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("Minimum element = %d", findMin(arr,n));

    return 0;
}