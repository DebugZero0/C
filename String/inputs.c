#include<stdio.h>
#include<string.h>
void main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Use fgets to read a sentence
    printf("The string is: %s", str);

    char srt2[50];
    printf("Enter another string: ");
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != sizeof(srt2)-1) { // Read until newline or buffer limit
        srt2[i++] = ch; // Store each character in the array
    }
    srt2[i] = '\0'; // Null-terminate the string
    printf("The second string is: %s", srt2);

}