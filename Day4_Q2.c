#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If elements remain in nums2
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;

    printf("Enter number of elements in first array: ");
    scanf("%d", &m);

    printf("Enter number of elements in second array: ");
    scanf("%d", &n);

    int nums1[m + n];   // total size = m + n
    int nums2[n];

    printf("Enter %d sorted elements for first array:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Fill remaining positions with 0 (optional, just for clarity)
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    printf("Enter %d sorted elements for second array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    merge(nums1, m, nums2, n);

    printf("Merged array:\n");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
