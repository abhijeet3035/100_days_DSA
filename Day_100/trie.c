// Day 100: Trie (Prefix Tree) Implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode *root, char *key) {
    struct TrieNode *curr = root;
    for (int i = 0; key[i]; i++) {
        int idx = key[i] - 'a';
        if (!curr->children[idx]) curr->children[idx] = createNode();
        curr = curr->children[idx];
    }
    curr->isEndOfWord = 1;
    printf("Inserted: %s\n", key);
}

int search(struct TrieNode *root, char *key) {
    struct TrieNode *curr = root;
    for (int i = 0; key[i]; i++) {
        int idx = key[i] - 'a';
        if (!curr->children[idx]) return 0;
        curr = curr->children[idx];
    }
    return curr->isEndOfWord;
}

int startsWith(struct TrieNode *root, char *prefix) {
    struct TrieNode *curr = root;
    for (int i = 0; prefix[i]; i++) {
        int idx = prefix[i] - 'a';
        if (!curr->children[idx]) return 0;
        curr = curr->children[idx];
    }
    return 1;
}

int main() {
    struct TrieNode *root = createNode();
    insert(root, "hello");
    insert(root, "help");
    insert(root, "world");
    insert(root, "word");

    char word[100];
    printf("\nEnter word to search: "); scanf("%s", word);
    printf("Search '%s': %s\n", word, search(root, word) ? "Found" : "Not Found");

    printf("Enter prefix to check: "); scanf("%s", word);
    printf("Prefix '%s': %s\n", word, startsWith(root, word) ? "Exists" : "Not Found");

    return 0;
}
