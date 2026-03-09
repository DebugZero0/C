#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
int size = 0;

// push function to add an element to the array
void push(int arr[], int element) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot push %d\n", element);
        return;
    }
    arr[size++] = element;
    printf("Pushed %d to array\n", element);
}

// pop function to remove the last element from the array
int pop(int arr[]) {
    if (size <= 0) {
        printf("Array is empty. Cannot pop\n");
        return -1; // Indicating empty array
    }
    int poppedElement = arr[--size];
    printf("Popped %d from array\n", poppedElement);
    return poppedElement;
}

// display function to print the elements of the array
void display(int arr[]) {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// peek function to view the last element without removing it
void peek(int arr[]){
    printf("The Top element is %d\n",arr[size-1]);
}

// isEmpty function to check if the array is empty
void isEmpty() {
    size == 0 ? printf("Array is empty\n") : printf("Array is not empty\n");
}

void main(){
    int arr[MAX_SIZE];
    for(int i=1; i<=5; i++){
        push(arr, i*10);
    }
    display(arr);
    pop(arr);
    pop(arr);
    pop(arr);
    pop(arr);
    display(arr);
    peek(arr);
    isEmpty();
}

/*
    Size is maintained as a global variable to keep track of the number of elements in the array.
    After pushing an element, size is incremented and after popping an element, size is decremented.
    arr[size++] to add element and arr[--size] to remove element.


    why arr[--size] not arr[size--]?
    arr[--size] is used to first decrement the size and then access the element at the new size index, which is the last element in the array.
*/