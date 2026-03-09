#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void print_list(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    Node *head = NULL;
    Node *temp = head;

    printf("Enter no of nodes you want\n");
    int n;
    scanf("%d", &n);
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
    print_list(head);
}
