// Find LCM using recursion

#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b, int* smaller_num){
    
    if (a % *smaller_num == 0 && b % *smaller_num == 0){
        return *smaller_num;
    }
    else{
        *smaller_num = *smaller_num - 1;
        GCD(a, b, smaller_num);
    }
}

int main(){
    int num1, num2;
    int my_smaller_num;
    int* ptr = &my_smaller_num;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    if (num1 < num2) my_smaller_num = num1;
    else my_smaller_num = num2;
    GCD(num1, num2, ptr);
    printf("LCM = %d", (num1*num2)/my_smaller_num );
    
    return 0;
}