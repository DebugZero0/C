 #include<stdio.h>
void main(){
    int a=10;

    int* x=&a; // int*--> storing the address of a
    *x=7; // updating the value of the address stored in x 
    printf("%d",a);
}