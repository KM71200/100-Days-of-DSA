/*Problem: Count Nodes in Linked List

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

struct node *createnode(int x){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

struct node *insertend(struct node *head, int x){
    struct node *newnode = createnode(x);

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head; 
}

int countnode(struct node* head){
    int count = 0;

    while (head != NULL){
        count++;
        head = head->next;
    }

    return count;
}

int main(){
    struct node *head = NULL;
    int n, x;

    scanf("%d",&n);

    for (int i=0; i<n ; i++){
        scanf("%d",&x);
        head = insertend(head,x);
    }

    printf("%d", countnode(head));

    return 0;
}