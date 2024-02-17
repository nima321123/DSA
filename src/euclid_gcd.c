

#include <stdio.h>
#include <stdlib.h>

int gcd_cal(int a, int b){
	int quotient; 
	int rmd; 
	int temp;
	while (b != 0){
		
		rmd = a % b;
		temp = b;
		
		a = b;
		b = rmd;
	}
	return temp;
}
		
		
		
int main()
{
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the first number: ");
    scanf("%d", &num2);
    
    int result = gcd_cal(num1, num2);
    printf("\n%d", result);
    return 0;
}
