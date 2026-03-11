/*Top K frequent Element*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Node;

int cmp(const void *a, const void *b)
{
    Node *x = (Node*)a;
    Node *y = (Node*)b;
    return y->freq - x->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    Node arr[numsSize];
    int size = 0;

    for(int i = 0; i < numsSize; i++)
    {
        int found = 0;

        for(int j = 0; j < size; j++)
        {
            if(arr[j].num == nums[i])
            {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            arr[size].num = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(Node), cmp);

    int *res = (int*)malloc(k * sizeof(int));

    for(int i = 0; i < k; i++)
        res[i] = arr[i].num;

    *returnSize = k;
    return res;
}

int main()
{
    int nums[] = {1,1,1,2,2,3};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    int returnSize;

    int *ans = topKFrequent(nums, n, k, &returnSize);

    printf("Top %d frequent elements: ", k);
    for(int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);

    free(ans);
    return 0;
}