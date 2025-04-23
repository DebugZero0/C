#include<stdio.h>
#include<stdlib.h>
void main(){
    int* ptr=(int*)malloc(5*sizeof(int));
    int* p=ptr;
    printf("Enter 5 Numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&(*ptr));
        ptr++;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",*p);
        p++;
    }
    
    
}