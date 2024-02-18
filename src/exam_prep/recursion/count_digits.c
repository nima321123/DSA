#include <stdio.h>

int count_digit(int num, int* count){
    if (num == 0) return *count;
    else *count = *count + 1;
    count_digit(num/10, count);
}

int main(){
    int num;
    int count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num == 0) printf("Number of digits: 1");
    else {
        count_digit(num, &count);
        printf("Number of digits: %d", count);
        }
    return 0;
}