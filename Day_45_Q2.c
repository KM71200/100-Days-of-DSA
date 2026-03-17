/*Maximum Depth of Binary Tree*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}


struct TreeNode* buildTree(int* nodes, int n) {
    if (n == 0 || nodes[0] == -1) return NULL;

    struct TreeNode* queue[10001];
    int front = 0, back = 0;

    struct TreeNode* root = newNode(nodes[0]);
    queue[back++] = root;

    int i = 1;
    while (front < back && i < n) {
        struct TreeNode* node = queue[front++];

        if (i < n && nodes[i] != -1) {
            node->left = newNode(nodes[i]);
            queue[back++] = node->left;
        }
        i++;

        if (i < n && nodes[i] != -1) {
            node->right = newNode(nodes[i]);
            queue[back++] = node->right;
        }
        i++;
    }

    return root;
}

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;

    struct TreeNode* queue[10001];
    int front = 0, back = 0, depth = 0;
    queue[back++] = root;

    while (front < back) {
        int size = back - front;
        depth++;
        while (size--) {
            struct TreeNode* node = queue[front++];
            if (node->left)  queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }
    }

    return depth;
}

int main() {
    
    int nodes1[] = {3, 9, 20, -1, -1, 15, 7};
    struct TreeNode* root1 = buildTree(nodes1, 7);
    printf("Example 1: %d\n", maxDepth(root1)); 

    
    int nodes2[] = {1, -1, 2};
    struct TreeNode* root2 = buildTree(nodes2, 3);
    printf("Example 2: %d\n", maxDepth(root2)); 

    return 0;
}
