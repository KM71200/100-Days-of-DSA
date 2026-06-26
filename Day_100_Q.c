#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} Node;

void merge(Node arr[], Node temp[], int left, int mid, int right, int count[])
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i].value <= arr[j].value)
        {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
        else
        {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(Node arr[], Node temp[], int left, int right, int count[])
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, left, mid, count);
    mergeSort(arr, temp, mid + 1, right, count);

    merge(arr, temp, left, mid, right, count);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    Node arr[n], temp[n];
    int count[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, 0, n - 1, count);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    printf("\n");

    return 0;
}
