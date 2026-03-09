#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *head=NULL;

int isEmpty();

void enque(int ele){
    Node *newNode=malloc(sizeof(Node));
    newNode->data=ele;
    newNode->next=NULL;
    if(head==NULL){
       head=newNode; 
       printf("%d enqueued \n",newNode->data);
       return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    printf("%d enqueued \n",newNode->data);
}
void deque(){
    if(isEmpty()){
        return;
    }
    Node *temp=head;
    head=head->next;
    printf("%d is dequeued\n",temp->data);
    free(temp);
}
void print(){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int isEmpty(){
    return head==NULL;
}
void peek(){
    if(isEmpty()){
        return;
    }
    printf("Peek element is %d\n",head->data);
}


void main(){
    // Menu driven program
    int choice,ele;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Print\n5. IsEmpty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d",&ele);
                enque(ele);
                break;
            case 2:
                deque();
                break;
            case 3:
                peek();
                break;
            case 4:
                print();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}