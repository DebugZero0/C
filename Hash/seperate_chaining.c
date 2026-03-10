#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

// seperate chaining
typedef struct node{
    int data;
    struct node* next;
}Node;

// Node pointer array to represent the hash table
Node* hashTable[SIZE];

void insert(int value){
    int index = value % SIZE;
    
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(){
    for(int i = 0; i < SIZE; i++){
        Node* temp = hashTable[i];
        printf("Index %d: ", i);
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = NULL;
    }

    insert(10);
    insert(25);
    insert(30);
    insert(45);
    insert(60);
    insert(75);

    display();

    return 0;
}

/*
Output:
    Index 0: 10 -> 30 -> 60 -> NULL
    Index 1: NULL
    Index 2: NULL
    Index 3: NULL
    Index 4: NULL
    Index 5: 25 -> 45 -> 75 -> NULL
    Index 6: NULL
    Index 7: NULL
    Index 8: NULL
    Index 9: NULL

*/