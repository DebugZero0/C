#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void DFS(Node* root)
{
    if(root == NULL)
        return;
    
    printf("%d ", root->data); // Process the current node
    DFS(root->left); // Traverse left subtree
    DFS(root->right); // Traverse right subtree
}

int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Depth First Search (DFS) Traversal: ");
    DFS(root);
    printf("\n");

    return 0;
}