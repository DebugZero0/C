#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void print_list(Node* ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL, *temp = NULL;

    printf("Enter no of nodes you want: ");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (head == NULL) {
            head = create(i);
            temp = head;
        } else {
            temp->next = create(i);
            temp = temp->next;
        }
    }

    printf("Initial list: ");
    print_list(head);

    printf("\n1. Delete at beginning\n2. Delete at end\n3. Delete at any position\n");
    int choice, pos;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: { // delete at beginning
            if (head != NULL) {
                Node* del = head; 
                head = head->next;
                free(del);
            }
            break;
        }
        case 2: { // delete at end
            if (head == NULL) break;   // list empty
            if (head->next == NULL) {  // only one node
                free(head);
                head = NULL;
            } else {
                temp = head;
                while (temp->next->next != NULL) {
                    temp = temp->next;
                }
                free(temp->next);
                temp->next = NULL;
            }
            break;
        }
        case 3: { // delete at given position
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            if (pos <= 0) {
                printf("Invalid position\n");
                break;
            }

            if (pos == 1 && head != NULL) {
                Node* del = head;
                head = head->next;
                free(del);
            } else {
                temp = head;
                for (int i = 1; i < pos - 1 && temp != NULL; i++) {
                    temp = temp->next;
                }
                if (temp == NULL || temp->next == NULL) {
                    printf("Position out of bounds\n");
                } else {
                    Node* del = temp->next;
                    temp->next = del->next;
                    free(del);
                }
            }
            break;
        }
        default:
            printf("Invalid choice\n");
    }

    printf("Updated list: ");
    print_list(head);

    return 0;
}
