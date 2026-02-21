/*Middle of linked list*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main() {
    int n, i, value;
    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n <= 0) return 0;

    
    scanf("%d", &value);
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = value;
    head->next = NULL;
    temp = head;

 
    for (i = 1; i < n; i++) {
        scanf("%d", &value);
        
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = value;
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = newNode;
    }

  
    struct ListNode *middle = middleNode(head);

   
    while (middle != NULL) {
        printf("%d ", middle->val);
        middle = middle->next;
    }

    return 0;
}