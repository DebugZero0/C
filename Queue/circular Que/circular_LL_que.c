#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* head=NULL;

void enqueue(){
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);

    Node *newNode=malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    else{
        Node *temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;        
    }
}

void dequeue(){
    if(head==NULL){
        printf("Queue is empty\n");
        return;
    }
    else if(head->next==head){
        printf("%d removed\n",head->data);
        free(head);
        head=NULL;
    }
    else{
        Node *temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        printf("%d removed\n",head->data);
        Node *toDelete=head;
        head=head->next;
        temp->next=head;
        free(toDelete);
    }
}

void display(){
    Node *temp=head;
    if(temp==NULL){
        printf("NULL\n");
        return;
    }
    else{
        while (temp->next!=head)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void main(){
    int choice;
    printf("Circular Linked List Queue\n");
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
