/*Sum of Left Leaves*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isLeaf(struct TreeNode* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    if (isLeaf(root->left)) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {


    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = sumOfLeftLeaves(root);

    printf("Sum of left leaves = %d\n", result);

    return 0;
}