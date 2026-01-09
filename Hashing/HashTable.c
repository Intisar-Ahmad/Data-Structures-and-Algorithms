#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// yes, I am defining the table size like this. do something about it.
#define TABLE_SIZE 10 

typedef struct Node{
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct 
{
    Node* buckets[TABLE_SIZE];
}HashTable;

unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    return value % TABLE_SIZE;
}

HashTable* create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    
    if (table == NULL) return NULL;

    for (int i = 0; i < TABLE_SIZE; ++i) {
        table->buckets[i] = NULL;
    }
    
    return table;
}



void insert(HashTable *table, const char *key, int value) {
    unsigned int index = hash(key);
    
    //  Check if the key already exists in the bucket
    Node *current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value; // Update existing key
            return;
        }
        current = current->next;
    }

    // If key doesn't exist, create a new node (Insert case)
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return; 

    new_node->key = strdup(key); // Copy the string so it persists
    new_node->value = value;
    
    // Insert at the head of the list (Fastest way)
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}


int main(int argc,char **argv/* yes i do this now too. cuz I am cool AF */) {
    HashTable *ht = create_table();

        unsigned int index = hash("bhino");
        printf("It goes in bucket: %u\n", index);
    

    return 0;
}