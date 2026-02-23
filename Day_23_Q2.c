/*Detect Cycle*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool hasCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    if (n == 0) {
        printf("false");
        return 0;
    }

    int value;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* cycleNode = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (i == pos)
            cycleNode = newNode;
    }

    scanf("%d", &pos);

    if (pos != -1) {
        struct Node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;

        tail->next = temp;  
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}