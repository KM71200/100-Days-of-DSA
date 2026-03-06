/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[100];
    int i=0,a,b,result;

    printf("Enter postfix expression: ");
    fgets(exp,100,stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i]-'0');
        }

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            a = pop();
            b = pop();

            switch(exp[i])
            {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }

            push(result);
        }

        i++;
    }

    printf("Result = %d", pop());

    return 0;
}