#include<stdio.h>
int main(){
    printf("Enter Size of arr\n");
    int s;
    scanf("%d",&s);
    int a[s];
    printf("Enter the %d numbers\n",s);
    for (int i = 0; i < s; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i < s; i++)  
    {
        int j=i;
        while (j>=1 && a[j]<a[j-1])
        { 
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
    for (int i = 0; i < s; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}