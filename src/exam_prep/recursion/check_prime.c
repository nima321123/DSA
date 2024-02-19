// Check prime using recursion


#include <stdio.h>
#include <stdlib.h>
int divisor;

void check_prime(int n, int divisor, int* flag){
    if (divisor == 1) return;
    if (n % divisor == 0) {
        printf("Divisible by %d", divisor);
        *flag = 0;
        return;
    }
    
    
    check_prime(n, divisor-1, flag);
}

int main()
{
    int* flag = (int*)malloc(sizeof(int));
    *flag = 1;

    
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    divisor = num/2;
    if (num == 1 || num == 2 || num == 3) printf("\nPrime number.");
    else {
        check_prime(num, divisor, flag);
        if (*flag == 1) printf("\nPrime number.");
        else if (*flag == 0) printf("\nNot prime.");}
    free(flag);

    return 0;
}
