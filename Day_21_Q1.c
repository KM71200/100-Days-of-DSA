/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

   
    scanf("%d", &n);


    if (n <= 0)
        return 0;


    scanf("%d", &value);
    head = (struct node*)malloc(sizeof(struct node));
    head->data = value;
    head->next = NULL;
    temp = head;

    for (i = 1; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }


    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}