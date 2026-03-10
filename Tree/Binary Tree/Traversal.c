#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void displayPreorder(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    displayPreorder(root->left);
    displayPreorder(root->right);
}
void displayInorder(Node* root){
    if(root == NULL){
        return;
    }
    displayInorder(root->left);
    printf("%d ", root->data);
    displayInorder(root->right);
}
void displayPostorder(Node* root){
    if(root == NULL){
        return;
    }
    displayPostorder(root->left);
    displayPostorder(root->right);
    printf("%d ", root->data);
}

int main(){
        Node *a, *b, *c, *d, *e, *f, *g;
        b = malloc(sizeof(Node));
        a = malloc(sizeof(Node));
        c = malloc(sizeof(Node));
        d = malloc(sizeof(Node));
        e = malloc(sizeof(Node));
        f = malloc(sizeof(Node));
        g = malloc(sizeof(Node));
        // conecting maunally
        a->data = 1;
        b->data = 2;
        c->data = 3;
        d->data = 4;
        e->data = 5;
        f->data = 6;
        g->data = 7;

        a->left = b;
        a->right = c;
        b->left = d;
        b->right = e;
        c->left = f;
        c->right = g;

        d->left = NULL;
        d->right = NULL;
        e->left = NULL;
        e->right = NULL;
        f->left = NULL;
        f->right = NULL;
        g->left = NULL;
        g->right = NULL;

        Node *root = a;

        printf("Preorder Traversal: ");
        displayPreorder(root);

        printf("\nInorder Traversal: ");
        displayInorder(root);

        printf("\nPostorder Traversal: ");
        displayPostorder(root);

        return 0;
}