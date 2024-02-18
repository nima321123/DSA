#include <stdio.h>


void print_fibo(int p2, int p1, int term, int i){
    
    if (i == term) return;
    int num = p2 + p1;
    printf("%d ", num);

    //recursive call
    print_fibo(p1, num, term, i+1); //elegant
}

int main(){
    int term;
    printf("Enter a number: ");
    scanf("%d", &term);
    if (term > 0) printf("0 ");
    if (term > 1) printf("1 ");
    print_fibo(0, 1, term - 2, 0);
    return 0;

}