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
// Traversal
void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[MAX_SIZE];
    return 0;
}