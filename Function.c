#include<stdio.h>
void main(){
    int n;
    int func();// Declaration of the function
    printf("Enter the last term:\n");
    scanf("%d",&n);
    printf("Sum of First %d digits =\t%d",n,func(n));
}
int func(int n){ // If you dont declare the function in main then write this func before main
    int sum=0;
    for (int i = 1; i <= n; i++)
    {
        sum+=i;
    }
    return sum;
}