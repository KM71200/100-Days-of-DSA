#include <stdio.h>
#include <stdlib.h>

/**
 * Function to return product of array except self
 */
int* productExceptSelf(int* nums, int numsSize) {
    
    int* answer = (int*)malloc(numsSize * sizeof(int));

    // Prefix products
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Suffix products
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * right;
        right *= nums[i];
    }

    return answer;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int* result = productExceptSelf(nums, n);

    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    // Free allocated memory
    free(nums);
    free(result);

    return 0;
}
