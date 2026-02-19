#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    
    int totalSum = 0;
    
    int currMax = nums[0];
    int maxSum = nums[0];
    
    int currMin = nums[0];
    int minSum = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        
        totalSum += nums[i];
        
        if(i > 0) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
            
            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }
    }
    

    if(maxSum < 0)
        return maxSum;
    
    return max(maxSum, totalSum - minSum);
}

int main() {

    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);

    printf("Maximum Circular Subarray Sum = %d\n", result);

    return 0;
}
