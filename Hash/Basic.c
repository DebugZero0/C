#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    hashTable[index] = key;
}

void display() {
    for(int i=0;i<SIZE;i++) {
        printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {

    // Initialize hash table with -1 to indicate empty slots
    for(int i=0;i<SIZE;i++)
        hashTable[i] = -1;

    insert(12);
    insert(25);
    insert(37);

    display();
    return 0;
}
