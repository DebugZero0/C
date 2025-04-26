#include<stdio.h>
#include<string.h>
void main(){
    char b[]="Hello World"; // String initialization
    printf("%s\n",b); // Output string


    char str[20];
    printf("Enter a string: ");
    scanf("%s",str); // Input string
    printf("String is: %s\n",str); // Output string

    char c[20];
    printf("Enter a string: ");
    scanf("%s",c); // Input string
    printf("String is: %s\n",c); // Output string

    
    int x=strcmp(str,c); // Compare two strings
    if(x==0){ // If strings are equal
        printf("Strings are equal\n"); // Output
    }
    else { // If strings are not equal
        printf("Strings are not equal\n"); // Output
    }
}