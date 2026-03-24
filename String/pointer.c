#include<stdio.h>
#include<string.h>
void main(){
    char str[]="Hello World!"; 
    char *p = str; // pointer to the first character of the string
    
    while(*p != '\0'){ 
        printf("%c", *p); 
        p++; 
    }
}

