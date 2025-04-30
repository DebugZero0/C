#include<stdio.h>
#include<string.h>
void main(){
    char b[]="Hello World"; // String initialization
    printf("%s\n",b); // Output string
    printf("%d\n\n",sizeof(b));// Null charecter is included in the size of string

    char str[20];
    printf("Enter a string: ");
    scanf("%s",str); // Input string
    printf("String is: %s\n",str); // Output string

    char c[20];
    printf("Enter a string: ");
    scanf("%s",c); // Input string
    printf("String is: %s\n",c); // Output string

    char ch='\0';
    int x=(int)ch;
    printf("Null character is: %d\n",x); // Output null character
}