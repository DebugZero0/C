#include<stdio.h>
#include<limits.h> 
void main(){
    int max=INT_MIN,smax;
    int arr[5]={1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        if(max<arr[i]){
            smax=max;// is previous max
            max=arr[i]; // New max
        }
    }
    printf("%d",smax);
}