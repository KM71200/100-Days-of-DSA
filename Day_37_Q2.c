/**/
#include <stdio.h>

int arr[10000];
int size = 0;
int k;

void sort()
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] < arr[j])  
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void add(int val)
{
    arr[size++] = val;

    sort();

    if(size < k)
        printf("-1\n");
    else
        printf("%d\n", arr[k-1]);
}

int main()
{
    int n, x;

    scanf("%d",&k);
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        arr[size++] = x;
    }

    sort();

    int q;
    scanf("%d",&q);

    while(q--)
    {
        int val;
        scanf("%d",&val);
        add(val);
    }

    return 0;
}