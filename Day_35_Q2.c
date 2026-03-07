/**/

#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int x)
{
    s1[++top1] = x;
}

int pop()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    return s2[top2--];
}

int peek()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    return s2[top2];
}

int empty()
{
    if(top1 == -1 && top2 == -1)
        return 1;
    else
        return 0;
}

int main()
{
    push(1);
    push(2);

    printf("Front element: %d\n", peek());
    printf("Popped element: %d\n", pop());

    if(empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}