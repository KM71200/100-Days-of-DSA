/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

struct node *insert_end(struct node *head , int x){
    struct node *newnode = create(x);

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

void print(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;
    int n , value;

    scanf("%d",&n);

    for (int i=0 ; i<n ; i++){
        scanf("%d",&value);
        head = insert_end(head,value);
    }

    print(head);
    return 0;
}