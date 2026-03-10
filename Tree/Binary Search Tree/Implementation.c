#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void display(Node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int search(Node *root, int val)
{
    if (root == NULL)
    {
        return 0; // Not found
    }
    if (root->data == val)
    {
        return 1; // Found
    }
    else if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val); 
    }
    else
    {
        // Node with only one child or no child then replace node with its child
        if (root->left == NULL) 
        {
            Node *temp = root->right;
            free(root);
            return temp; // Replacing node with its right child
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp; // Replacing node with its left child
        }
        // Node with two children: Get the inorder successor
        Node *temp = root->right;
        while (temp->left != NULL) 
        {
            temp = temp->left;
        }
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor , this temp->data is already copied to root->data that node is to be deleted
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void main()
{
    Node *root = NULL;
    int n, x;

    printf("Enter no of nodes you want: ");
    scanf("%d", &n);

    printf("Enter %d nodes:\n", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder traversal of the BST: ");
    display(root);
    printf("\n");

    int ch;
    printf("1.Delete a value\n2.Search a value\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter a value to delete: ");
        int deleteVal;
        scanf("%d", &deleteVal);
        root = deleteNode(root, deleteVal);
        display(root);
        break;
    case 2:
        printf("Enter a value to search: ");
        int searchVal2;
        scanf("%d", &searchVal2);
        search(root, searchVal2) ? printf("Value found in the BST.\n") : printf("Value not found in the BST.\n");
        break;

    default:
        break;
    }
}
/*
    why dont we direcly call deleteNode(root->right, val) without assigning it to root->right because we need to update the right child of the current node after deletion, if we just call deleteNode(root->right, val) without assignment, we won't be able to update the right child of the current node after deletion, which can lead to incorrect tree structure and potential memory leaks. By assigning the result of deleteNode(root->right, val) back to root->right, we ensure that the tree structure is correctly maintained after deletion.

    why Inorder successor is used in case of deleting a node with two children? Inorder successor is used in case of deleting a node with two children because it helps maintain the properties of the binary search tree (BST). The inorder successor of a node is the smallest node in its right subtree, which means it will be greater than all nodes in the left subtree and less than all nodes in the right subtree. By replacing the value of the node to be deleted with its inorder successor, we can ensure that the BST properties are preserved after deletion. This allows us to maintain the correct ordering of the nodes in the tree while removing a node with two children.

*/