//Write a program in C to print the first 50 natural numbers using recursion.

#include <stdio.h>

void print_natural(int n){
    if (n <= 0) return; //Base case
    print_natural((n-1));
    printf("%d ", n);
}

int main(){
    printf("The natural numbers are: ");
    print_natural(60);
}
