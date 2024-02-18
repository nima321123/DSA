
#include <stdlib.h>
#include <stdio.h>
/// Implement stack using linked list

struct Node
{
    int data;
    struct Node * next;
};

struct Stack 
{
    struct Node * top; // also be the head of the linked list
};

void push(struct Stack* stack, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (stack != NULL){
        temp->next = stack->top;
        stack->top = temp;
    }
    else{
        stack->top = temp;
    }
}

void pop(struct Stack* stack)
{
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free (temp);
}

// return 1 if the stack is empty otherwise 0
int is_empty(struct Stack* stack)
{
    if (stack->top == NULL) return 1;
    else return 0;
}

void print_stack(struct Stack* stack)
{
    struct Node* temp = stack->top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    char response;
    printf("Do you want to push? (y/n): ");
    getchar();
    scanf("%c", &response);
    while (response != 'n')
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        getchar();
        push(stack, data);
        printf("Do you want to push? (y/n): ");
        
        scanf("%c", &response);
        getchar();
    }

    print_stack(stack);

    printf("\nDo you want to pop? (y/n): ");
    scanf("%c", &response);
    getchar();

    while ((is_empty(stack) != 1) && response != 'n')
        {
            pop(stack);
            printf("\nDo you want to pop? (y/n): ");
            scanf("%c", &response);
            getchar();
        }
    
    while (response != 'n')
    {
        pop(stack);
        printf("\nDo you want to pop? (y/n): ");
        scanf("%c", &response);
        getchar();
    }
    
    print_stack(stack);


    return 0;
}