#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    int x;

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;

    printf("Enter left child of %d (or -1 to stop): ", data);
    scanf("%d", &x);
    if(x == -1){
        newNode->left = NULL;
    }
    else{
        newNode->left = createNode(x);
    }

    printf("Enter right child of %d (or -1 to stop): ", data);
    scanf("%d", &x);
    if(x == -1){
        newNode->right = NULL;
    }
    else{
        newNode->right = createNode(x);
    }

    return newNode;
}

void display(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

int main(){   // ✅ FIXED
    Node *root;
    int rootData;

    printf("Enter the value of root node: ");
    scanf("%d", &rootData);

    root = createNode(rootData);

    printf("Binary Tree created successfully.\n");
    display(root);

    return 0;   // ✅ FIXED
}

/*  
    Binary Tree - Each node has at most two children.

    Left pointer and right pointer is required.
    Taking inputs from user to create the tree Nodes.
    when user enters -1, it means that there is no child for that node and we can stop taking input for that node's child.
    Normal recursive approach to create the tree.
*/