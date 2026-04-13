/*Travelling Salesman Problem*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 15

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int mask, int pos) {
    // if all cities visited
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; // return to start
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // not visited
            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize DP with -1
    memset(dp, -1, sizeof(dp));

    // Start from city 0 (mask = 1)
    int result = solve(1, 0);

    printf("%d\n", result);

    return 0;
}