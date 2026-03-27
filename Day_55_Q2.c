/*Binary Tree Right Side View*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* queue[1000];
int front = -1, rear = -1;

void enqueue(struct TreeNode* node) {
    if (rear == -1) front = rear = 0;
    else rear++;
    queue[rear] = node;
}

struct TreeNode* dequeue() {
    struct TreeNode* temp = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return temp;
}

int isEmpty() {
    return front == -1;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (!isEmpty() && i < n) {
        struct TreeNode* curr = dequeue();

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

void rightSideView(struct TreeNode* root) {
    if (!root) return;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue();

            if (i == size - 1) {
                printf("%d ", curr->val);
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

    struct TreeNode* root = buildTree(arr, n);

    rightSideView(root);

    return 0;
}