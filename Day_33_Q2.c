/*Evaluate Reverse Polish Notation*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;
    char tokens[100][20];

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    printf("Enter tokens:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%s", tokens[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0)
        {
            int b = pop();
            int a = pop();
            int result;

            if(strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if(strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if(strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;

            push(result);
        }
        else
        {
            push(atoi(tokens[i]));
        }
    }

    printf("Result = %d", pop());

    return 0;
}