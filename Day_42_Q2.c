/*Find Median from Data Stream*/
#include <stdio.h>

#define MAX 100

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;


void insertMax(int val)
{
    int i = maxSize++;
    maxHeap[i] = val;

    while(i > 0 && maxHeap[(i-1)/2] < maxHeap[i])
    {
        int t = maxHeap[i];
        maxHeap[i] = maxHeap[(i-1)/2];
        maxHeap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int extractMax()
{
    int val = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;

    while(1)
    {
        int l = 2*i+1, r = 2*i+2, largest = i;

        if(l < maxSize && maxHeap[l] > maxHeap[largest])
            largest = l;

        if(r < maxSize && maxHeap[r] > maxHeap[largest])
            largest = r;

        if(largest == i) break;

        int t = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = t;

        i = largest;
    }

    return val;
}



void insertMin(int val)
{
    int i = minSize++;
    minHeap[i] = val;

    while(i > 0 && minHeap[(i-1)/2] > minHeap[i])
    {
        int t = minHeap[i];
        minHeap[i] = minHeap[(i-1)/2];
        minHeap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int extractMin()
{
    int val = minHeap[0];
    minHeap[0] = minHeap[--minSize];

    int i = 0;

    while(1)
    {
        int l = 2*i+1, r = 2*i+2, smallest = i;

        if(l < minSize && minHeap[l] < minHeap[smallest])
            smallest = l;

        if(r < minSize && minHeap[r] < minHeap[smallest])
            smallest = r;

        if(smallest == i) break;

        int t = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = t;

        i = smallest;
    }

    return val;
}



void addNum(int num)
{
    insertMax(num);
    insertMin(extractMax());

    if(minSize > maxSize)
        insertMax(extractMin());
}


double findMedian()
{
    if(maxSize > minSize)
        return maxHeap[0];

    return (maxHeap[0] + minHeap[0]) / 2.0;
}



int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        addNum(x);

        printf("Median = %.1f\n", findMedian());
    }

    return 0;
}