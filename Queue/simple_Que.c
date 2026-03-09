#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
} que; 

que q; 

void create(int size)
{
    q.size=size;
    q.front=q.rear=-1; 
    q.Q=malloc(q.size*sizeof(int));
}
void enqueue(int x)
{
    if((q.rear+1)%q.size==q.front)
        printf("Queue is Full\n");
    else
    {
        q.rear=(q.rear+1)%q.size;
        q.Q[q.rear]=x;
    }
}
int dequeue()
{
    int x=-1;
    if(q.front==q.rear)
        printf("Queue is Empty\n");
    else
    {
        q.front=(q.front+1)%q.size;
        x=q.Q[q.front];
    }
    return x;
}
void display()
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}
int main()
{
    // create a queue of size 3 and perform enqueue and dequeue operations
    create(3);

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("Dequeue element is %d\n",dequeue());
    display();
    return 0;
}
// This implementation uses a circular queue to efficiently utilize space after dequeuing elements. 
// Limitations: It overwrites the front element when the queue is full, so it does not handle overflow properly.
