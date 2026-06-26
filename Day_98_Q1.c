#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;


int compare(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter start and end of each interval:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

   
    qsort(arr, n, sizeof(Interval), compare);

    printf("\nMerged Intervals:\n");

    int start = arr[0].start;
    int end = arr[0].end;

    for (int i = 1; i < n; i++)
    {

        if (arr[i].start <= end)
        {
            if (arr[i].end > end)
                end = arr[i].end;
        }
        else
        {
         
            printf("[%d, %d]\n", start, end);

            start = arr[i].start;
            end = arr[i].end;
        }
    }

 
    printf("[%d, %d]\n", start, end);

    return 0;
}
