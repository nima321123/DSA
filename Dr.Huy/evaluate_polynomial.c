#include <stdio.h>
#include <math.h>

int evaluate(int coefficients[], int N, int val){
    int result = 0;
    for(int i=0; i < N; i++){
        result += coefficients[i]*pow(val, i);
    }
    return result;
}

// print the polynomial
void print_result(int coefficients[], int N, int val){
    for(int i=0; i < N; i++){
        printf("%d(%d)^%d + ", coefficients[i], val, i);
    }
    printf("%d(%d)^%d = ", coefficients[N-1], val, N);
}


int main(){
    int coefficients[] = {2, 6, 5, 17, 1};
    int size = sizeof(coefficients)/sizeof(int) ;
    int val = 5;
    int result = evaluate(coefficients, size, val);
    print_result(coefficients, size, val);
    printf("%d", result);
    return 0;
}