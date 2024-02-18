#include <stdio.h>
#define PI 3.14

int main(){
    double r = 2.50;
    int a = 5, b = 3.5;
    char* text[50];
    
    printf("area = %.3lf", PI*r*r);
    
    sprintf(text, "Integer: %d; Double: %lf\n", a, b);
    printf("\n%s", text);
    
}