#include<stdio.h>
#define MAX_SIZE 10

void main(){
    // int a[MAX_SIZE][MAX_SIZE]={{1,2,3},
    //                            {4,5,6},
    //                            {7,8,9}};

    // int b[MAX_SIZE][MAX_SIZE]={{9,8,7},
    //                            {6,5,4},
    //                            {3,2,1}};
    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int c[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of first matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &b[i][j]);
        }
    }
    // Matrix multiplication
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            c[i][j] = 0;
            for(int k=0; k<3; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // Print the result
    printf("Resultant matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }


}