#include<stdio.h>
#define MAX_SIZE 10
int size=0;

void insertAtFirst(int arr[],int ele){
    int x;
    if(size >= MAX_SIZE){
        printf("Array Full");
        return;
    }
    for(x=size; x>0; x--){
        arr[x] = arr[x-1];
    }
    arr[0] = ele;
    size++;
}

void insertAtPosition(int arr[], int ele, int pos){
    int x;
    if(size >= MAX_SIZE){
        printf("Array Full");
        return;
    }
    if(pos<0 || pos>size){
        printf("Invalid Position");
        return;
    }
    for(x=size; x>pos; x--){
        arr[x] = arr[x-1];
    }
    arr[pos] = ele;
    size++;
}

void insertAtLast(int arr[],int ele){
    if(size>=MAX_SIZE){
        printf("Array Full");
        return;
    }
    arr[size++] = ele;
}
void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void main(){
    int arr[MAX_SIZE];
    int ele;
    for(int p=1; p<=5; p++){
        insertAtFirst(arr,p);
    }
    traverse(arr,size);
    for(int q=6; q<=10; q++){
        insertAtLast(arr,q);
    }
    traverse(arr,size);
}

