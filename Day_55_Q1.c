/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* queue[1000];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = node;
}

struct Node* dequeue() {
    struct Node* temp = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return temp;
}

int isEmpty() {
    return front == -1;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

void rightView(struct Node* root) {
    if (!root) return;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();

            if (i == size - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}