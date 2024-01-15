
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    //let user enter string 
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    //sequential calculator
    int result = str[0] - '0';
    int i = 1;
    char opr;
    while (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
        opr = str[i];
        switch(opr){
            case '+':
                result += str[i+1] - '0';
                break;
            case '-':
                result -= str[i+1] - '0';
                break;
            case '*':
                result *= str[i+1] - '0';
                break;
            case '/':
                result /= str[i+1] - '0';
                break;
            default: 
                printf("Invalid string!\n");
                exit(0);
                break;
            
        }
        i += 2;
        
    }
    //print the result
    printf("Result: %d", result);
    return 0;
}
