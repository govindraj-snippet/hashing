#include <stdio.h>

#define TABLE_SIZE 10

// Hash Table with Open Addressing
struct HashTable {
    int table[TABLE_SIZE];
    int status[TABLE_SIZE]; // 0 = empty, 1 = occupied, -1 = deleted
};

// Simple hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
void initHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = -1; // -1 indicates empty slot
        ht->status[i] = 0;  // 0 means empty
    }
}

// Insert into hash table (Open Addressing)
void insertOpenAddressing(struct HashTable* ht, int key) {
    int index = hash(key);
    while (ht->status[index] == 1) {
        index = (index + 1) % TABLE_SIZE;
    }
    ht->table[index] = key;
    ht->status[index] = 1;
}

// Search in hash table (Open Addressing)
int searchOpenAddressing(struct HashTable* ht, int key) {
    int index = hash(key);
    while (ht->status[index] != 0) {
        if (ht->status[index] == 1 && ht->table[index] == key) return 1;
        index = (index + 1) % TABLE_SIZE;
    }
    return 0;
}

// Print hash table (Open Addressing)
void printOpenAddressing(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->status[i] == 1)
            printf("Slot %d: %d\n", i, ht->table[i]);
        else
            printf("Slot %d: EMPTY\n", i);
    }
}

int main() {
    struct HashTable ht;
    initHashTable(&ht);
    insertOpenAddressing(&ht, 15);
    insertOpenAddressing(&ht, 25);
    insertOpenAddressing(&ht, 35);
    printOpenAddressing(&ht);
    printf("Found 25: %d\n", searchOpenAddressing(&ht, 25));
    return 0;
}