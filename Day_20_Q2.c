//3_SUM

#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 3) {
        printf("No triplets possible\n");
        return 0;
    }

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int found = 0;

   
    for(int i = 0; i < n - 2; i++) {

        
        if(i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if(sum == 0) {
                printf("[%d, %d, %d]\n", arr[i], arr[left], arr[right]);
                found = 1;

                left++;
                right--;

                
                while(left < right && arr[left] == arr[left - 1])
                    left++;

                while(left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    if(!found) {
        printf("No triplets found\n");
    }

    return 0;
}