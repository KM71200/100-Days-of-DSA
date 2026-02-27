/*Remove cycle in a ;inked list*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}


void createCycle(struct Node* head, int pos) {
    if(pos == -1) return;

    struct Node *temp = head, *cycleNode = NULL;
    int index = 0;

    while(temp->next != NULL) {
        if(index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if(cycleNode != NULL)
        temp->next = cycleNode;
}


bool removeCycle(struct Node* head) {
    if(head == NULL) return false;

    struct Node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
         

            slow = head;

            if(slow == fast) {
                while(fast->next != slow)
                    fast = fast->next;
            } else {
                while(slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

         
            fast->next = NULL;
            return true;
        }
    }

    return true;
}

int main() {
    int n, pos;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &pos);  

    createCycle(head, pos);

    if(removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}