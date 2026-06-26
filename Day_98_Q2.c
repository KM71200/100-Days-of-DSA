#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

// Comparator for sorting by start time
int compare(const void *a, const void *b)
{
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(Interval), compare);

    Interval merged[n];
    int k = 0;


    merged[0] = intervals[0];


    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start <= merged[k].end)
        {
       
            if (intervals[i].end > merged[k].end)
                merged[k].end = intervals[i].end;
        }
        else
        {
        
            k++;
            merged[k] = intervals[i];
        }
    }

    printf("\nMerged Intervals:\n");
    for (int i = 0; i <= k; i++)
    {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }

    return 0;
}
