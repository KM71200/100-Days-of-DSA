/*Binary Tree Level Order Traversal*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void levelOrder(struct TreeNode* root)
{
    if(root == NULL)
        return;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("[\n");

    while(front < rear)
    {
        int levelSize = rear - front;

        printf("  [");

        for(int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];

            printf("%d", node->val);

            if(i < levelSize - 1)
                printf(",");

            if(node->left)
                queue[rear++] = node->left;

            if(node->right)
                queue[rear++] = node->right;
        }

        printf("]");

        if(front < rear)
            printf(",");

        printf("\n");
    }

    printf("]\n");
}

int main()
{
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    levelOrder(root);

    return 0;
}