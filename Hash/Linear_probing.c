#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    // Linear probing
    while(hashTable[index]!=-1){
        index = (index + 1) % SIZE; 
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

    insert(12);
    insert(22); // collision with 12
    insert(32); // collision chain

    display();
    return 0;
}
/*
Output:
    0 : -1
    1 : -1
    2 : 12
    3 : 22
    4 : 32
    5 : -1
    6 : -1
    7 : -1
    8 : -1
    9 : -1

*/