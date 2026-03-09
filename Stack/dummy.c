#include<stdio.h>

void main(){
    int size=0;
    int arr[]={1,2,3,4,5};
    while(size<5){
        printf("%d ",arr[size++]);
    }
    printf("\n%d",size);
}