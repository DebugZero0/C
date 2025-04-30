#include<stdio.h>
#define PI 3.14159
#define Area(r) (PI*(r)*(r))
#define SQUARE(x) ((x)*(x))
// Compare this snippet from lib.c:
void main(){
    printf("PI: %.5f\n",PI);
    printf("Enter a radius: ");
    int r;
    scanf("%d",&r);
    printf("Area of circle: %.2f\n",Area(r));
    printf("Square of %d: %d\n",r,SQUARE(r));
}