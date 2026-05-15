#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[N] = {NULL};

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[N] = {0.78, 0.17, 0.39, 0.26, 0.72,
                    0.94, 0.21, 0.12, 0.23, 0.68};

    printf("Original Array:\n");
    printArray(arr, N);

    bucketSort(arr, N);

    printf("Sorted Array:\n");
    printArray(arr, N);

    return 0;
}
