/*Add two number*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};


struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}


struct Node* padList(struct Node* head, int diff) {
    while (diff--) {
        struct Node* newNode = createNode(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}


struct Node* addHelper(struct Node* l1, struct Node* l2, int* carry) {
    if (!l1 && !l2)
        return NULL;

    struct Node* nextNode = addHelper(l1->next, l2->next, carry);

    int sum = l1->val + l2->val + *carry;
    *carry = sum / 10;

    struct Node* newNode = createNode(sum % 10);
    newNode->next = nextNode;

    return newNode;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {

    int len1 = getLength(l1);
    int len2 = getLength(l2);

    if (len1 < len2)
        l1 = padList(l1, len2 - len1);
    else if (len2 < len1)
        l2 = padList(l2, len1 - len2);

    int carry = 0;
    struct Node* result = addHelper(l1, l2, &carry);

    if (carry) {
        struct Node* newNode = createNode(carry);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

int main() {
    int n1, n2, val;
    struct Node *l1 = NULL, *l2 = NULL, *result = NULL;

    printf("Enter number of digits in first list: ");
    scanf("%d", &n1);
    printf("Enter digits (MSB first): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        l1 = insert(l1, val);
    }

    printf("Enter number of digits in second list: ");
    scanf("%d", &n2);
    printf("Enter digits (MSB first): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        l2 = insert(l2, val);
    }

    result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    return 0;
}