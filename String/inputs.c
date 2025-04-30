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
    printf("The second string is: %s\n", srt2); 
    printf("Type cast of null character is: %d\n", (int)ch); // Output null character

    char str3[50];
    printf("Enter a string: ");
    scanf("%s", str3); // Use scanf to read a word 
    printf("The string is: %s\n", str3);

    char str4[50];
    printf("Enter a string: ");
    scanf("%[^\n]", str4); // Use scanf to read a line until newline
    printf("The string is: %s", str4); // Output string
}