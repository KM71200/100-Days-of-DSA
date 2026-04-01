//Binary tree camera
#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera
    }

    if (left == 1 || right == 1) {
        return 2; // covered
    }

    return 0; // needs camera
}

// Main function to calculate cameras
int minCameraCover(struct TreeNode* root) {
    cameras = 0;

    if (dfs(root) == 0)
        cameras++;

    return cameras;
}

int main() {
    /*
        Example Tree:
              0
             /
            0
           / \
          0   0

        Input: [0,0,null,0,0]
    */

    struct TreeNode* root = createNode(0);
    root->left = createNode(0);
    root->left->left = createNode(0);
    root->left->right = createNode(0);

    int result = minCameraCover(root);
    printf("Minimum Cameras Needed: %d\n", result);

    return 0;
}
