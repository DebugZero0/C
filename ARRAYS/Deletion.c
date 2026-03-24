#include<stdio.h>
#define MAX_SIZE 10
int size=0;

// Delete at last
void deleteAtlast(int arr[]){
    if(size <= 0){
        printf("Empty array");
        return;
    }
    size--;
}
// Delete at first
void deleteAtFirst(int arr[]){
    if(size <= 0){
        printf("Empty array");
        return;
    }
    for(int i=0; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}
// Delete at any position
void deleteAtPosition(int arr[], int pos){
    if(size <=0){
        printf("Empty array");
        return;
    }
    if(pos < 0 || pos >= size){
        printf("Invalid position");
        return;
    }
    for(int i=pos-1; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

// Traversal
void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={5, 10, 15, 20, 25};
    size = 5;
    printf("Original array: ");
    traverse(arr, size);
    deleteAtPosition(arr, 2);
    printf("Array after deletion: ");
    traverse(arr, size);
    return 0;
}