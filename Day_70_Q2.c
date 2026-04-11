/*Cheapest Flights Within K Stops*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    
    int dist[n];
    
    // Initialize distances
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;
    
    // Bellman-Ford with k+1 relaxations
    for(int i = 0; i <= k; i++) {
        int temp[n];
        
        for(int j = 0; j < n; j++)
            temp[j] = dist[j];
        
        for(int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];
            
            if(dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        
        for(int j = 0; j < n; j++)
            dist[j] = temp[j];
    }
    
    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main() {
    int n = 4;
    int flights[][3] = {
        {0,1,100},
        {1,2,100},
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };
    
    int flightsSize = 5;
    int src = 0, dst = 3, k = 1;
    
    int result = findCheapestPrice(n, flights, flightsSize, src, dst, k);
    
    printf("Cheapest Price: %d\n", result);
    
    return 0;
}