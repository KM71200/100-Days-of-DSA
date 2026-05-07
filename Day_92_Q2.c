int partition(int* nums, int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }

    int temp = nums[i];
    nums[i] = nums[high];
    nums[high] = temp;

    return i;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k; 

    int low = 0, high = numsSize - 1;

    while (low <= high) {
        int p = partition(nums, low, high);

        if (p == target)
            return nums[p];
        else if (p < target)
            low = p + 1;
        else
            high = p - 1;
    }

    return -1;
}
