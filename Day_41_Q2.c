/*Task Scheduler*/
#include <stdio.h>

int main() {
    int n, cool;
    scanf("%d", &n);  
    
    char tasks[n];
    for(int i = 0; i < n; i++)
        scanf(" %c", &tasks[i]);

    scanf("%d", &cool);   

    int freq[26] = {0};

    for(int i = 0; i < n; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxFreq)
            maxFreq = freq[i];

    int maxCount = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq)
            maxCount++;

    int time = (maxFreq - 1) * (cool + 1) + maxCount;

    if(n > time)
        printf("%d", n);
    else
        printf("%d", time);

    return 0;
}