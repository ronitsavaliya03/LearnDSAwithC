#include<stdio.h>
#define PI 3.1416

int main(){
    float radius;

    printf("Enter the radius: ");
    scanf("%f", &radius);

    printf("Area of Cicle: %.2f", PI*radius*radius);

    return 0;
}