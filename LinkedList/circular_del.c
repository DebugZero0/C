#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a circular linked list
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
    head->next = head;  // circular
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;  // last node points to head
        temp->next = newNode;
        temp = newNode;
    }
}

// Display the circular linked list
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

// Delete node at beginning
void deleteAtBeginning() {
    Node *temp, *last;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {  // only one node
        free(head);
        head = NULL;
    } else {
        last = head;
        while (last->next != head)
            last = last->next;

        temp = head;
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Node deleted from beginning.\n");
}

// Delete node at end
void deleteAtEnd() {
    Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {  // only one node
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Node deleted from end.\n");
}

// Delete node at specific position
void deleteAtPosition(int pos) {
    Node *temp, *prev;
    int count = 1;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    temp = head;
    do {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head && count < pos);

    if (temp == head) {
        printf("Invalid position.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
    }
}

// Menu-driven program
int main() {
    int n, choice, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display List\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayList();
            break;
        case 2:
            deleteAtBeginning();
            break;
        case 3:
            deleteAtEnd();
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
