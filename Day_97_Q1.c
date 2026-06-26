#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;


int compare(const void *a, const void *b)
{
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapInsert(int heap[], int *size, int value)
{
    int i = (*size)++;
    heap[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}


int heapRemoveMin(int heap[], int *size)
{
    int min = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return min;
}

int main()
{
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting meetings[n];

    printf("Enter start and end time of each meeting:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &meetings[i].start, &meetings[i].end);


    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++)
    {

        while (heapSize > 0 && heap[0] <= meetings[i].start)
            heapRemoveMin(heap, &heapSize);

       
        heapInsert(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    printf("Minimum rooms required = %d\n", maxRooms);

    return 0;
}
