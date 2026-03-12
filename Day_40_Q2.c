/*Daily Temperatures*/
#include <stdio.h>

int main()
{
    int temperatures[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temperatures)/sizeof(temperatures[0]);

    int ans[n];
    int stack[n];
    int top = -1;

    for(int i = 0; i < n; i++)
        ans[i] = 0;

    for(int i = 0; i < n; i++)
    {
        while(top != -1 && temperatures[i] > temperatures[stack[top]])
        {
            int prev = stack[top];
            top--;
            ans[prev] = i - prev;
        }

        top++;
        stack[top] = i;
    }

    printf("Result: ");
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}