/*Valid parenthesis*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s) {
    int n = strlen(s);
    char stack[n];     
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

       
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
       
        else {
            if (top == -1)   
                return false;

            char topChar = stack[top--];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return (top == -1); 
}

int main() {
    char s[10005];

    printf("Enter string: ");
    scanf("%s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}