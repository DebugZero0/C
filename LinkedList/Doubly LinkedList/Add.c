#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node *head=NULL;

void insertAtBegining(int val){
    Node *newNode=malloc(sizeof(Node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(int val){
    Node *newNode=malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertAtPosition(int val,int pos){
    Node *newNode=malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(pos==1){
        insertAtBegining(val);
        return;
    }
    Node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Position out of bounds\n");
            return;
        }
    }
    if(temp->next==NULL){
        insertAtEnd(val);
        return;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void display(){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    insertAtBegining(5);
    display();
    insertAtPosition(15,3);
    display();
    return 0;
}