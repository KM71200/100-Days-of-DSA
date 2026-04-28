/*Koko Eating Bananas*/
#include <stdio.h>

int minEatingSpeed(int piles[], int n, int h)
{
    int left = 1;
    int right = piles[0];

    for(int i = 1; i < n; i++)
    {
        if(piles[i] > right)
            right = piles[i];
    }

    while(left < right)
    {
        int mid = left + (right - left)/2;
        long long hours = 0;

        for(int i = 0; i < n; i++)
        {
            hours += (piles[i] + mid - 1) / mid; 
        }

        if(hours <= h)
            right = mid;      
        else
            left = mid + 1;   
    }

    return left;
}

int main()
{
    int n, h;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    printf("Enter bananas in each pile: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &piles[i]);

    printf("Enter hours h: ");
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);

    printf("Minimum eating speed = %d\n", result);

    return 0;
}