#include<stdio.h>
#define N 10

void print(int arr[N][N]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int arr[N][N]={{1,2,3},{4,5,6},{7,8,9}};
    printf("Original matrix:\n");
    print(arr);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i>j){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
    printf("Transposed matrix:\n");
    print(arr);
}