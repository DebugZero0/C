#include<stdio.h>
#include<stdlib.h>

#define MAX 3

int front = 0, rear = -1;
int queue[MAX];

void enqueue(int ele){
    if(rear == MAX - 1){
        printf("Queue is full\n");
    }
    else{
        queue[++rear] = ele;
    }
}

int dequeue(){
    int ele;
    if(rear < front){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        ele = queue[front++];

        // Optional reset when queue becomes empty
        if(front > rear){
            front = 0;
            rear = -1;
        }

        return ele;
    }
}

int peek(){
    if(rear < front){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return queue[front];
    }
}

void display(){
    int i;
    if(rear < front){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements in the queue are: ");
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, ele;

    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;

            case 2:
                ele = dequeue();
                if(ele != -1){
                    printf("Dequeued element: %d\n", ele);
                }
                break;

            case 3:
                ele = peek();
                if(ele != -1){
                    printf("Front element: %d\n", ele);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
/*
    Limited to 3 elements and does not reuse space after dequeuing, which can lead to inefficient use of the queue. -> To fix this, we can implement a circular queue.

    For simple que front = 0 and rear = -1 
*/