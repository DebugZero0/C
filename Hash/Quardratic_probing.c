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
        index = (hashFunction(key) + i*i) % SIZE; // Quadratic probing
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
    insert(2); // collision with 2, will be placed at index (2 + 1^2) % SIZE = 3
    insert(2); // collision chain, will be placed at index (2 + 2^2) % SIZE = 6
    insert(2); // collision chain, will be placed at index (2 + 3^2) % SIZE = 11

    display();
    return 0;
}
/*
Output:
    0 : -1
    1 : -1
    2 : 2
    3 : 2
    4 : -1
    5 : -1
    6 : 2
    7 : -1
    8 : -1
    9 : -1
    10 : -1
    11 : 2
    12 : -1
    13 : -1
    14 : -1
*/