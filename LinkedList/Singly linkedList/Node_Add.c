#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void print_list(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertFirst(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertLast(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;   // ✅ FIXED

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPos(int val, int pos)
{
    if (pos == 1)
    {
        insertFirst(val);
        return;
    }

    Node *temp = head;

    // ✅ Bounds safety check
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()   // ✅ FIXED return type
{
    while (1)
    {
        int choice, val, pos;
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Print list\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertFirst(val);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertLast(val);
            break;

        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertAtPos(val, pos);
            break;

        case 4:
            print_list(head);
            printf("\n");
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
