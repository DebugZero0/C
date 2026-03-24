#include<stdio.h>
#include<string.h>
void main(){
    char str[10];
    printf("Enter a string: ");
    gets(str); // scanf("%[^\n]", str); 

    // int k = 0,size=0;
    // while(str[k]!= '\0'){ //length of string
    //     size++;
    //     k++;
    // }

    int size = strlen(str); 

    for(int i=0; i<=size/2;i++){ //reverse string
        char temp = str[i];
        str[i] = str[size-i-1];
        str[size-i-1] = temp;
    }
    puts("The reverse string is: "); 
    puts(str); //output string
}