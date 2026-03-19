/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count[1001] = {0};

   
    for (int i = 0; i < nums1Size; i++)
        count[nums1[i]]++;

   
    int minSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(minSize * sizeof(int));
    int idx = 0;

    
    for (int i = 0; i < nums2Size; i++) {
        if (count[nums2[i]] > 0) {
            result[idx++] = nums2[i];
            count[nums2[i]]--;
        }
    }

    *returnSize = idx;
    return result;
}

int main() {
    int returnSize;

   
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int* res1 = intersect(nums1, 4, nums2, 2, &returnSize);
    printf("Example 1: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", res1[i]);
    printf("\n");
    free(res1);

   
    int nums3[] = {4, 9, 5};
    int nums4[] = {9, 4, 9, 8, 4};
    int* res2 = intersect(nums3, 3, nums4, 5, &returnSize);
    printf("Example 2: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", res2[i]);
    printf("\n");
    free(res2);

    return 0;
}
