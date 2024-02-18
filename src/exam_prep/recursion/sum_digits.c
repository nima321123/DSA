// sum of digits using recursion  

#include <stdio.h>
void sum_digit(int n, int* sum){
    if (n == 0) return;
    int digit = n % 10;
    *sum = *sum + digit;
    sum_digit((n-digit)/10, sum);
}
int main()
{   
    int num;
    int sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    sum_digit(num, &sum);
    printf("Sum of digits: %d", sum);
    return 0;
}
