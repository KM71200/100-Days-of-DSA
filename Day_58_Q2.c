#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int* preorder, int* inorder, int inStart, int inEnd, int* preIdx) {
    if (inStart > inEnd) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preIdx];
    root->left = root->right = NULL;
    (*preIdx)++;

    // Find root in inorder
    int mid = inStart;
    while (inorder[mid] != root->val) mid++;

    root->left  = build(preorder, inorder, inStart, mid - 1, preIdx);
    root->right = build(preorder, inorder, mid + 1, inEnd,   preIdx);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIdx = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIdx);
}

// --- Helper: print level-order (BFS) to verify ---
void printLevelOrder(struct TreeNode* root) {
    if (!root) { printf("[]\n"); return; }

    struct TreeNode* queue[6001];
    int front = 0, back = 0;
    queue[back++] = root;

    printf("[");
    int first = 1;
    while (front < back) {
        struct TreeNode* node = queue[front++];
        if (!first) printf(",");
        first = 0;
        if (node) {
            printf("%d", node->val);
            queue[back++] = node->left;
            queue[back++] = node->right;
        } else {
            printf("null");
        }
    }
    printf("]\n");
}

int main() {
    // Example 1
    int pre1[] = {3, 9, 20, 15, 7};
    int in1[]  = {9, 3, 15, 20, 7};
    struct TreeNode* tree1 = buildTree(pre1, 5, in1, 5);
    printf("Example 1: ");
    printLevelOrder(tree1);

    // Example 2
    int pre2[] = {-1};
    int in2[]  = {-1};
    struct TreeNode* tree2 = buildTree(pre2, 1, in2, 1);
    printf("Example 2: ");
    printLevelOrder(tree2);

    return 0;
}