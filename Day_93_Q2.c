#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = 
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct ListNode** head, int val) {

    struct ListNode* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

struct ListNode* insertionSortList(struct ListNode* head) {

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {

        struct ListNode* nextNode = curr->next;

        struct ListNode* prev = &dummy;

        while (prev->next != NULL &&
               prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = nextNode;
    }

    return dummy.next;
}

void printList(struct ListNode* head) {

    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}

int main() {

    struct ListNode* head = NULL;

    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 1);
    insertEnd(&head, 3);

    printf("Original List:\n");
    printList(head);

    head = insertionSortList(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
