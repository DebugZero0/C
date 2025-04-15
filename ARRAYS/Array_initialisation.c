#include<stdio.h>
void main(){
    int arr[10]; // initialisation , size is not optional
    int brr[]={1,2,3,4,5}; // initialisation, size is optional 
    int x=sizeof(brr); // int data type occupies 4byte 4*5=20 is size of brr
    int y=sizeof(brr[0]);
    printf("Size of brr in bytes\t:%d\nSize of 1st elements int bytes\t:%d\n",x,y);
    printf("Length of brr\t:%d",x/y);
}