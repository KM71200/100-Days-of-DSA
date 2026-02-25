/*Cycle count*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to detect cycle and return starting node
struct Node* detectCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct Node *slow = head, *fast = head;


    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { 
            
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  
        }
    }

    return NULL; 
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *cycleNode = NULL;

 
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

      
        if (i == pos)
            cycleNode = newNode;
    }

    scanf("%d", &pos);

   
    if (pos != -1) {
        temp->next = cycleNode;
    }

    struct Node* result = detectCycle(head);

    if (result == NULL)
        printf("no cycle\n");
    else
        printf("tail connects to node with value %d\n", result->data);

    return 0;
}