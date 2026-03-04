/*Min Stack*/
#include <stdio.h>
#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;

void push(int val)
{
    top++;
    stack[top] = val;

    if(top == 0)
        minStack[top] = val;
    else if(val < minStack[top-1])
        minStack[top] = val;
    else
        minStack[top] = minStack[top-1];
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int peek()
{
    return stack[top];
}

int getMin()
{
    return minStack[top];
}

int main()
{
    push(-2);
    push(0);
    push(-3);

    printf("Minimum: %d\n", getMin()); // -3

    pop();

    printf("Top: %d\n", peek()); // 0
    printf("Minimum: %d\n", getMin()); // -2

    return 0;
}