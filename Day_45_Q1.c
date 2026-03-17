/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int* nodes, int n) {
    if (n == 0 || nodes[0] == -1) return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    Node* root = newNode(nodes[0]);
    int front = 0, back = 0;
    queue[back++] = root;

    int i = 1;
    while (front < back && i < n) {
        Node* node = queue[front++];

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

    free(queue);
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int main() {
    int n;
    scanf("%d", &n);

    int* vals = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &vals[i]);

    Node* root = buildTree(vals, n);
    printf("%d\n", height(root));

    free(vals);
    return 0;
}