#include <stdio.h>


int canShip(int weights[], int n, int days, int capacity) {
    int d = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current + weights[i] > capacity) {
            d++;
            current = weights[i];

            if (d > days)
                return 0;
        } else {
            current += weights[i];
        }
    }
    return 1;
}


int shipWithinDays(int weights[], int n, int days) {
    int low = weights[0], high = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canShip(weights, n, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, days;

    printf("Enter number of packages: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter number of days: ");
    scanf("%d", &days);

    int result = shipWithinDays(weights, n, days);

    printf("Minimum capacity required = %d\n", result);

    return 0;
}
