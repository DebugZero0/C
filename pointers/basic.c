#include<stdio.h>
void main(){
    int age=21;
    printf("Age= %d\n",age);
    // '&' denotes address
    int *p=&age; 
    // To store address '*' used before variable
    printf("Address= %p\n",p);
    printf("Address= %p\n",&age);
    printf("Value of that Address= %d\n",*p);
    printf("Address of *p= %p\n",*p);
    printf("value of *p= %d\n",p); // Just gives a random value as no value is stored in the address of *p
    printf("%d",&age);// p=&age
}