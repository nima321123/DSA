
/*You are given a positive integer n.

Let even denote the number of even indices in the binary representation of n (0-indexed) with value 1.

Let odd denote the number of odd indices in the binary representation of n (0-indexed) with value 1.

Return an integer array answer where answer = [even, odd]*/


#include <stdio.h>
#include <stdlib.h>

int* evenOddBit(int n) {
    //dynamically create an array to store the result
    int* result = (int*)malloc(2*sizeof(int));
    //create an array to store the binary digits, default values are -1;
    int binary[10];
    for (int i = 0; i < 10; i++){
        binary[i] = -1;
    }
    
    //convert n to binary
    
    int i = 0;
    while (n > 0){
        binary[i] = n % 2;
        n = n/2;
        i++;
    }
    
    //count the number of bits
    int bits = 0;
    for (int i = 0; i < 10; i++){
        if (binary[i] == 0 || binary[i] == 1){
            bits ++;
        }
    }
    //reverse binary array
    int temp;
    int start = 0;
    int end = bits - 1;
    while (start < end){
        temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }
    
    //count even and odd bits
    int even = 0, odd = 0;
    for (int i = 0; i < bits; i ++){
        if (i % 2 == 0 && binary[i] == 1){
            even ++;
        }
        if (i % 2 == 1 && binary[i] == 1){
            odd++;
        }
    }
    //debug print
    printf("[");
    for (int i = 0; i < bits; i++){
        if (i == bits - 1) printf("%d", binary[i]);
        else
        printf("%d; ", *(binary+i));
    }
    
    printf("]\n");
    
    result[0] = even;
    result[1] = odd;
    
    return result;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int* result = evenOddBit(n);
    printf("[%d, %d]", *(result), *(result+1));
    free(result);
    return 0;
}
