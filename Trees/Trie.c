#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Create a new node
TrieNode* createNode() {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) node->children[i] = NULL;
    return node;
}

// Insert a word: O(Length of word)
void insert(TrieNode *root, const char *key) {
    TrieNode *curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a'; // Map 'a'-'z' to 0-25
        if (!curr->children[index]) 
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

// Search for a word: O(Length of word)
bool search(TrieNode *root, const char *key) {
    TrieNode *curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!curr->children[index]) return false;
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

int main() {
    TrieNode *root = createNode();
    
    insert(root, "apple");
    insert(root, "app");

    printf("Search 'app': %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search 'banana': %s\n", search(root, "banana") ? "Found" : "Not Found");

    return 0;
}