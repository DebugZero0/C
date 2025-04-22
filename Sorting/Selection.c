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
        int currEle=a[i];
        int idx=i-1;
        while(idx>=0 && a[idx]>currEle){
            a[idx+1]=a[idx];
            idx--;
        }
        a[idx+1]=currEle;
    }
    
    for (int i = 0; i < s; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}