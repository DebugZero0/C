#include <stdio.h>

#define MAX 5

int pq[MAX];
int size = 0;

// Insert element
void enqueue(int value) {
    if (size == MAX) {
        printf("Priority Queue is Full!\n");
        return;
    }

    pq[size++] = value;
    printf("%d inserted\n", value);
}

// Delete highest priority element
void dequeue() {
    if (size == 0) {
        printf("Priority Queue is Empty!\n");
        return;
    }

    int maxIndex = 0;

    // Find highest priority element (largest number) and its index
    for (int i = 1; i < size; i++) { // why i=1? because we are comparing with maxIndex which is initialized to 0
        if (pq[i] > pq[maxIndex]) {
            maxIndex = i;
        }
    }
    printf("%d removed\n", pq[maxIndex]);

    // Shift elements left
    for (int i = maxIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}
// Peek highest priority element
int peek() {
    if (size == 0) {
        printf("Priority Queue is Empty!\n");
        return -1;
    }

    int maxIndex = 0;

    // Find highest priority element (largest number) and its index
    for (int i = 1; i < size; i++) {
        if (pq[i] > pq[maxIndex]) {
            maxIndex = i;
        }
    }

    return pq[maxIndex];
}

// Display queue
void display() {
    if (size == 0) {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(40);
    enqueue(30);
    enqueue(50);
    enqueue(20);

    display();
    printf("Highest priority element is %d\n", peek());


    dequeue();
    display();

    printf("Highest priority element is %d\n", peek());

    return 0;
}
// No need to maintain rear and front pointers as we are using a simple array to store elements. The highest priority element is determined by its value,we get the index of the highest priority element and we shift elements after deletion to maintain the order.