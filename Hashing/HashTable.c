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


int main(int argc,char **argv/* yes i do this now too. cuz I am cool AF */) {
    HashTable *ht = create_table();

        unsigned int index = hash("bhino");
        printf("It goes in bucket: %u\n", index);
    

    return 0;
}