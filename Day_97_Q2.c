#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int start[], int end[], int n)
{
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < n)
    {
        if (start[i] < end[j])
        {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main()
{
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter end times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &end[i]);

    printf("Minimum rooms required = %d\n", minMeetingRooms(start, end, n));

    return 0;
}
