#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *head = NULL;

// push
void push(int new_data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed. Cannot push %d\n", new_data);
        return;
    }
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    printf("Pushed %d to linked list\n", new_data);
}
// pop
int pop() {
    if (head == NULL) {
        printf("Linked list is empty. Cannot pop\n");
        return -1; // Indicating empty list
    }
    Node* temp = head;
    int poppedData = temp->data;
    head = head->next;
    free(temp);
    printf("Popped %d from linked list\n", poppedData);
    return poppedData;
}
// peek
void peek() {
    if (head == NULL) {
        printf("Linked list is empty. Cannot peek\n");
        return;
    }
    printf("The Top element is %d\n", head->data);
}
// isEmpty
int isEmpty() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return 1;
    }
    printf("Linked list is not empty\n");
    return 0;
}
// display
void display(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    printf("Linked list elements: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(void) {
    for (int i = 1; i <= 5; i++) {
        push(i * 10);
    }
    display(head);
    pop();
    pop();
    peek();
    isEmpty();
    pop();
    isEmpty();
    display(head);
    while (head != NULL) {
        pop();
    }
    return 0;
}