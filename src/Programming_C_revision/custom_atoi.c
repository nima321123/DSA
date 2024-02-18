#include <stdio.h>
#include <stdlib.h>


int custom_atoi(char *str) {
    int arr[256];
    int len = 0;

    // Scan each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // If the character is a digit, save it in the array
        if (str[i]>='0' && str[i]<='9'){
            arr[len]=str[i]-'0';
            len++;
        } else {
            break;
        }
    }

    // Calculate the sum of each digit in the array multiplied by its index
    if (len==0){return 0;}
    int result = 0;
    int mul = 1;
    for (int i = len-1; i >=0; i--) {
        result += arr[i] * mul;
        mul = mul*10;
    }

    return result;
}

int main(){
    char* phone_num = "0774599015";
    printf("%d",custom_atoi(phone_num));
    
}