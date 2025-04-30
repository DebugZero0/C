#include<stdio.h>
#include<stdlib.h>
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    // Allocate memory for n integers
    int *ptr=(int*)malloc(n*sizeof(int));
    int *p=ptr;
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&(*ptr));
        ptr++;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",*p);
        p++;
    }
}