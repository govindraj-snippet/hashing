#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for linked list in chaining
struct Node {
    int key;
    struct Node* next;
};

// Hash Table structure
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// Hash function: Simple Modulo-based hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to initialize hash table
void initHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Insert function for Chaining
void insertChaining(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search function for Chaining
int searchChaining(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* temp = ht->table[index];
    while (temp) {
        if (temp->key == key) {
            return 1; // Found
        }
        temp = temp->next;
    }
    return 0; // Not found
}

// Delete function for Chaining
void deleteChaining(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* temp = ht->table[index];
    struct Node* prev = NULL;
    while (temp) {
        if (temp->key == key) {
            if (prev) {
                prev->next = temp->next;
            } else {
                ht->table[index] = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Print function for Chaining
void printChaining(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = ht->table[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable ht;
    initHashTable(&ht);

    insertChaining(&ht, 15);
    insertChaining(&ht, 25);
    insertChaining(&ht, 35);
    insertChaining(&ht, 12);
    insertChaining(&ht, 22);

    printChaining(&ht);

    if (searchChaining(&ht, 25)) {
        printf("Key 25 found.\n");
    } else {
        printf("Key 25 not found.\n");
    }

    deleteChaining(&ht, 25);
    printChaining(&ht);

    return 0;
}