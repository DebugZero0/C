#include<stdio.h>
void swap(int* x,int* y ){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    return;
}
void main(){
    int a=10,b=5;
    printf("Value of a=\t%d\nValue of b=\t%d \n",a,b);
    swap(&a,&b);
    printf("Value of a=\t%d\nValue of b=\t%d",a,b);
}