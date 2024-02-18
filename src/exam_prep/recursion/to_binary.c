// convert a decimal number to binary using recursion0
#include <stdlib.h>
#include <stdio.h>

void to_bi(int num, int i, int* result){
    if (num == 0) return;
    *(result + i) = num % 2;
    to_bi(num/2, i+1, result);
} 
void reverse_arr(int* arr, int start, int end){
   int temp;
   while (start < end) {
       temp = arr[start];
       arr[start] = arr[end];
       arr[end] = temp;
       start ++;
       end--;
   }
    
}
int main(){
    
    int n;
    
    int ptr [16] = {0}; // assign pointer to store result array
    printf("Enter a number: ");
    scanf("%d", &n);
    
   to_bi(n, 0, ptr);
    // print the binary result
    
    
    
    reverse_arr(ptr,0, 15);
    for (int i = 0; i < 16; i++){
        printf("%d", *(ptr + i));
    }
}   