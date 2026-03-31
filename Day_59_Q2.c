#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Simple hashmap using array (since constraints usually small)
// You can adjust size if needed
int map[10001];

// Build tree
struct TreeNode* build(int inorder[], int postorder[], int left, int right, int* postIndex) {
    if (left > right)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    int index = map[rootVal];

    // Build RIGHT first
    root->right = build(inorder, postorder, index + 1, right, postIndex);
    root->left = build(inorder, postorder, left, index - 1, postIndex);

    return root;
}

// Preorder traversal (for checking)
void preorder(struct TreeNode* root) {
    if (!root) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    // Store inorder indices in map
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &postIndex);

    // Output preorder traversal
    preorder(root);

    return 0;
}
