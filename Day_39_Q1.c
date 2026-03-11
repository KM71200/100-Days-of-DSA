/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(heap[parent] > heap[i])
        {
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapifyDown(int i)
{
    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);
}

void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'i')   
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'e')   
        {
            extractMin();
        }
        else if(op[0] == 'p')   
        {
            peek();
        }
    }

    return 0;
}