#include<stdio.h>
#include<stdlib.h>

// Threaded Binary Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
    int ltag, rtag; // 0 for child, 1 for thread
} Node;

Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->ltag = newNode->rtag = 1;
    return newNode;
}

Node* insert(Node* root, int key) {

    Node *ptr = root;
    Node *parent = NULL;

    while (ptr != NULL) {

        if (key == ptr->data) {
            printf("Duplicate not allowed\n");
            return root;
        }

        parent = ptr;

        if (key < ptr->data) {
            if (ptr->ltag == 0)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (ptr->rtag == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* temp = createNode(key);

    if (parent == NULL) {
        root = temp;
        temp->left = temp->right = NULL;
    }

    else if (key < parent->data) {
        temp->left = parent->left;
        temp->right = parent;

        parent->ltag = 0;
        parent->left = temp;
    }

    else {
        temp->left = parent;
        temp->right = parent->right;

        parent->rtag = 0;
        parent->right = temp;
    }

    return root;
}

/*
    Threaded Binary Tree - A binary tree where null pointers are replaced with pointers to the in-order predecessor or successor.

    

    ltag and rtag are used to indicate whether the left and right pointers are threads or actual child pointers.
*/