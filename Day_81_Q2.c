#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return false;


    if (root->left == NULL && root->right == NULL) {
        return (targetSum == root->val);
    }

    int remaining = targetSum - root->val;

    return hasPathSum(root->left, remaining) ||
           hasPathSum(root->right, remaining);
}

int main() {


    struct TreeNode* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);

    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);

    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
