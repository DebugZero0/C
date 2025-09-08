#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Create list
void createList(int n) {
    Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return;
    }

    head = (Node*)malloc(sizeof(Node));
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }
}

// Display list
void displayList() {
    Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    Node *newNode, *last;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        last = head;
        while (last->next != head)
            last = last->next;
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertAtEnd(int data) {
    Node *newNode, *last;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        last = head;
        while (last->next != head)
            last = last->next;
        last->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted at end.\n");
}

// Insert at position
void insertAtPosition(int data, int pos) {
    Node *newNode, *temp;
    int i;

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i != pos - 1) {
        printf("Position out of range.\n");
        return;
    }

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

// Menu-driven
int main() {
    int n, choice, data, pos;

    printf("Enter number of nodes to create initially: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayList();
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtPosition(data, pos);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
