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

    for (int i = 0; i < s-1; i++)
    {
        for (int j = 0; j < s-1-i; j++)
        {
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    }
    
    for (int i = 0; i < s; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}