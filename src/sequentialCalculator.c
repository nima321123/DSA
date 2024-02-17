/*Given an array of string s which represents an expression, evaluate this expression 
(left to right regardless of the order of evaluation) and return its value. 
Example 1:

> Input: `s = ["3", "+", "2", "*", "2"]`

> Output: `10`

Example 2:

> Input: `s = ["3", "/", "2"]`

> Output: `1`
*/

#include <stdio.h>
#include <stdlib.h>

int evaluate(char** s, int sSize){
    int result = atoi(s[0]);
    for (int i = 1; i < sSize; i++){
        if (s[i][0] == '+'){
            result += atoi(s[i+1]);
        }
        if (s[i][0] == '-'){
            result -= atoi(s[i+1]);
        }
        if (s[i][0] == '*'){
            result *= atoi(s[i+1]);
        }
        if (s[i][0] == '/'){
            result /= atoi(s[i+1]);
        }
    }
    return result;
}
int main(){
    char* s[] = {"3", "/", "2"};
    int sSize = 3;
    printf("%d", evaluate(s, sSize));
    return 0;
}