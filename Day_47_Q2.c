/*Maximum Depth of Binary Tree*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct TreeNode* arr[10000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == -1)
        q->front = q->rear = 0;
    else
        q->rear++;

    q->arr[q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* temp = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct TreeNode* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    int depth = maxDepth(root);
    printf("%d\n", depth);

    return 0;
}