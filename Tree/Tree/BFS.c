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
void BFS(Node* root)
{
    if(root == NULL)
        return;

    Node* queue[100]; // Simple queue implementation
    int front = 0, rear = 0;

    queue[rear++] = root; // Enqueue the root node

    while(front < rear)
    {
        Node* currentNode = queue[front++]; // Dequeue a node
        printf("%d ", currentNode->data); // Process the current node

        if(currentNode->left != NULL)
            queue[rear++] = currentNode->left; // Enqueue left child
        if(currentNode->right != NULL)
            queue[rear++] = currentNode->right; // Enqueue right child
    }
}
int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Breadth First Search (BFS) Traversal: ");
    BFS(root);
    printf("\n");

    return 0;
}