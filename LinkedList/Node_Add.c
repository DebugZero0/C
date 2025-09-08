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
    // Switch case to enter node at any position , first , last
    printf("\n1. Add at beginning\n2. Add at end\n3. Add at any position\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int val, pos;
    switch (choice)
    {
    case 1:
        printf("Enter value to add at beginning: ");
        scanf("%d", &val);
        Node *newNode = create(val);
        newNode->next = head;
        head = newNode;
        print_list(head);
        break;
    case 2:
        printf("Enter value to add at end: ");
        scanf("%d", &val);
        Node *newNode2 = create(val);
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode2;
        print_list(head);
        break;
    case 3:
        printf("Enter position to add node: ");
        scanf("%d", &pos);
        printf("Enter value to add at position %d: ", pos);
        scanf("%d", &val);
        Node *newNode3 = create(val);
        if (pos == 1)
        {
            newNode3->next = head;
            head = newNode3;
        }
        else
        {
            temp = head;
            for (int i = 1; i < pos - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Position out of bounds\n");
                free(newNode3);
            }
            else
            {
                newNode3->next = temp->next;
                temp->next = newNode3;
            }
        }
        print_list(head);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    
}
