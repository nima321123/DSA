//Write a program in C to calculate the sum of numbers from 1 to n using recursion
#include <stdio.h>

int my_sum(int n){
    if (n <= 0) return 0;
    return n + my_sum(n-1);
}

int main(){
    int n = 6;
    int sum = my_sum(n);
    printf("%d", sum);
    return 0;
}