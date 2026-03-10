#include<stdio.h>
#define SIZE 15
int hashTable[SIZE];
int hashFunction(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;
    while(hashTable[index] != -1) {
        i++;
        index = (hashFunction(key) + i*hashFunction(i)) % SIZE; // Double hashing
    }
    hashTable[index] = key;
}
void display() {
    for(int i=0;i<SIZE;i++) {
        printf("%d : %d\n", i, hashTable[i]);
    }
}
int main() {
    for(int i=0;i<SIZE;i++)
        hashTable[i] = -1;

    insert(2); // insert 2 at index 2
    insert(2); // collision with 2, will be placed at index (2 + 1*hashFunction(1)) % SIZE = 3
    insert(2); // collision chain, will be placed at index (2 + 2*hashFunction(2)) % SIZE = 6
    insert(2); // collision chain, will be placed at index (2 + 3*hashFunction(3)) % SIZE = 11

    display();
    return 0;
}