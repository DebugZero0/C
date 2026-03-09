#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtEnd(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}
void deleteAtBegining(){
    if(head==NULL){
        printf("List is Empty");
        return;
    }
    Node *temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is Empty");
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}
void deleteAtPosition(){
    int pos;
    printf("Enter postion:");
    scanf("%d",&pos);
    if(pos==1){
        deleteAtBegining();
        return;
    }
    Node *temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Position out of bounds\n");
            return;
        }
    }
    if(temp->next==NULL){
        deleteAtEnd();
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);    
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int n;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &val);
        insertAtEnd(val);
    }
    int ch;
    while (1)
    {
        printf("-----Menu-----\n");
        printf("1.Delete At Begining\n2.Delete at End\n3.Delete At ANy Position\n4.Display\n5.Exist\nEnter Choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            deleteAtBegining();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            deleteAtPosition();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}