#include<stdio.h>
void main(){
    printf("Enter size of Array\n");
    int s,i;
    scanf("%d",&s);
    int a[s];
    printf("Enter the %d numbers\n",s);
    for (i = 0; i < s; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < s; i++)
    {
        printf("%d\t",a[i]);
    }
    
}