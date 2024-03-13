// reverse a string using recursion.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse_string(char* str, int i, int end){
    //base case
    if (i >= end) return;
    // reverse elements
    char temp = *(str + i);
    *(str + i) = *(str + end);
    *(str + end) = temp;
    reverse_string(str, i+1, end-1);
}

int main(){
    
    char my_string [100];
    printf("Enter a string: ");
    scanf("%s", my_string);
    int end = strlen(my_string) - 1;
    
    reverse_string(my_string, 0, end);
    printf("\n%s", my_string);
}
