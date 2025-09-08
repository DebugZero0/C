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

void print_List(Node *head){
    Node *ptr = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void main()
{
    int n, x;
    printf("Enter Number of nodes you want\n");
    scanf("%d", &n);
    Node *head = NULL;
    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d : ", i + 1);
        scanf("%d", &x);
        if (head == NULL)
        {
            head = create(x);
            temp = head;
        }
        else
        {
            temp->next = create(x);
            temp = temp->next;
        }
    }
    temp->next = head; // Making the linked list circular

    // Printing the circular linked list
    print_List(head);
     
}
