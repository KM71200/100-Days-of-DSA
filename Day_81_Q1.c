#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

TrieNode* trieCreate() {
    return createNode();
}

void insert(TrieNode* root, char* word) {
    TrieNode* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            curr->children[index] = createNode();

        curr = curr->children[index];
    }

    curr->isEndOfWord = true;
}

bool search(TrieNode* root, char* word) {
    TrieNode* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            return false;

        curr = curr->children[index];
    }

    return curr->isEndOfWord;
}

bool startsWith(TrieNode* root, char* prefix) {
    TrieNode* curr = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (curr->children[index] == NULL)
            return false;

        curr = curr->children[index];
    }

    return true;
}
