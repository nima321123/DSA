#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    char data;
    struct stack* next;
} Stack;

void push(Stack** top, char data) {
    Stack* new_node = (Stack*) malloc(sizeof(Stack));
    if (!new_node) return;
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

char pop(Stack** top) {
    char c;
    Stack* temp;
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return '\0';
    }
    else {
        temp = *top;
        c = temp->data;
        *top = temp->next;
        free(temp);
        return c;
    }
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return 1;
    else if (character1 == '{' && character2 == '}') return 1;
    else if (character1 == '[' && character2 == ']') return 1;
    else return 0;
}

int areParenthesesBalanced(char exp[]) {
    int i = 0;
    Stack* stack = NULL;
    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (stack == NULL) return 0;
            else if (!isMatchingPair(pop(&stack), exp[i])) return 0;
        }
        i++;
    }
    if (stack == NULL) return 1;
    else return 0;
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (areParenthesesBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
