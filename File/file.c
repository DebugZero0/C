#include<stdio.h>
void main(){
    FILE *ptr,*ptr2;
    char str[100]; 
    ptr = fopen ("Define.txt","r"); // open file in read mode
    while (fgets(str, sizeof(str), ptr) != NULL) { // read each line until EOF
        printf("%s", str); // print each line
    }
    printf("\n");
    fclose(ptr); // close the file after reading
    
    char str2[100];
    ptr2 = fopen ("Define.txt","a"); // open file in append mode
    printf("Enter a string to append to the file: \n");
    fgets(str2, sizeof(str2), stdin); // read a string from user
    fputs(str2, ptr2); // append the string to the file
    
}