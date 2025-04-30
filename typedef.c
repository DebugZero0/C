#include<stdio.h>
// typedef is declared in global scope and can be used in any function
typedef int integer; // typedef is used to create an alias for a data type

typedef struct book{ // typedef is used to create an alias for a structure type
    char title[50];
    char author[50];
    int pages;
}pw; //new name for struct book

pw a; // pw is an alias for struct book
pw b;
pw c;


void main(){
    integer a=10; 
    integer b=20;
    integer c=a+b; // using the alias integer instead of int
    printf("Sum of a and b is %d\n",c); // prints 30

    typedef int* int_pointer; // We cannot initialize pointers in same line so typedef is used too resolve this issue
    int x=10;
    int y=20;
    int_pointer p1=&x, p2=&y; // intitialized in same line
    printf("Address of x :\t%p\nAddress of y:\t%p",p1,p2);// p1 is a pointer to an integer
}
