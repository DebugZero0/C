#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int val)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void print_List(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void reverse(Node *head)
{
    Node *a = NULL, *b = head, *c = NULL;
    while (b != NULL)
    {
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    head = a;
    print_List(head);
}

void main()
{
    int n;
    printf("Enter no of nodes you want: ");
    scanf("%d", &n);
    Node *head = NULL;
    Node *temp = head;
    for (int i = 1; i <= n; i++)
    {
        if (head == NULL)
        {
            head = create(i);
            temp = head;
        }
        else
        {
            temp->next = create(i);
            temp = temp->next;
        }
    }
    printf("The list are: ");
    print_List(head);
    printf("\nReverse list are: ");
    reverse(head);
}