#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }

    if (front == -1) // first element
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted\n", value);
}

// Remove element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("%d removed\n", queue[front]);

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    for(int i = front; ; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}

/*
    circular queue handles space more efficiently than a linear queue by reusing the empty spaces created by dequeued elements.
    This is done by using the modulo operator to wrap around the rear and front indices when they reach the end of the array.
    Front = -1 and Rear = -1 indicates an empty queue. When the first element is enqueued, both front and rear are set to 0.

    Enqueue : 
        if((rear + 1) % SIZE == front) {
            printf("Queue is Full!\n");
            return;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    Dequeue :
        if(front == rear) front = rear = -1; 
        else front = (front + 1) % SIZE;
*/