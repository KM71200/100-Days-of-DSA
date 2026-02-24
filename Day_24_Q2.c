#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};


struct Node* removeElements(struct Node* head, int val) {
    

    struct Node dummy;
    dummy.next = head;
    
    struct Node *prev = &dummy;
    struct Node *curr = head;
    
    while(curr != NULL) {
        if(curr->val == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return dummy.next;
}

int main() {
    int n, value, val;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &val);

   
    head = removeElements(head, val);
\
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}